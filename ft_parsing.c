#include "pushswap.h"

t_list	*ft_parsing(char **arg, t_list	**a)
{
	int		i;

	i = 1;
	if (ft_isstandard(arg))
		return	(0);
	while (arg[i])
	{
		if (ft_isint(arg[i]))
		{
			ft_printf("Error integer limits\n");
			return (0);
		}
		ft_lstadd_back(a, ft_lstnew(ft_atoi(arg[i])));
		i++;
	}
	if (ft_checksame(*a))
		return (0);
	return (*a);
}

int	ft_isstandard(char **arg)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (arg[i])
	{
		j = 0;
		while(arg[i][j])
		{
			if (!(arg[i][j] >= '0' && '9' >= arg[i][j]) && arg[i][j] != '-')
			{
				ft_printf("%c Error character [%i][%i]\n", arg[i][j], i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isint(char *str)
{
	long	num;
	int		sig;
	int		i;
	
	sig = 1;
	i = 0;
	num = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sig = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (48 <= str[i] && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
		if ((sig > 0 && num > 2147483647) || (sig < 0 && num < -2147483648))
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sig;
	int	i;

	sig = 1;
	i = 0;
	num = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sig = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (48 <= str[i] && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sig);
}

int	ft_checksame(t_list *a)
{
	t_list	*i;
	t_list	*j;

	i = a;
	while (i->next != NULL)
	{
		j = i->next;
		while(j->next != NULL)
		{
			if (i->content == j->content)
			{
				ft_printf("Error same number\n");
				stack_free(&a);
				return (1);
			}
			j = j->next;
		}
		if (i->content == j->content)
		{
			ft_printf("Error same number\n");
			stack_free(&a);
			return (1);
		}
		i = i->next;
	}
	return (0);
}
