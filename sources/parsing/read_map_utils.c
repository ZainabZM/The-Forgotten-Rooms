#include "parsing.h"

void	init_map(t_map *map, int *map_started)
{
	*map_started = 0;
	map->data = NULL;
	map->height = 0;
	map->width = 0;
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	error_empty_line(char *line)
{
	if (is_empty_line(line))
	{
		printf("Error: empty line inside the map\n");
		free(line);
		exit(1);
	}
}
