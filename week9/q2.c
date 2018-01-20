#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#define SIZE 10
struct link
{
    int val;
    struct link  *next;
};
int opcount=0;
void main ()
{
    int n, num, index, i, f = 0, search, key;
    struct link * array[ SIZE ];
    printf( "\nEnter limit\n" );
    scanf( "%d", &n );
    printf( "\nEnter values" );
    for ( i = 0; i < SIZE ; i ++ )
    {
        array[i] = NULL;
    }
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &num );
        index = num % SIZE;
        if ( array[index] == NULL)
        {
            struct link *temp = ( struct link * )malloc ( sizeof ( struct link ) );
            temp -> val = num;
            temp -> next = NULL;
            array[index] = temp;
        }
        else
        {
            struct link * temp = array[ index ];
            while ( temp -> next!= NULL )
            {
                temp = temp -> next;
            }
            struct link * t = ( struct link * )malloc ( sizeof ( struct link ) );
            t -> val = num;
            t -> next = NULL;
            temp -> next = t;
        }
        
            
    }
    printf("\n The entered table is : \n ");
        for ( i = 0; i < SIZE - 1; i++ )
        {
            struct link * t= array[i];
            while ( t != NULL )
            {
                printf("Key from the table: %d, Value from the table : %d\t ",i % SIZE , t -> val );
                t = t->next;
            }
            printf( "\n" );
        }
        printf( "\n Enter value to be serached" );
        scanf ( "%d", &search );
        key = search % SIZE;
        if ( array[key] == NULL )
        {   opcount++;
            printf( "\nSorry,not found" );

        }
        else
        {
            struct link * temp = array[ key ];
            while ( temp!=NULL)
            {  opcount++;
                if ( temp -> val == search )
                {
                    f = 1;
                    break;
                }
                temp = temp ->next;
            }
        }
        if ( f == 1 )
        {
            printf ( "\nValue you searched for is at  %d", key + 1 );

        }
        else
        {
            printf ("No match found " );
        }

}