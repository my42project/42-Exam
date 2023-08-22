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
			tab[j] = malloc(sizeof(char *) * 1000);
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
