#include "pushswap.h"

t_data	*ft_initdata(t_list *lst, t_data *data)
{
	data->count = 0;
	data->bestcount = 0;
	data->lis = NULL;
	data->bestlis = NULL;
	(void)lst;
	return (data);
}

t_data	*ft_lis(t_list *lst, t_data *data)
{
	int		range;
	t_list	*templis;
	int		tempcount;

	ft_lstcpy((&data->lis), &templis);
	tempcount = data->count;
	range = ft_lstcount(lst);
	while (range > 0)
	{
		if (data->lis == NULL || (data->lis->content < lst->content))
			ft_inclis(lst, data);
		lst = lst->next;
		data = ft_lis(lst, data);
		stack_free((&data->lis));
		ft_lstcpy(&templis, (&data->lis));
		data->count = tempcount;
		range--;
	}
	stack_free(&templis);
	stack_free((&data->lis));
	return (data);
}

t_data	*ft_inclis(t_list *lst, t_data *data)
{
	ft_lstadd_front((&data->lis), ft_lstnew(lst->content));
	data->count += 1;
	if (data->bestcount < data->count)
	{
		data->bestcount = data->count;
		if (data->bestlis != NULL)
			stack_free((&data->bestlis));
		ft_lstcpy((&data->lis), (&data->bestlis));
	}
	return (data);
}

int	ft_isnotlis(int a, t_data data)
{
	t_list	*temp;
	int		range;

	range = ft_lstcount(data.bestlis);
	temp = data.bestlis;
	//ft_printf("%i ", a);
	while (range > 0)
	{
		if (temp->content == a)
		{
			//ft_printf("no\n");
			return (0);
		}
		temp = temp->next;
		range--;
	}
	//ft_printf("yes\n");
	return (1);
}

void	ft_swaplis(t_list **a, t_list **b, t_data data)
{
	int		range;

	range = ft_lstcount(*a);
	while (range > 0)
	{
		ft_printf("%i ", (*a)->content);
		if (ft_isnotlis((*a)->content, data))
			push(a, b, 'b');
		rotate(a, 'a');
		range--;
	}
}