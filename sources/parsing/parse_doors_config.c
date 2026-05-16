#include "parsing.h"
 
int	parse_door_line(char *line, t_config *config)
{
	int	i;
	int	id;
 
	if (!line || !config)
		return (0);
	if (config->door_count >= MAX_DOORS)
	{
		printf("Error: Too many door destinations (max %d)\n", MAX_DOORS);
		return (0);
	}
	id = line[1] - '0';
	i = 2;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0')
	{
		printf("Error: Missing map path for door D%d\n", id);
		return (0);
	}
	config->doors[config->door_count].id = id;
	config->doors[config->door_count].map_path = ft_strdup(line + i);
	if (!config->doors[config->door_count].map_path)
	{
		printf("Error: Failed to allocate door path\n");
		return (0);
	}
	config->door_count++;
	return (1);
}