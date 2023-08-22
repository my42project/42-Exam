#include <unistd.h>

void epur_str(char *s){
	int i = 0;
	while (s[i] == 32 || s[i] == '\t')
		i++;
	while (s[i]) {
		if (s[i] == 32 || s[i] == '\t' && s[i + 1] > 32 && s[i + 1])
			write(1, " ", 1);
		else if (s[i] != 32 && s[i] != '\t')
			write(1, &s[i], 1);
		i++;
	}
}

int main(int ac, char **av) {
	if (ac == 2)
		epur_str(av[1]);
	write(1, "\n", 1);
}
