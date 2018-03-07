#include "fdf.h"

void 			draw_line(_2D pos0, _2D pos1, s_data *data, int e2) 
{
  int dx = abs(pos1.x-pos0.x);
  int sx = pos0.x<pos1.x ? 1 : -1;
  int dy = abs(pos1.y-pos0.y); 
  int sy = pos0.y<pos1.y ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2;

  if (pos1.x < 0 || pos1.x >= W_WIDTH || pos1.y < 0 || pos1.y >= W_HEIGHT
  	|| pos0.x < 0 || pos0.x >= W_WIDTH || pos0.y < 0 || pos0.y >= W_HEIGHT)
  	return;
  while (1)
  {
  	data->image.img_adr[W_WIDTH * pos0.y + pos0.x] = data->norme_color;
    if (pos0.x==pos1.x && pos0.y==pos1.y) 
      break;
    e2 = err;
    if (e2 >-dx) 
    	{
    	 err -= dy;
    	 pos0.x += sx; 
    	};
    if (e2 < dy) 
    	{
    		err += dx; 
    		pos0.y += sy; 
    	};
  }
}

static void 	plot_z(s_data *data, int l_count, int L_count)
{	
	int 		i;
	Vertex_t 	*mesh;

	mesh = data->mesh;
	while (L_count < (int)mesh[0].lungime_x)
	{
		i = 0;
		while (i < (int)mesh[0].latime_z - 1)
		{
			if (mesh[l_count].clip == 1 && i < (int)mesh[0].latime_z - 1)
			{
				i++;
				l_count++;
				continue;
			}
			data->norme_color = get_color(mesh[l_count].Local.y, mesh[l_count + (int)mesh[0].lungime_x].Local.y, mesh[0].max_y/2, data);
			draw_line(mesh[l_count].Screen, mesh[l_count + (int)mesh[0].lungime_x].Screen, data, 0);
			i++;
			l_count++;
		}
		L_count++;
	}
}


void			plot(s_data *data, int l_count, int L_count)
{	
	int 		i;
	Vertex_t 	*mesh;

	mesh = data->mesh;
	while (l_count < (int)mesh[0].latime_z)
	{
		i = 0;
		while (i < (int)mesh[0].lungime_x - 1)
		{
			if (mesh[L_count].clip == 1 && i < (int)mesh[0].lungime_x - 1 && mesh[L_count + 1].clip == 1)
			{
				i++;
				L_count++;
				continue;
			}
			data->norme_color = get_color(mesh[L_count].Local.y, mesh[L_count + 1].Local.y, mesh[0].max_y/2, data);
			draw_line(mesh[L_count].Screen, mesh[L_count + 1].Screen, data, 0);
			i++;
			L_count++;
		}
		l_count++;
		L_count++;
	}
	plot_z(data, 0, 0);
}