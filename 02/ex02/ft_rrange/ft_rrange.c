#include <stdlib.h>

int ft_abs(int x) {
	if ( x < 0 )
		return -x;
	return x;
}

int		*ft_range(int start, int end){
	int *res;
	int	i = 0;

	res = malloc(sizeof(int) * (ft_abs(end - start) + 1));
	while (start < end)
		res[i++] = end++;
	while (start > end)
		res[i++] = end--;
	res[i] = end;
	return res;
}
