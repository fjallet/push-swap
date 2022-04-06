#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <fcntl.h>
#include "ft_printf/ft_printf.h"

typedef struct s_list  t_list;

struct s_list {
	int 	content;
	t_list  *next;
};

//push_swap.c

//ft_parsing.c
t_list	*ft_parsing(char **arg, t_list	**a);
int		ft_isstandard(char **arg);
int		ft_isint(char *arg);
int		ft_atoi(const char *str);
int		ft_checksame(t_list *a);

//ft_stack_utils.c
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstprint(t_list *a);

//operation.c
void    swap(t_list **a, char c);
void	double_swap(t_list **a, t_list **b);
void    push(t_list **a, t_list **b, char c);
void    rotate(t_list **a, char c);
void    double_rotate(t_list **a, t_list **b);
void	reverse_rotate(t_list **a, char c);
void	double_reverse_rotate(t_list **a, t_list **b);

#endif