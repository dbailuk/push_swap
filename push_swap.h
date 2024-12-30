#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				content;
	int				index;
	int				flag;
	struct s_list	*next;
}	t_list;

typedef struct s_push
{
	int	next;
	int	max;
	int	mid;
	int	flag;
}	t_push;

typedef struct s_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		asize;
	int		bsize;
}	t_swap;

/* --------------------
   List Utils
--------------------- */
t_list	*list_new(int content);
void	list_add_back(t_list **lst, t_list *new_node);
int		list_size(t_list *lst);
t_list	*list_last(t_list *lst);
void	list_clear(t_list **lst);

/* --------------------
   Parsing & indexing
--------------------- */
t_list	*parse_args(int ac, char **av);
void	add_index(t_list *lst);

/* --------------------
   Check & sorting
--------------------- */
int		check_sorting(t_list **stack);
int		check_sorting_a(t_list **stack, int count);
t_list	*find_min_lst(t_list **stack);
t_list	*find_max_lst(t_list **stack);
int		isrevsorted(t_swap *tab);
void	check_sort(t_swap *tab);

/* --------------------
   Sort small & quick
--------------------- */
void	sort_2(t_list **stack);
void	sort_3nbr(t_swap *tab);
void	sort_5nbr(t_swap *tab);
void	quick_sort(t_list **a, t_list **b, int count);

/* --------------------
   Operations
--------------------- */
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
