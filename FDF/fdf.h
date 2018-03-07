#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>

# define FOCAL_DISTANCE 200
# define W_WIDTH 1600
# define W_HEIGHT 900
# define PROJECT_WIDTH W_WIDTH/2
# define PROJECT_HEIGHT W_HEIGHT/2

typedef struct 		l_list
{
	int 			count;			// <- pozitia elementului
	double 			latime_z;       // <- latimea inputului
	double 			lungime_x;	    // <- lungimea inputului
	int 			pos[3];
	struct l_list 	*next;
}					node;

typedef struct 		mx
{
	void			*mlx;
	void			*win;
}					mlx;			


typedef struct 		doiD
{
	short 			x;
	short 			y;
}					_2D;             //<--- Used for storing 2d Coordinates (screen coordinates)

typedef struct 		treiD
{
	double 			x;
	double 			y;
	double 			z;
}					_3D;      		 //<--- Used for storing 3d coordinates (Local, Global and Aligned)

typedef struct  	s_image
{
	void 			*img_ptr;
	int 			*img_adr;
}					img;

typedef struct ve
{
	_3D 			Local;           //<--- Local coordinates, relative to Model Space
	_3D 			Global;			 //<--- Global coordinates, relative to World Space
	_3D 			Aligned;		 //<--- Aligned coordinates, transposed in relation to the camera view.
	_2D 			Screen;			 //<--- The coordinates which are printed on your screen
	double 			latime_z;		 //<--- Latimea obiectului, folositoare pentru a descoperi centrul
	double 			lungime_x;		 //<--- Lungimea obiectului, folositoare pentru a descoperi centrul
	double 			max_y;
	int 			clip;
}					Vertex_t;        //<--- The total info each vertex needs to hold

typedef struct 		dt 
{
	double			mesh_tr[4][4];
	double			camera_tr[4][4];
	Vertex_t		*mesh;
	mlx				q;
	img 			image;
	int 			count;
	int 			*color;
	int 			norme_color;
	int 			projection;
}					s_data;			//<--- Datele organizate intr-o structura pentru mlx_hook

// Matrix Math
void				MAT_Copy(double source[4][4], double dest[4][4]); 
void				MAT_Mult(double mat1[4][4], double mat2[4][4], double dest[4][4]);
void				VEC_MultMatrix(_3D *Source, double mat[4][4], _3D *Dest);

// Transformation matrices
void 				MAT_Identity(double mat[4][4]);
void 				TR_Translate(double matrix[4][4],double tx,double ty,double tz);
void 				TR_Scale(double matrix[4][4],double sx,double sy, double sz);
void 				TR_Rotate(double matrix[4][4],double ax,double ay,double az);
void 				Project(Vertex_t *Vertex, int type, double zoom_z);

//Utility
node				*init_list(int x, int y, int z);
void				add_to_list(node *head, int x, int y, int z);
void				lst_remove(node **head);
void 				image_init(s_data *data);
void 				validate_file(char *str);
void				choose_projection(s_data *data);

//List Creation
node				*write_in_list(node *head, char *str, int z);
node				*read_n_write(char *argv);

//Mash Creation
Vertex_t			*mesh_create(node *head, int *count);

//Rendering

void				render(s_data *data, double zoom_z);
int 				key_rotate(int keycode, s_data *data);

//Plotting
void 				draw_line(_2D pos0, _2D pos1, s_data *data, int e2);
void				plot(s_data *data, int l_count, int L_count);

//Color
int 				get_color(double y0, double y1, double max_y, s_data *data);
void				enter_colors(s_data	*data);
void				error_handling(int *a);
#endif