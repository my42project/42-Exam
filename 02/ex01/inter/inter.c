#include <unistd.h>

int	iter(char *s1, char c, int i) {
	int	j;

	j = -1;
	while (s1[++j] && (j < i || i == -1))
		if (s1[j] == c)
			return (1);
	return (0);
}

void	inter(char *s1, char *s2) {
	int i;

	i = -1;
	while (s1[++i])
		if (!iter(s1, s1[i], i) && iter(s2, s1[i], -1))
			write(1, &s1[i], 1);
}

int main(int ac, char **av) {
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
}

