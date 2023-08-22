int	max(int *tab, unsigned int len) {
	int	result;
	int i;

	i = -1;
	result = tab[0];
	while (++i < len)
		if (result < tab[i])
			result = tab[i];
	return (result);
}