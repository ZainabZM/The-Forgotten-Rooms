#include "raycasting.h"

void	move_forward(t_player *p, char **map)
{
	double	nx;
	double	ny;

	nx = p->x + p->dir_x * MOVE_SPEED;
	ny = p->y + p->dir_y * MOVE_SPEED;
	if (map[(int)ny][(int)nx] != '1' && map[(int)ny][(int)nx] != '2')
	{
		p->x = nx;
		p->y = ny;
	}
}

void	move_backward(t_player *p, char **map)
{
	double	nx;
	double	ny;

	nx = p->x - p->dir_x * MOVE_SPEED;
	ny = p->y - p->dir_y * MOVE_SPEED;
	if (map[(int)ny][(int)nx] != '1' && map[(int)ny][(int)nx] != '2')
	{
		p->x = nx;
		p->y = ny;
	}
}

void	strafe_left(t_player *p, char **map)
{
	double	nx;
	double	ny;

	nx = p->x - p->plane_x * MOVE_SPEED;
	ny = p->y - p->plane_y * MOVE_SPEED;
	if (map[(int)ny][(int)nx] != '1' && map[(int)ny][(int)nx] != '2')
	{
		p->x = nx;
		p->y = ny;
	}
}

void	strafe_right(t_player *p, char **map)
{
	double	nx;
	double	ny;

	nx = p->x + p->plane_x * MOVE_SPEED;
	ny = p->y + p->plane_y * MOVE_SPEED;
	if (map[(int)ny][(int)nx] != '1' && map[(int)ny][(int)nx] != '2')
	{
		p->x = nx;
		p->y = ny;
	}
}
