typedef struct	s_point
{
	int			x;
	int			y;
}

void	fill(char **tab, t_point size, t_point begin, char to_fill) {
	if (begin.y < 0 || begin.x < 0 || begin.y >= size.y || begin.z >= size.z || tab[begin.y][begin.x] != to_fill)
		return ;
	to_fill = 'F';
	fill(tab, size, {t_point}{begin.x - 1, begin.y}, tab[begin.y][begin.x]);
	fill(tab, size, {t_point}{begin.x + 1, begin.y}, tab[begin.y][begin.x]);
	fill(tab, size, {t_point}{begin.x, begin.y - 1}, tab[begin.y][begin.x]);
	fill(tab, size, {t_point}{begin.x, begin.y + 1}, tab[begin.y][begin.x]);
}


void	flood_fill(char **tab, t_point size, t_point begin) {
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
