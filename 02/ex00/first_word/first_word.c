#include <unistd.h>

void	fw(char *s) {
	while (*s == 32 || *s == '\t')
		s++;
	while (*s) {
		if (*s != 32 && *s != '\t')
			write(1, &*s, 1);
		else
			break;
		s++;
	}
}

int main(int ac, char **av) {
	if (ac == 2)
		fw(av[1]);
	write(1, "\n", 1);
}