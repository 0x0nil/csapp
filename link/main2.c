/*main2.c*/
#include<stdio.h>
void addvec(int *x,int *y,int *z,int n);
void multvec(int *x,int *y,int *z,int n);
int x[2]={1,2};
int y[2]={3,4};
int z[2];

int main()
{
	addvec(x,y,z,2);
	printf("z=[%d %d]\n",z[0],z[1]);
	return 0;
}
