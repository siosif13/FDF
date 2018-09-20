#include "fdf.h"

static void		validate_error(void)
{
	ft_putendl("Invalid file");
	exit(0);
}
	
void 			validate_file(char *str)
{
	while (*str)
	{
		if ((*str >= '0' && *str <='9') || (*str >= 65 && *str <= 70) || 
			(*str >= 96 && *str <= 102) || (*str == 'x') || (*str == 'X') || (*str != '-')
			|| (*str != '+'))
			str++;
		else if (*str == ',')
			{
				*str = '\0';
				break;
			}
		else
			validate_error();
	}
}

void			error_handling(int *a)
{
	if (*a == 11)
	{
		ft_putendl("blaze it");
		return;
	}
	ft_putendl("The number needs to be within the given list, try again.");
	scanf("%d", a);
}





/*

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
    	}
    if (e2 < dy) 
    	{
    		err += dx; 
    		pos0.y += sy; 
    	}
  }
}


*/