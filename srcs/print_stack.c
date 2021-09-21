#include "push_swap.h"
#include "stdio.h"

void print_stack(t_stack *s)
{
	int i;
	int j;

	j = 0;
	i = 0;
	printf("\n");
	while (i < s->size)
	{
		printf("%d [%d]\n", s->num[i++], j++);
	}
	printf("\n");
}
