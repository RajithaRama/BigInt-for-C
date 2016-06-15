#include "bigint.h"
#include <stdlib.h>

/* implement the functions in *.h 
 * Given are broken code!!!!!!!
 */ 


bigint_t new_bigint(int a) 
{
	int rem;
	bigint_t head = malloc(sizeof(struct linked_node*));
	*head = NULL;
	while(a!=0){
		rem = a%100;
		//printf("%d\n", (char)rem);
		addnode((char)rem, head);
		a = a/100;
	}
	return head;
		
}


int add(bigint_t * ps, bigint_t a, bigint_t b)
{	//if(**ps) free_bigint(*ps);
	
	
	bigint_t s = * ps;
	s = malloc(sizeof(struct linked_node *));
	int sizea = 1, sizeb = 1, rem = 0, sum = 0, i, j;
	*s = NULL;
	struct linked_node * as = *a;
	struct linked_node * bs = *b;

	while((as -> next)){
		as = (as -> next);
		sizea++;
	}
	while((bs -> next)){
		bs = (bs -> next);
		sizeb++;
	}
	
	i = sizea-1;
	j = sizeb-1;
	
	bigint_t aarry = malloc(sizeof(struct linked_node *)*sizea);
	bigint_t barry = malloc(sizeof(struct linked_node *)*sizeb);
	
	while(((*a))){
		aarry[i] = *a;
		*a = ((*a) -> next);
		i--;
	}
	while((*b)){
		barry[j] = *b;
		(*b) = ((*b) -> next);
		j--;
	}
	printf("%d %d \n", sizea, sizeb);
	printf("%d %d \n", i, j); 
	for(;sizea>0 && sizeb>0; sizea--, sizeb--, i++, j++){
	printf("%d %d %d\n", aarry[i+1] -> data, barry[j+1] -> data, rem);
		sum = ( aarry[i+1] -> data) + (barry[j+1] -> data) + rem;
		addnode((char)(sum%100), s);
		rem = sum/100;
	printf("sizea = %d sizeb = %d sum = %d rem = %d \n", sizea, sizeb, (*s)->data, rem); 
	}
	printf("%d %d \n", sizea, sizeb); 	
	while(sizea>0){
		addnode((aarry[i+1] -> data) + rem, s);
		sizea--;
		i++;
		rem = 0;
	}
	while(sizeb>0){
		addnode((barry[j+1] -> data) + rem, s);
		sizeb--;
		j++;
		rem = 0;
		//printf("sizea = %d sizeb = %d sum = %d rem = %d \n", sizea, sizeb, (*s)->data, rem);
	}
	*ps = s;
	
	return 0;
}
void free_bigint(bigint_t a){
	deletelist(a);
} 


void show_bigint(bigint_t v) 
{
	showlist(*v);
}

		 

/*
int main()
{
	bigint_t a = new_bigint(1099);
	bigint_t b = new_bigint(56456);
	bigint_t c;
	show_bigint(a);
	show_bigint(b);
	add(&c, a, b);
	//printf("sizea = %d\n", (*c)->data);
	//printf("..\n");
	show_bigint(c);
	return 0;
}
*/
