#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define row 10
#define col 10
void insert(float c[row][col]);
void disp(float c[row][col]);
int modulus(float c[row][col]);
void copy_row(float c[row][col]);
void copy_col( float b[row][col],float c[row][col]);
void inverse(float b[row][col],float c[row][col]);
void result(float a[row][col],float b[row][col]);

int nr=3,nc=3;
float mod_a;
int main()
{
     static float a[row][col],b[row][col],c[row][col];
     printf("give the first matrix\n");
     insert(a);
     printf("give the second matrix \n\n");
     insert(b);
     printf("entered matrix is\n\na::\n");
     disp(a);
     printf("\nb::\n\n");
     disp(b);
     mod_a=modulus(b);
     if(mod_a==0)
	{
	  printf("divisoin not possible becaause modulus of second matrix is:: %.2f\n",mod_a);
	  getchar();
	exit(1);
	}
     printf("\nmod_b = %.2f\n",mod_a);
     copy_col(b,c);
     copy_row(c);
     inverse(b,c);
     result(a,b);
return 0;
}
void result(float a[row][col],float b[row][col])
{
     int i,j,k;
     float val;
     static float ans[row][col];
     for(i=0;i<nr;i++)
     {
          for(j=0;j<nc;j++)
          {
               for(k=0;k<nc;k++)
               {
                   val+=a[i][k]*b[k][j];
               }
               ans[i][j]=val ;
               val=0;
          }
     }
     printf("\nfirst matrix divided by  second matrix ::\n\n");
     disp(ans);
}
void copy_row(float c[row][col])
{
     int i,j;

     for(i=nr;i<nr+2;i++)
     {
          for(j=0;j<(nr+2);j++)
          {
               c[i][j]=c[i-nr][j];

          }

     }
}
void copy_col(float b[row][col],float c[row][col])
{
     int i,j;

     for(i=0;i<5;i++)
          {
            for(j=0;j<5;j++)
              {
                 c[i][j]=b[i][j];
              }
          }

     for(i=0;i<nr;i++)
     {
          for(j=0;j<2;j++)
          {
               c[i][nr+j]=b[i][j];
          }
          printf("\n");

     }
     
}
void inverse(float b[row][col],float c[row][col])
{
     int i,j;

     for(i=1;i<(nr+1);i++)
     {
          for(j=1;j<(nc+1);j++)
          {
               b[j-1][i-1]=c[i][j]*c[i+1][j+1]-c[i][j+1]*c[i+1][j];
               b[j-1][i-1]/=mod_a;

          }
     }
}
int modulus(float c[row][col])
{
      static int a,b,d;
      a=c[0][0]*(c[1][1]*c[2][2]-c[1][2]*c[2][1]);
      b=c[0][1]*(c[1][0]*c[2][2]-c[2][0]*c[1][2]);
      d=c[0][2]*(c[1][0]*c[2][1]-c[1][1]*c[2][0]);
      d+=a-b;
      return d;
}

void insert(float a[row][col])
{
     int i,j;
     printf("enter the value in matrix  \n");
     for(i=0;i<nr;i++)
          {
            for(j=0;j<nc;j++)
               {scanf("%f",&a[i][j]);}
          }
}
void disp(float ans[row][col])
{
     int i,j;

     for(i=0;i<nr;i++)
          {
            for(j=0;j<nc;j++)
              {
                 printf("%.2f \t",ans[i][j]);
              }
            printf("\n");
          }
}
