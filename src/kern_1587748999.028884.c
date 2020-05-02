#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../init_array_lib/init_dyn_array.h"


int main( int argc, const char* argv[] )
{
    srand(time(NULL));

    
	int **B = create_two_dim_int(128, 128, "ones");
	int ***A = create_three_dim_int(16, 64, 16, "ones");
    clock_t start = clock();

	for (int a = 5; a < 11; a++)
	{
	  
	    A[a][a][a]=A[a-5][a-1][a]*30;
	  
	    A[a][a][a]=A[a+3][a+5][a+1]-32;
	}

    clock_t stop = clock();
    double elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("%f", elapsed); 
	deallocate_2d_array(B, 128, 128);
	deallocate_3d_array(A, 16, 64, 16);
    return 0; 
    }