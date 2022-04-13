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
	t_list	*templis;
	int		tempcount;

	ft_lstcpy((&data->lis), &templis);
	tempcount = data->count;
	while (lst->next != NULL)
	{
		if (data->lis == NULL || (data->lis->content < lst->content))
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
		}
		lst = lst->next;
		data = ft_lis(lst, data);
		stack_free((&data->lis));
		ft_lstcpy(&templis, (&data->lis));
		data->count = tempcount;
	}
	stack_free(&templis);
	stack_free((&data->lis));
	return (data);
}