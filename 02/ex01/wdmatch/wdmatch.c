#include <unistd.h>

void wdmatch(char *s1, char *s2) {
	int i;
	int j;

	i = 0;
	j = 0;
	while (s2[j])
		if (s2[j++] == s1[i++])
			;
	while (!s1[i])
		while (*s1)
			write(1, &*s1++, 1);
}

int main(int ac, char **av) {
	if (ac == 3)
		wdmatch(av[1], av[2]);
	write(1, "\n", 1);
}