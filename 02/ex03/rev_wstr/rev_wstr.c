#include <unistd.h>
#include <stdlib.h>

char **ft_split(char *str) {
	int i = 0;
	int j = 0;
	int k;
	char **tab;

	tab = malloc(sizeof(char *) * 1000);
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i]) {
		if (str[i] > 32) {
			k = 0;
			tab[j] = malloc(sizeof(char) * 1000);
			while (str[i] > 32)
				tab[j][k++] = str[i++];
			tab[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return tab;
}

void ft_putstr(char *s) {
	while (*s)
		write(1, &*s++, 1);
}

void	rev_wstr(char *s) {
	char **rew = ft_split(s);
	int i = 1;
	while (rew[i])
		i++;
	while (--i >= 0) {
		ft_putstr(rew[i]);
		if (i > 0)
			ft_putstr(" ");
	}
}

int main(int ac, char **av) {
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
}