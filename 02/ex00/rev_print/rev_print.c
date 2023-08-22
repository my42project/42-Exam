#include <unistd.h>

void rp(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (0 < i)
		write(1, &s[--i], 1);
}

int main(int ac, char **av) {
	if (ac == 2)
		rp(av[1]);
	write(1, "\n", 1);
}