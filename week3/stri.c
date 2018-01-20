#include <stdio.h>
#include <string.h>
 
void search(char *pat, char *txt)
{
  int i,j;
    int M = strlen(pat)-1;
    int N = strlen(txt)-1;
    int opcount=0;
 
    /* A loop to slide pat[] one by one */
    for (i = 0; i <= N - M; i++)
    {
        
 
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
          {opcount++;
            if (txt[i+j] != pat[j])
                break;
        }

 
        if (j == M)  // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
           printf("Pattern found at index %d \n", i);
    }
     printf("opcount =%d\n",opcount);
}
 
/* Driver program to test above function */
int main()
{
   char txt[256] ;
   char pat[256] ;
   printf("enter the string\n");
   fgets(txt,256,stdin);
   printf("enter the sub string\n");
   fgets(pat,256,stdin);
  printf("...........................\n");
   printf("%s",txt );
   printf("%s",pat );
   search(pat, txt);
   return 0;
}