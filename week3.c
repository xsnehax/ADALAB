#include <stdio.h>
#include <conio.h>

int N, i, count=0;
int p[100], pi[100];      /* The permutation and its inverse */
int dir[100];             /* The directions of each element  */

void PrintPerm()
{
   int i;
   /* uncomment if you want to print the index of each perm  */
   /*
   count = count + 1;
   printf( "[%8d] ", count );
   */
   for (i=1; i <= N; ++i)
      printf( "%d", p[i] );
};



void PrintTrans( int x, int y )
{
   printf( " (%d %d)", x, y );
   printf( "\n" );
} /* PrintTrans */;



void Move( int x, int d )
{
   int z;
   PrintTrans( pi[x], pi[x]+d );
   z = p[pi[x]+d];
   p[pi[x]] = z;
   p[pi[x]+d] = x;
   pi[z] = pi[x];
   pi[x] = pi[x]+d;
};



void Perm ( int n )
{
   int i;
   if (n > N)
      PrintPerm();
   else
   {
      Perm( n+1 );
      for (i=1; i<=n-1; ++i)
      {
         Move( n, dir[n] );
         Perm( n+1 );
      }
      dir[n] = -dir[n];
   }
};

void main ()
{
   printf( "Enter n for numbers: " );
   scanf( "%d", &N );
   printf( "\n" );
   for (i=1; i<=N; ++i)
   {
      dir[i] = -1; p[i] = i;
      pi[i] = i;
   }
   Perm ( 1 );
   printf( "\n" );
   getch();
}
