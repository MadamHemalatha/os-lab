#include<stdio.h>
#include<conio.h>
#define max 25
void main()
{
int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;
static int bf[max],ff[max];
printf("\n \t Memory Management Scheme-first fit");
printf("\n Enter the number of blocks:");
scanf("%d",&nb);
printf("\n Enter the number of files:");
scanf("%d",&nf);
printf("\n Enter the size of the blocks:\n");
for(i=1;i<=nb;i++)
{
printf("Block %d:",i);
scanf("%d",&b[i]);
}
printf("\n Enter the size of the files:\n");
for(i=1;i<=nf;i++)
{
printf("File %d:",i);
scanf("%d",&f[i]);
}
for(i=1;i<=nf;i++)
{
for(j=1;j<=nb;j++)
{
if(bf[j]!=1)
{
temp=b[j]-f[i];
if(temp>=0)
{
if(highest<temp)
{
ff[i]=j;
highest=temp;
}
}
}
}
frag[i]=highest;
bf[ff[i]]=1;
highest=0;
}
printf("\n File_no \t File_Size \t Block_No \t Block_Size \t Fragement");
for(i=1;i<=nf&&ff[i]!=0;i++)
printf("\n %d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
getch();
}
