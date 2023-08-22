#include <unistd.h>

int ft_atoi(char *s) {
	int res = 0;
	while (*s)
		res = res * 10 + *s++ - '0';
	return res;
}

void	ft_putchar(char c) {
	write(1, &c, 1);
}

void print_hex(int n) {
	if (n >= 16) {
		print_hex(n / 16);
		print_hex(n % 16);
	}
	else if (n >= 10 && n < 16)
		ft_putchar(n + 87);
	else if (n < 10)
		ft_putchar(n + 48);
}

int main(int ac, char **av) {
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
}
