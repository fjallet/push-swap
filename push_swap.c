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

void	ft_move(t_list **a, t_list **b, t_move bestmove)
{
	while (bestmove.rr != 0)
	{
		double_rotate(a, b);
		bestmove.rr--;
	}
	while (bestmove.rrr != 0)
	{
		double_reverse_rotate(a, b);
		bestmove.rrr--;
	}
	while (bestmove.ra != 0)
	{
		rotate(a, 'a');
		bestmove.ra--;
	}
	while (bestmove.rb != 0)
	{
		rotate(b, 'b');
		bestmove.rb--;
	}
	while (bestmove.rra != 0)
	{
		reverse_rotate(a, 'a');
		bestmove.rra--;
	}
	while (bestmove.rrb != 0)
	{
		reverse_rotate(b, 'b');
		bestmove.rrb--;
	}
}

void	ft_printmove(t_move a)
{
	ft_printf("ra : %i\n", a.ra);
	ft_printf("rb : %i\n", a.rb);
	ft_printf("rr : %i\n", a.rr);
	ft_printf("rra : %i\n", a.rra);
	ft_printf("rrb : %i\n", a.rrb);
	ft_printf("rrr : %i\n", a.rrr);
	ft_printf("num : %i\n", a.num);
}

void	ft_pushswap(t_list **a, t_list **b)
{
	t_move	bestmove;
	int		range;

	range = 2;
	while (range > 0)
	{
		ft_printf("---stack A---\n");
		print_stack(*a);
		ft_printf("---stack B---\n");
		print_stack(*b);
		bestmove = checkbestmove(*a, *b);
		ft_printmove(bestmove);
		ft_move(a, b, bestmove);
		push(b, a, 'a');
		range--;
	}
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
	ft_printf("--- LIS ---\n");
	print_stack(data.bestlis);
	stack_free((&data.bestlis));
	ft_pushswap(&a, &b);
	ft_printf("---stack A---\n");
	print_stack(a);
	stack_free(&a);
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