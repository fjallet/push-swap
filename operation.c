#include "pushswap.h"

void    swap(t_list **a, char c)
{
	t_list *temp;

	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	ft_printf("s%c\n", c);
}

void	double_swap(t_list **a, t_list **b)
{
	t_list *temp;

	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
	ft_printf("ss\n");
}

void    push(t_list **a, t_list **b, char c)
{
	t_list  *temp;

	temp = *a;
	*a = temp->next;
	ft_lstadd_front(b, temp);
	ft_printf("p%c\n", c);
}

void    rotate(t_list **a, char c)
{
	t_list  *temp;
	t_list	*temp2;

	temp = *a;
	*a = temp->next;
	temp2 = ft_lstlast(*a);
	temp2->next = temp;
	temp->next = NULL;
	ft_printf("r%c\n", c);
}

void    double_rotate(t_list **a, t_list **b)
{
	t_list  *temp;
	t_list	*temp2;

	temp = *a;
	*a = temp->next;
	temp2 = ft_lstlast(*a);
	temp2->next = temp;
	temp->next = NULL;
	temp = *b;
	*b = temp->next;
	temp2 = ft_lstlast(*b);
	temp2->next = temp;
	temp->next = NULL;
	ft_printf("rr\n");
}

void	reverse_rotate(t_list **a, char c)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *a;
	if (!*a)
		return ;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = *a;
	*a = temp2;
	ft_printf("rr%c\n", c);
}

void	double_reverse_rotate(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *a;
	if (!*a)
		return ;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = *a;
	*a = temp2;
	temp = *b;
	if (!*b)
		return ;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = *b;
	*b = temp2;
	ft_printf("rrr\n");
}