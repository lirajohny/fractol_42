#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	
	write(1, "test\n", 5);
	mlx = mlx_init();
	write(1, "test\n", 5);
	mlx_win = mlx_new_window(mlx, 640, 640, "Hello world!");
	write(1, "test\n", 5);
	mlx_pixel_put(mlx, mlx_win, 320, 320, 0x35A239);
	write(1, "test\n", 5);
	mlx_loop(mlx);
	write(1, "test\n", 5);
}
