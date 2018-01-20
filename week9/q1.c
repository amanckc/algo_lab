#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 500
int t[MAX];
//int found=0,notFound=0;
int opcount=0;
void shifttable(char p[])
{
  int i,j,m;
  m=strlen(p);
  for(i=0;i<MAX;i++)
   t[i]=m;
  for(j=0;j<m-1;j++)
    t[p[j]]=m-1-j;
}
int horspool(char src[],char p[])
{
  int i,j,k,m,n;
  n=strlen(src);
  m=strlen(p);
  printf("\nLength of text= %d",n);
  printf("\n Length of pattern= %d",m);
  i=m-1;
  while(i<n)
 {
    k=0;
    while((k<m)&&(p[m-1-k]==src[i-k]))
     {
      k++;opcount++;
     }
     //notFound++;
    if(k==m)
    return(i-m+1);
    else{
     i+=t[src[i]];
    }
 }

  return -1;
}
void main()
{
  char src[100],p[100];
  int pos;
  memset(src,0,100);
  memset(p,0,100);
  printf("Enter the text in which pattern is to be searched:\n");
  fgets(src,100,stdin);
  src[strlen(src)-1]='\0';
  printf("Enter the pattern to be searched:\n");
  fgets(p,100,stdin);
  p[strlen(p)-1]='\0';
  shifttable(p);
  pos=horspool(src,p);
 if(pos>=0)
  printf("\n The desired pattern was found starting from position %d \n",pos+1);
 else
  printf("\n The pattern was not found in the given text\n");
  printf("NO of key comparisons= %d \n",opcount);
  // printf("UNsuccessful searches are= %d \n",notFound);


}