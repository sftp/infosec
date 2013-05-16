int gcd (int a, int b)
{
	while (a != 0 && b != 0) {
		if (a >= b)
			a = a % b;
		else
			b = b % a;
	}

	return a + b;
}

int gcd_stein (int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a == b)
		return a;
	if (a == 1 || b == 1)
		return 1;

	/* if bith a and b is even */
	if (!(a & (int)1) && !(b & (int)1))
		return 2 * gcd_stein(a/2, b/2);
	/* if a is even */
	if (!(a & (int)1))
		return gcd_stein(a/2, b);
	/* if b is even */
	if (!(b & (int)1))
		return gcd_stein(a, b/2);

	if (a > b)
		return gcd_stein((a-b)/2, b);

	return gcd_stein(a, (b-a)/2);
}

int gcd_ext (int a, int b, int *x, int *y)
{
	if (b == 0) {
		*x = 1;
		*y = 0;

		return a;
	}

	int q, r, x1, x2, y1, y2;

	x2 = 1; x1 = 0;
	y2 = 0; y1 = 1;

	while (b > 0) {
		q = a / b;

		r = a - q * b;

		*x = x2 - q * x1;
		*y = y2 - q * y1;

		a = b;
		b = r;

		x2 = x1; x1 = *x;
		y2 = y1; y1 = *y;
	}

	*x = x2;
	*y = y2;

	return a;
}
