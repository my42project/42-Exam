#include <unistd.h>

void	print_bits(unsigned int octet) {
	int 			i;
	unsigned int	bits;

	i = 9;
	while (--i) {
		bits = (octet >> i & 1) + '0';
		write(1, &bits, 1);
	}
}
