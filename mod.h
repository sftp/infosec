int mod(long int a, int n)
{
	int ret;
	ret = a % n;
	if(ret < 0)
		ret +=n;

	return ret;
}
