#include <unistd.h>

void str_capitalizer(char *s) {
	int i = -1;
	while (s[++i]) {
		if (s[0] >= 'a' && s[0] <= 'z')
			s[i] -= 32;
		if (s[i] >= 'a' && s[i] <= 'z' && (s[i - 1] == 32 || s[i - 1] == '\t'))
			s[i] -= 32;
		else if (s[i] >= 'A' && s[i] <= 'Z' && (s[i - 1] != 32 && s[i - 1] != '\t' && i != 0))
			s[i] += 32;
		write(1, &s[i], 1);
	}
	write(1, "\n", 1);
}

int main(int ac, char **av) {
	int	i = 0;
	if (ac != 1)
		while (++i < ac)
			str_capitalizer(av[i]);
	else
		write(1, "\n", 1);
}