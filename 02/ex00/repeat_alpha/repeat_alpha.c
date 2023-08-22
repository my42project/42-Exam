#include <unistd.h>
#include <stdio.h>
void ra(char *s) {
	int count;

	count = 0;
	while (*s) {
		if (*s >= 'A' && *s <= 'Z')
			count = *s - 'A' + 1;
		else if (*s >= 'a' && *s <= 'z')
			count = *s - 96;
		else
			write(1, &*s, 1);
		while (count) {
			write(1, &*s, 1);
			count--;
		}
		s++;
	}

}

int main(int ac, char **av) {
	if (ac == 2)
		ra(av[1]);
	write(1, "\n", 1);
}