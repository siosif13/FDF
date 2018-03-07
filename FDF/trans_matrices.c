#include "fdf.h"

void 	MAT_Identity(double mat[4][4])
{
    mat[0][0]=1; mat[0][1]=0; mat[0][2]=0; mat[0][3]=0;
    mat[1][0]=0; mat[1][1]=1; mat[1][2]=0; mat[1][3]=0;
    mat[2][0]=0; mat[2][1]=0; mat[2][2]=1; mat[2][3]=0;
    mat[3][0]=0; mat[3][1]=0; mat[3][2]=0; mat[3][3]=1;
}

void 	TR_Translate(double matrix[4][4],double tx,double ty,double tz)
{
   double tmat[4][4];
   double temp[4][4];
   tmat[0][0]=1;  tmat[0][1]=0;  tmat[0][2]=0;  tmat[0][3]=0;
   tmat[1][0]=0;  tmat[1][1]=1;  tmat[1][2]=0;  tmat[1][3]=0;
   tmat[2][0]=0;  tmat[2][1]=0;  tmat[2][2]=1;  tmat[2][3]=0;
   tmat[3][0]=tx; tmat[3][1]=ty; tmat[3][2]=tz; tmat[3][3]=1;
   MAT_Mult(matrix,tmat,temp);
   MAT_Copy(temp,matrix);
}

void 	TR_Scale(double matrix[4][4],double sx,double sy, double sz)
{
   double smat[4][4];
   double temp[4][4];
   smat[0][0]=sx; smat[0][1]=0;  smat[0][2]=0;  smat[0][3]=0;
   smat[1][0]=0;  smat[1][1]=sy; smat[1][2]=0;  smat[1][3]=0;
   smat[2][0]=0;  smat[2][1]=0;  smat[2][2]=sz; smat[2][3]=0;
   smat[3][0]=0;  smat[3][1]=0;  smat[3][2]=0;  smat[3][3]=1;
   MAT_Mult(matrix,smat,temp);
   MAT_Copy(temp,matrix);
}

void 	TR_Rotate(double matrix[4][4],double ax,double ay,double az)
{
   double xmat[4][4], ymat[4][4], zmat[4][4];
   double temp[4][4];
   double mat2[4][4];
   xmat[0][0]=1;        xmat[0][1]=0;        xmat[0][2]=0;        xmat[0][3]=0;
   xmat[1][0]=0;        xmat[1][1]=cos(ax);  xmat[1][2]=sin(ax);  xmat[1][3]=0;
   xmat[2][0]=0;        xmat[2][1]=-sin(ax); xmat[2][2]=cos(ax);  xmat[2][3]=0;
   xmat[3][0]=0;        xmat[3][1]=0;        xmat[3][2]=0;        xmat[3][3]=1;

   ymat[0][0]=cos(ay);  ymat[0][1]=0;        ymat[0][2]=-sin(ay); ymat[0][3]=0;
   ymat[1][0]=0;        ymat[1][1]=1;        ymat[1][2]=0;        ymat[1][3]=0;
   ymat[2][0]=sin(ay);  ymat[2][1]=0;        ymat[2][2]=cos(ay);  ymat[2][3]=0;
   ymat[3][0]=0;        ymat[3][1]=0;        ymat[3][2]=0;        ymat[3][3]=1;

   zmat[0][0]=cos(az);  zmat[0][1]=sin(az);  zmat[0][2]=0;        zmat[0][3]=0;
   zmat[1][0]=-sin(az); zmat[1][1]=cos(az);  zmat[1][2]=0;        zmat[1][3]=0;
   zmat[2][0]=0;        zmat[2][1]=0;        zmat[2][2]=1;        zmat[2][3]=0;
   zmat[3][0]=0;        zmat[3][1]=0;        zmat[3][2]=0;        zmat[3][3]=1;

   MAT_Mult(matrix,ymat,temp);
   MAT_Mult(temp,xmat,mat2);
   MAT_Mult(mat2,zmat,matrix);
}

void 	Project(Vertex_t *Vertex, int type, double zoom_z)
{
   float zf;
   float zn;
   float ratio;
   double m[4][4];

   if (type == 0)
   {
     if(!Vertex->Aligned.z)
         Vertex->Aligned.z=1;
     Vertex->Screen.x = FOCAL_DISTANCE * Vertex->Aligned.x / Vertex->Aligned.z + PROJECT_WIDTH;
      Vertex->Screen.y = FOCAL_DISTANCE * Vertex->Aligned.y / Vertex->Aligned.z + PROJECT_HEIGHT;
   }
   else if (type == 1)
   {
      zf = 1000000;
      zn = 0;
      ratio = W_WIDTH / W_HEIGHT;
      MAT_Identity(m);
      m[0][0] = 1.0 / ratio;
      m[1][1] = 1.0 / 1;
      m[2][2] = -2.0 / (zf - zn);
      m[3][2] = -(zf + zn) / (zf - zn);
      VEC_MultMatrix(&Vertex->Aligned, m, &Vertex->Aligned);
      Vertex->Screen.x = Vertex->Aligned.x * zoom_z + W_WIDTH / 2;
      Vertex->Screen.y = Vertex->Aligned.y * zoom_z + W_HEIGHT / 2;
   }
}
