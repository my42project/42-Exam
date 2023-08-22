#include <unistd.h>
#warning expand_str

void	expand_str(char *s) {
	int flg;

	flg = 0;
	while (*s == 32 || *s == '\t')
		s++;
	while (*s) {
		if (*s == 32 || *s == '\t')
			flg = 1;
		else {
			if (flg)
				write(1, "   ", 3);
			flg = 0;
			write(1, &*s, 1);
		}
		s++;
	}
}

int	main(int ac, char **av) {
	if (ac == 2)
		expand_str(av[1]);
	write(1, "\n", 1);
}