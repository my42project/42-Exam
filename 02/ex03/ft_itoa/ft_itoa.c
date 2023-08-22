#include <stdlib.h>

char *ft_itoa(int n) {
	char *r;
	int tmp = n;
	int bas = 1;

	while (tmp && bas++)
		tmp /= 10;
	if (!(r = malloc(sizeof(char) * ((n < 0) + !n + bas + 1))))
		return (0);
	r = r + (n < 0) + !n + bas - 1;
	*r = '\0';
	if (!n)
		*(--r) = '0';
	bas = (n >= 0) * 2 - 1;
	while (n) {
		*(--r) = (n % ( 10 * bas) * bas ) + '0';
		n /= 10;
	}
	if (bas < 0)
		*(--r) = '-';
	return r;
}
