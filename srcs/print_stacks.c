#include "../include/push_swap.h"

void	print_stacks(t_pw *s)
{
	int	i = 0, j = 0, k = 0, l = 0, m = 0;

	m = s->b->size;
	while (m <= s->c->size - 1)
		s->b->num[m++] = -1;
	printf("\n---------  BOTTOM ---------\n");
	
	while (i <= s->a->size - 1)
		printf("\n     %d  [%d]     %d  [%d]", s->a->num[i++], j++, s->b->num[k++], l++);
	printf("\n\n---------  TOP ---------\n");
	printf(" Stack A         Stack B\n\n");
	printf("\nStack A Size = %d   Stack A Size = %d\n", s->a->size, s->b->size);
}
