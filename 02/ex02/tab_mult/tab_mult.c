#include <unistd.h>
#include <stdio.h>
int ft_atoi(char *s) {
	int res = 0;
	int sign = 1;
	if (*s == '-') {
		s++;
		sign = -1;
	}
	while (*s)
		res = res * 10 + *s++ - '0';
	return res * sign;
}

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_putstr(char *s) {
	while (*s)
		write(1, &*s++, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void tab_mult(int n) {
	int i = 0;
	while (++i <= 9) {
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i * n);
		write(1, "\n", 1);
	}
}

int main(int ac, char **av) {
	if (ac == 2)
		tab_mult(ft_atoi(av[1]));
}
