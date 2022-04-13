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
		//ft_printf("%i\n", temp->content);
		free(temp);
	}
	//ft_printf("%i\n", (*lst)->content);
	free(*lst);
	*lst = NULL;
}

int main( int argv, char   **argc)
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
	ft_printf("---stack A---\n");
	stack_free(&a);
	ft_printf("--- LIS ---\n");
	print_stack(data.bestlis);
	stack_free((&data.lis));
	ft_printf("---stack B---\n");
	stack_free(&b);
	(void)argv;
	(void)argc;
	(void)a;
	(void)b;
	(void)data;
	return (0);
}