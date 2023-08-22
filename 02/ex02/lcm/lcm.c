unsigned int    lcm(unsigned int a, unsigned int b) {
	unsigned int	res;

	if (!a || !b)
		return 0;
	if (a > b)
		res = a;
	else
		res = b;
	while (1) {
		if (!(res % a) && !(res % b))
			return res;
		res++;
	}
	return res;
}