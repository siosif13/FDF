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