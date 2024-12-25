#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;      // Original value
	int				index;      // Rank/index of this value
	int				flag;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_push
{
	int	next;  // The smallest index not yet in place
	int	max;   // The largest index still under consideration
	int	mid;   // Midpoint for partitioning
	int	flag;  // "Partition" identifier
}	t_push;

/*
** Basic stack functions
*/
t_stack	*create_stack(void);
void	push_stack(t_stack *stack, int value);
int		pop_stack(t_stack *stack);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *a);

/*
** Error and Utils
*/
void	print_error_and_exit(void);

/*
** Push_swap operations
*/
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/*
** Sorting logic
*/
void	sort_stack(t_stack *a, t_stack *b);
void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);

/*
** Quick Sort approach (new):
*/
void	quick_sort(t_stack *a, t_stack *b, int count);

/*
** Additional helper functions (new) for the quick-sort logic:
**  - check if 'a' is sorted and has 'count' elements
**  - find the min/max index in a stack
*/
int		check_sorting_a(t_stack *a, int count);
int		find_min_index(t_stack *a);
int		find_max_index(t_stack *a);
// Optional: a helper to get bottom node (similar to ft_lstlast)
t_node	*bottom_of_stack(t_stack *s);

/*
** Parsing logic
*/
void	parse_args(int argc, char **argv, t_stack *a);
long	ft_atol(const char *str);

#endif
