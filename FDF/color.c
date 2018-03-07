#include "fdf.h"

static	void	print_list()
{
	ft_putendl("Choose the colors you want the wireframe to be represented in from the follwing list by typing the coresponding number");
	ft_putendl("1.Yellow");
	ft_putendl("2.Orange");
	ft_putendl("3.Pink");
	ft_putendl("4.Blue");
	ft_putendl("5.Bright Green");
	ft_putendl("6.Red");
	ft_putendl("7.Purple");
	ft_putendl("8.Another purple");
	ft_putendl("9.A nicer shade of blue :D");
	ft_putendl("10.Ice Blue");
	ft_putendl("11.Ganja Green ;)");
	ft_putendl("12.Lime Green");
	ft_putendl("13.White");
	ft_putendl("14.Mint Green");
}

static int		choose_colors(int *a)
{
	int 	arr[14];
	
	arr[0] = 0x0FEDD00;  //yellow
	arr[1] = 0x0FE5000;   //orange
	arr[2] = 0x0E10098; //pink
	arr[3] = 0x00084CA;  //blue
	arr[4] = 0x000B08B; // bright green
	arr[5] = 0x0DA291C;  // red
	arr[6] = 0x07D2248;  // purple
	arr[7] = 0x08031A7;  // Another purple 
	arr[8] = 0x0236192;   // A nicer shade of blue :D
	arr[9] = 0x040C1AC;   // Ice blue 
	arr[10] = 0x000B140;   // Leaf Green 
	arr[11] = 0x097D700;  // Lime green 
	arr[12] = 0x0D9D9D6; 	// White 
	arr[13] = 0x02CD5C4; 	// Mint Green
	return (arr[*a - 1]);
}
static int		*init_color(int c1, int c2, int c3, int c4)
{
	int *arr;

	arr = (int *)malloc(sizeof(int) * 4);
	arr[0] = choose_colors(&c1);
	arr[1] = choose_colors(&c2);
	arr[2] = choose_colors(&c3);
	arr[3] = choose_colors(&c4);
	return (arr);
}

int 			get_color(double y0, double y1, double max_y, s_data *data)           
{
	int 	i;
	int 	color_arr[4];
	int 	color;
	double	tmp;

	i = 0;
	while (i < 4)
	{
		color_arr[i] = data->color[i];
		i++;
	}

	tmp = y0;
	if (y1 < y0)
		tmp = y1;

	if (tmp < -max_y/2)
		color = color_arr[3];
	if (tmp >= -max_y/2 && tmp < 0)
		color = color_arr[2];
	if (tmp >= 0 && tmp < max_y/2)
		color = color_arr[1];
	if (tmp >= max_y/2)
		color = color_arr[0];
	return (color);
}

void			enter_colors(s_data	*data)
{
	int a;
	int b;
	int c;
	int d;

	print_list();
	ft_putendl("Please specify the frist color");
	scanf("%d", &a);
	if (a > 14 || a == 11)
		error_handling(&a);
	ft_putendl("Please specify the second color");
	scanf("%d", &b);
	if (b > 14 || b == 11)
		error_handling(&b);
	ft_putendl("Please specify the third color");
	scanf("%d", &c);
	if (c > 14 || c == 11)
		error_handling(&c);
	ft_putendl("Please specify the fourth color");
	scanf("%d", &d);
	if (d > 14 || d == 11)
		error_handling(&d);
	data->color = init_color(a, b, c, d);
}
