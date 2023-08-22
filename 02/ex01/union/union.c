#include <unistd.h>

int check(char *s, char c, int i) {
	int j;

	j = -1;
	while (++j < i)
		if (s[j] == c)
			return (1);
	return (0);
}

void ft_union(char *s1, char *s2) {
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		s1[i++] = s2[j++];
	k = -1;
	while (++k <= i -1)
		if (!check(s1, s1[k], k))
			write(1, &s1[k], 1);
}

int main(int ac, char **av) {
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
}
