#include "pushswap.h"

int main( int argv, char   **argc)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	a = ft_parsing(argc, &a);
	if (!a)
		return (1);
	ft_printf("parsing valide\n");
	push(&a, &b, 'b');
	push(&a, &b, 'b');
	push(&a, &b, 'b');
	double_reverse_rotate(&a, &b);
	ft_printf("---stack A---\n");
	ft_lstprint(a);
	ft_printf("---stack B---\n");
	ft_lstprint(b);
	(void)argv;
	(void)a;
	(void)b;
	return (0);
}