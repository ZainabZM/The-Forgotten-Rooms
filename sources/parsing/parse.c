#include "parsing.h"

void	parse_map(t_map *map, char *filename)
{
	int	fd;

	fd = open_cub_file(filename);
	if (fd < 0)
		exit(1);
	read_config_lines(fd, &map->config);
	map->data = NULL;
	map->height = 0;
	map->width = 0;
	read_map_lines(fd, map);
	close(fd);
}
