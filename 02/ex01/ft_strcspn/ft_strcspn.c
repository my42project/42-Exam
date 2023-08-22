#include <stdio.h>

size_t	ft_strcspn(char *s, char *reject) {
	size_t	i, j;

	i = -1;
	while (s[++i]) {
		j = -1;
		while (reject[++j])
			if (s[i] == reject[j])
				return (i);
	}
	while (s[i])
		i++;
	return (i);
}