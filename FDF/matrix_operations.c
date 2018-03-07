#include "fdf.h"

void	MAT_Copy(double source[4][4], double dest[4][4])
{
    int i;
    int j;
    i = 0;
    while (i < 4)
    {
      j = 0;
      while (j < 4)
      {
        dest[i][j] = source[i][j];
        j++;
      }
      i++;
    }
} 

void	MAT_Mult(double mat1[4][4], double mat2[4][4], double dest[4][4])
{
  int i;
  int j;

  i = 0;
  while (i < 4)
  {
    j = 0;
    while (j < 4)
    {
      dest[i][j] = mat1[i][0] * mat2[0][j]+
                   mat1[i][1] * mat2[1][j]+
                   mat1[i][2] * mat2[2][j]+
                   mat1[i][3] * mat2[3][j];
      j++;
    }
    i++;
  }
}

void	VEC_MultMatrix(_3D *Source, double mat[4][4], _3D *Dest)
{
	 Dest->x =Source->x*mat[0][0]+
            Source->y*mat[1][0]+
            Source->z*mat[2][0]+
                      mat[3][0];
    Dest->y=Source->x*mat[0][1]+
            Source->y*mat[1][1]+
            Source->z*mat[2][1]+
                      mat[3][1];
    Dest->z=Source->x*mat[0][2]+
            Source->y*mat[1][2]+
            Source->z*mat[2][2]+
                      mat[3][2];
}