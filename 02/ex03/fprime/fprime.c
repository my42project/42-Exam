#include <stdio.h>
#include <stdlib.h>

void fprime(int n) {
	int i;

	i = 1;
	if (n == i)
		printf("1");
	while (++i <= n)
		if (!(n % i)) {
			printf("%d", i);
			if (n == i)
				break;
			printf("*");
			n /= i;
			i = 1;
		}
}

int	main(int ac, char **av) {
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
}