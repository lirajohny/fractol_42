#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 640, 640, "Hello world!");
	//mlx_pixel_put(mlx, mlx_win, 320, 320, 0x35A239);
	mlx_loop(mlx);
}
