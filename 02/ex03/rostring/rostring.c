#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str) {
	int i = 0;
	int j = 0;
	int k;
	char **tab;

	tab = malloc(sizeof(char *) * 1000);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i]) {
		if (str[i] > 32) {
			k = 0;
			tab[j] = malloc(sizeof(char) * 1000);
			while (str[i] > 32)
				tab[j][k++] = str[i++];
			tab[j][k] = '\0';
			j++;
		} else
				i++;
	}
	tab[j] = 0;
	return tab;
}

void ft_putstr(char *s) {
	while (*s)
		write(1, &*s++, 1);
}

void rostring(char *s) {
	int i = 1;
	char **rs = ft_split(s);
	while (rs[i]) {
		ft_putstr(rs[i++]);
		ft_putstr(" ");
	}
	ft_putstr(rs[0]);

}

int main(int ac, char **av) {
	if (ac > 1)
		rostring(av[1]);
	write(1, "\n", 1);
}
