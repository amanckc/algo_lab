#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 
struct link
{
    int value;
};
 
void main ()
{
    int n, num, index, i, f = 0, search, key, c, opcount = 0;
    struct link  array[ SIZE ];
    printf( "\nEnter limit\n" );
    scanf( "%d",&n );
    printf("the default value is 100000");
    printf( "\nEnter values" );
    for ( i = 0; i < SIZE ; i ++ )
    {
        array[i].value = 100000;
    }
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &num);
        index = num % SIZE;
        if ( array[index].value == 100000)
        {
           array[index].value= num;
        }
        else
        {
            c = index;
            index = ( index + 1 ) % SIZE;
            while ( index != c )
            {
                if ( array[ index ].value == 100000)
                {
                    array[ index ].value= num;
                    break;
                }
                else
                {
                    index = ( index + 1 ) % SIZE;
                }
            }
        }        
    }
    printf("\n The entered table is : \n");
        for ( i = 0; i < SIZE; i++ )
        {
            if ( array[i].value!= 999 )
                {
                    printf("Key is: %d,  and Value is: %d\t ",i % SIZE , array[i].value);
                   
                }
         
            printf( "\n" );
        }
        printf( "\n Check out our search feature ,type a value");
        scanf ( "%d", &search );
        key = search % SIZE;
        if ( array[key].value  == 999 )
        {
            printf( "\nyou got smoked" );
 
        }
        else
        {
            for ( i = 0; i < SIZE; i++ )
            {
                opcount++;
                if ( array[i].value== search )
                {
                    f = 1;
                    key = i;
                    break;
                }
 
            }
        }
        if ( f == 1 )
        {
            printf ( "\nthe index for the value you searched%d", key );
 
        }
        else
        {
            printf ("No match found " );
        }
        printf( "\n The operation count is : %d ",opcount);
 
}