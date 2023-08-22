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
	printf("number: %d\n", res * sign);
	return res * sign;
}

int prime(int n) {
	int i = 1;
	while (i < n)
		if (n % i == 0)
			return 0;
	return 1;
}

void ft_putnbr(int n) {
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void add_prime_sum(int n) {
	int prime_sum = 0;
	int i = 1;

	if (n <= 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (++i <= n)
		if (prime(i))
			prime_sum += i;
	ft_putnbr(prime_sum);
}

int main(int ac, char **av) {
	if (ac == 2)
		add_prime_sum(ft_atoi(av[1]));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}