#include "fdf.h"

void		add_to_list(node *head, int x, int y, int z)
{
	node	*current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = init_list(x, y, z);
}

node		*init_list(int x, int y, int z)
{	
	static int 		c;
	node			*list;

	list = (node*)malloc(sizeof(node));
	if (list == NULL)
		return (NULL);
	list->pos[0] = x;				
	list->pos[1] = y;
	list->pos[2] = z;
	list->next = NULL;
	list->count = c + 1;
	c++;
	return (list);
}

void		lst_remove(node **head)
{
	node	*current;
	node 	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

node		*write_in_list(node *head, char *str, int z)   ///<-- scrie fiecare rand in parte in lista
{
	char 	**arr;
	int 	x;
	
	arr = ft_strsplit(str, ' ');
	x = 0;
	while (arr[x])
	{
		validate_file(arr[x]);
 		if (!head)
		{
			head = init_list(x, ft_atoi_base(arr[x], 10), z);
		}
		else
		{
			add_to_list(head, x, ft_atoi_base(arr[x], 10), z);
		}
		x++;
	}
	head->lungime_x = x;
 	return (head);
}

node		*read_n_write(char *argv)    // <-- foloseste gnl pentru a citi si crea lista
{
	int 	fd;
	char	*line;
	node	*head;
	int 	z;

	z = 0;
	head = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("This file cannot pe opened.");
		exit(0);
	}
	while (get_next_line(fd, &line))
	{
		head = write_in_list(head, line, z);
		z++;
	}
	head->latime_z = z;
	free(line);
	close(fd);
	return (head);
}
