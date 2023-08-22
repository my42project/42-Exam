#include <stdio.h>
#include <stdlib.h>

void	pgcd(int n1, int n2) {
	int i = 0;
	int gcd = 0;
	while (++i < n1 && i < n2)
		if (!(n1 % i) && (n2 % i))
			gcd = i;
	printf("%d", gcd);
}

int main(int ac, char **av) {
	if (ac == 3)
		pgcd(atoi(av[1]), atoi(av[2]));
	printf("\n");
}
