#include <bigint.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main()
{
  int i, f; 
  for(f = 1; f < 50; f++) {
    bigint_t a, b, fib; 
    for(i=2, a = new_bigint(1), b = new_bigint(1), fib = new_bigint(1); i < f; i++) { 
		printf("..\n");
		printf("\n");
      add(&fib, a, b); 
      printf("..\n");
      printf("..\n");
      free_bigint(a);
      printf("\n");
      a = b;    
      b = fib;
    }

    printf("%d the Fib is ", f);
    show_bigint(fib);
    free_bigint(a);
    free_bigint(b);
    free_bigint(fib);
    

  } // end for(fib=10..)

  return 0; 
}
  
  
