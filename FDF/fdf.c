#include "fdf.h"

static void		init_data(s_data *data, node *head, int *i, char *argv)
{
	int x;

	data->q.mlx = mlx_init();
	data->q.win = mlx_new_window(data->q.mlx, W_WIDTH, W_HEIGHT, "42 - FDF // User: siosif");
	head = read_n_write(argv);
	data->mesh = mesh_create(head, i);
	lst_remove(&head);
	data->count = *i;
	image_init(data);
	MAT_Identity(data->mesh_tr);
	TR_Translate(data->mesh_tr, -data->mesh[0].lungime_x/2, -data->mesh[0].max_y/2, -data->mesh[0].latime_z/2);
	TR_Rotate(data->mesh_tr, M_PI, 0, 0);
	x = 0;
	while (x <= data->count)
	{
		VEC_MultMatrix(&data->mesh[x].Local, data->mesh_tr, &data->mesh[x].Local);   /// <<-- First centering	
		x++;
	}

}

int				main(int argc, char **argv)
{
	s_data		data;
	int 		i;
	node 		*head;

	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf (map_name)\nExample: ./fdf mars.fdf");
		exit (0);
	}
	head = NULL;
	enter_colors(&data);
	choose_projection(&data);
	init_data(&data, head, &i, argv[1]);
	render(&data, 25);
 	mlx_hook(data.q.win, 2, 1, key_rotate, &data);
	mlx_loop(data.q.mlx);
	return (0);
}