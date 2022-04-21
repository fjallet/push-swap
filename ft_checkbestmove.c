#include "pushswap.h"

t_move	checkbestmove(t_list *a, t_list *b)
{
	t_move 	posib;
	t_move	posia;
	t_move	bestmove;
	t_move	tempmove;
	int		range;

	posib.rr = 0;
	ft_initmove(&bestmove);
	range = ft_lstcount(b);
	while (posib.rr < range)
	{
		ft_initmove(&tempmove);
		posia = ft_posi(b->content, a);
		posib.rrr = range - posib.rr;
		ft_printf("%i %i\n%i %i\n",posia.rr, posia.rrr, posib.rr, posib.rrr);
		if (posib.rr <= posib.rrr && posia.rr <= posia.rrr)
			ft_rrp(posia, posib, &tempmove);
		if (posib.rr >= posib.rrr && posia.rr >= posia.rrr)
			ft_rrrp(posia, posib, &tempmove);
		ft_swaprrp(posia, posib, &tempmove);
		if (tempmove.num < bestmove.num)
		{
			bestmove = tempmove;
			ft_printmove(bestmove);
		}
		b = b->next;
		posib.rr++;
	}
	return(bestmove);
}

void	ft_rrp(t_move posia, t_move posib, t_move *tempmove)
{
	if (tempmove->num <= posib.rr && tempmove->num <= posia.rr)
		return ;
	ft_initmove(tempmove);
	if (posib.rr >= posia.rr)
	{
		tempmove->rr = posia.rr;
		tempmove->rb = posib.rr - posia.rr;
		tempmove->num = posib.rr;
	}	
	else if (posib.rr < posia.rr)
	{
		tempmove->rr = posib.rr;
		tempmove->ra = posia.rr - posib.rr;
		tempmove->num = posia.rr;
	}
}

void	ft_rrrp(t_move posia, t_move posib, t_move *tempmove)
{
	if (tempmove->num <= posib.rrr && tempmove->num <= posia.rrr)
		return ;
	ft_initmove(tempmove);
	if (posib.rrr >= posia.rrr)
	{
		tempmove->rr = posia.rr;
		tempmove->rb = posib.rr - posia.rr;
		tempmove->num = posib.rr;
	}	
	else if (posib.rrr < posia.rrr)
	{
		tempmove->rr = posib.rr;
		tempmove->ra = posia.rr - posib.rr;
		tempmove->num = posia.rr;
	}
}

void	ft_swaprrp(t_move posia, t_move posib, t_move *tempmove)
{
	if (posia.rr + posib.rrr >= posia.rrr + posib.rr)
	{
		if (tempmove->num > posib.rr + posia.rrr)
		{
			ft_initmove(tempmove);
			tempmove->rra = posia.rrr;
			tempmove->rb = posib.rr;
			tempmove->num = posib.rr + posia.rrr;
		}
	}
	else
	{
		if (tempmove->num > posib.rrr + posia.rr)
		{
			ft_initmove(tempmove);
			tempmove->rra = posia.rr;
			tempmove->rb = posib.rrr;
			tempmove->num = posib.rrr + posia.rr;
		}
	}
}

t_move	ft_posi(int b, t_list *a)
{
	int		range;
	t_move	posi;
	t_list	*temp;

	temp = a;
	range = ft_lstcount(a);
	//ft_printf("-> %i\n", b);
	//ft_printf("%i > ? > %i\n", temp->content, (ft_lstlast(a))->content);
	//ft_printf("%i > ? ou ? > %i\n", temp->content, (ft_lstlast(a))->content);
	if (temp->content > b && b > (ft_lstlast(a))->content)
		posi.rr = 0;
	else if (temp->content > (ft_lstlast(a))->content && (b < temp->content || b > (ft_lstlast(a))->content))
		posi.rr = 0;
	else
	{
		posi.rr = 1;
		while (temp->next != NULL)
		{
			//ft_printf("%i < ? < %i\n", temp->content, temp->next->content);
			if (temp->next->content < temp->content && (b > temp->content || b < temp->next->content))
				break ;
			if (temp->content < b && b < temp->next->content)
				break ;
			posi.rr++;
			temp = temp->next;
		}
	}
	posi.rrr = range - posi.rr;
	//ft_printf("%i fin %i\n", posi.rr, posi.rrr);
	return (posi);
}

void	ft_initmove(t_move *a)
{
	a->ra = 0;
	a->rb = 0;
	a->rr = 0;
	a->rra = 0;
	a->rrb = 0;
	a->rrr = 0;
	a->num = 1000;
}