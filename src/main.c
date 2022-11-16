#include "chaos_sim.h"

int	keypress(int k, t_render *r)
{
	if (k == 65307 || k == 53)
		exit(1);
	return (0);
}

int	render_next_frame(t_render *r)
{
	mlx_put_image_to_window(r->mlx, r->mlx_win, r->img, 0, 0);
	return (1);
}

int	main(int argc, const char **argv)
{
	t_render	*r;

	r = malloc(sizeof(t_render));
    r->dot_num = 1000;

	r->dots = spawn_dots(r);

	r->w = 1000;
	r->h = 1000;
	r->mlx = mlx_init();
	r->mlx_win = mlx_new_window(r->mlx, r->w, r->h, "ant_sim");
	r->img = mlx_new_image(r->mlx, r->w, r->h);
	r->addr = mlx_get_data_addr(r->img, &r->bits_per_pixel, &r->line_length, &r->endian);

	init_threads(r);

	mlx_key_hook(r->mlx_win, keypress, r);
	mlx_loop_hook(r->mlx, render_next_frame, r);
	mlx_loop(r->mlx);
}
