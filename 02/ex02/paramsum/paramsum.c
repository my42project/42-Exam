#include <unistd.h>

void paramsum(int n) {
	if (n > 9)
		paramsum(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int main(int ac, char **av) {
	if (ac > 1)
		paramsum(ac - 1);
	write(1, "\n", 1);
}