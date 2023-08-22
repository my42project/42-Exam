#include <unistd.h>

void last_word(char *s) {
	char *lw;

	while (*s) {
		if (*s <= 32 && *(s + 1) > 32)
			lw = &*(s + 1);
		s++;
	}
	while (*lw && *lw > 32)
		write(1, &*lw++, 1);
}

int main(int ac, char **av) {
	if (ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
}
