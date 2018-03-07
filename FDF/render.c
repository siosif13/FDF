#include "fdf.h"

static void 	clip_it3D(s_data *data)
{
	int i;
	i = 0;
	
	while (i < data->count)
	{
		if (data->mesh[i].Global.z < 2)
			data->mesh[i].clip = 1;
		else
			data->mesh[i].clip = 0;
		i++;
	}
}

static	void	fuck_the_normes(s_data *data, double zoom_z, int type)
{
	int i;

	i = 0;
	while (i <= data->count)
	{
		VEC_MultMatrix(&data->mesh[i].Local, data->mesh_tr, &data->mesh[i].Global);
		i++;
	}
	i = 0;
	while (i <= data->count)
	{
		VEC_MultMatrix(&data->mesh[i].Global, data->camera_tr, &data->mesh[i].Aligned);
		i++;
	}
	i = 0;
	while (i <= data->count)
	{
		Project(&data->mesh[i], type, zoom_z);
		i++;
	}
}

static double 	fuck_the_normes_2(int keycode, double zoom_z, s_data *data)
{
	double tmp;

	tmp = zoom_z;
	if (data->projection == 1)
	{
		if (keycode == 65451 && tmp)
			tmp += 0.5;
		if (keycode == 65453 && tmp && tmp > 1)
			tmp -= 0.5;
	}
	else if (data->projection == 0)
	{
		if (keycode == 65451 && tmp > 9)
			tmp -= 0.5;
		if (keycode == 65453 && tmp)
			tmp += 0.5;
	}
	return (tmp);
}

void			render(s_data *data, double zoom_z)
{
	static int 	k;

	if (k == 0)
	{
		MAT_Identity(data->mesh_tr);
		MAT_Identity(data->camera_tr);
		TR_Translate(data->mesh_tr, 0, 0, 25);
		k = 1;
	}
	else
	{
		mlx_destroy_image(data->q.mlx, data->image.img_ptr);
		image_init(data);
	}
	fuck_the_normes(data, zoom_z, data->projection);
	if (data->projection == 0)
		clip_it3D(data);
	plot(data, 0, 0);
	mlx_put_image_to_window(data->q.mlx, data->q.win, data->image.img_ptr, 0, 0);
	mlx_string_put  (data->q.mlx, data->q.win, 50, 50, 0x0FFFFFF, "Usage: Rotate with arrow keys // Zoom with + and -");
}

int 		key_rotate(int keycode, s_data *data)  
{
	static double rot_y;
	static double rot_x;
	static double zoom_z = 25;

	if (keycode == 65307)
		exit(0);
	zoom_z = fuck_the_normes_2(keycode, zoom_z, data);
	if (keycode == 65362)
		rot_x = rot_x + 0.07;
	if (keycode == 65364)
		rot_x = rot_x - 0.07;
	if (keycode == 65363)
		rot_y = rot_y + 0.07;
	if (keycode == 65361)
		rot_y = rot_y - 0.07;
	MAT_Identity(data->mesh_tr);
	TR_Rotate(data->mesh_tr, rot_x, rot_y, 0);
	MAT_Identity(data->camera_tr);
	TR_Translate(data->mesh_tr, 0, 0, zoom_z);
	render(data, zoom_z); 
	return (1);
}
