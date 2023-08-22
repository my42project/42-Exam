int is_power_of_2(unsigned int n) {
	int	i;

	i = 1;
	if ((int)n <= 0)
		return (0);
	while (i <= n) {
		if (i == n)
			return (i);
		i *= 2;
	}
	return (0);
}
