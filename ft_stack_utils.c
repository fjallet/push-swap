#include "pushswap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->next = NULL;
	if (!content)
		return (0);
	else
		list->content = content;
	return (list);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		new->next = NULL;
		return ;
	}
	temp = *alst;
	temp = ft_lstlast(temp);
	temp->next = new;
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		new->next = NULL;
		return ;
	}
	new->next = *alst;
	*alst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstprint(t_list *a)
{
	if (!a)
		return ;
	while (a && a->next != NULL)
	{
		ft_printf("%i\n", a->content);
		a = a->next;
	}
	ft_printf("%i\n", a->content);
	return ;
}