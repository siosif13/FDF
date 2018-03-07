#include "fdf.h"

void		choose_projection(s_data *data)
{
	int a;

	ft_putendl("Now please choose the projection type:");
	ft_putendl("1.Perspective projection");
	ft_putendl("2.Ortographic projection");
	scanf("%d", &a);
	if (a < 1 || a > 2)
	{
		ft_putendl("The number must be within the list, try again.");
		scanf("%d", &a);
	}
	data->projection = a - 1;
}

void 		image_init(s_data *data)
{
	int bits;
	int bytes;
	int endian;

	bits = 32;
	bytes = W_WIDTH * 4;
	endian = 0;
	data->image.img_ptr = mlx_new_image(data->q.mlx, W_WIDTH, W_HEIGHT);
	data->image.img_adr = (int *)mlx_get_data_addr(data->image.img_ptr, &bits, &bytes, &endian);
}

Vertex_t	*mesh_create(node *head, int *count)     
{
	node			*current;
	Vertex_t		*mesh;
	int 			i;
	static int 		max_y;
		
	current = head;
	while (current->next != NULL)
		current = current->next;
	mesh = (Vertex_t*)malloc(sizeof(Vertex_t) * current->count);
	i = 0;
	current = head;
	while (current != NULL)
	{
		mesh[i].Local.x = current->pos[0];
		mesh[i].Local.y = current->pos[1];
		mesh[i].Local.z = current->pos[2];
		mesh[i].latime_z = head->latime_z;
		mesh[i].lungime_x = head->lungime_x;
		current = current->next;
		if (mesh[i].Local.y > max_y)
			{
				max_y = mesh[i].Local.y;
				mesh[0].max_y = max_y;
			}
		i++;
	}
	*count = i - 1;
	return (mesh);
}
