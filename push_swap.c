#include "pushswap.h"

void	stack_free(t_list **lst)
{
	t_list *temp;

	if (!(*lst))
		return ;
	while ((*lst)->next != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	free(*lst);
	*lst = NULL;
}

int	main(int argv, char **argc)
{
	t_data	data;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	a = ft_parsing(argc, &a);
	if (!a)
		return (1);
	ft_printf("parsing valide\n");
	ft_initdata(a, &data);
	ft_lis(a, &data);
	ft_swaplis(&a, &b, data);
	ft_printf("---stack A---\n");
	print_stack(a);
	stack_free(&a);
	ft_printf("--- LIS ---\n");
	print_stack(data.bestlis);
	stack_free((&data.bestlis));
	ft_printf("---stack B---\n");
	print_stack(b);
	stack_free(&b);
	(void)argv;
	(void)argc;
	(void)a;
	(void)b;
	(void)data;
	return (0);
}