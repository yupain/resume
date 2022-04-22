#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# include <stdio.h> //printf

typedef struct s_intl
{
	long long		i;
	int				ind;
	struct s_intl	*next;
}	t_intl;

typedef struct s_stack
{
	t_intl	*ints;
	t_intl	*intl;
	int		sp;
}	t_stack;

typedef struct s_push
{
	t_stack	*a;
	t_stack	*b;
	int		sort_fl;
	int		med_ind;
	int		max_ind;
}	t_push;

void		ps_swap(t_stack *stack, int i);// swap stack a/b
void		ps_swapall(t_push *push);// stacks swap
void		ps_push_a(t_push *push);// from b to a
void		ps_push_b(t_push *push);// from a to b

void		ps_rotate(t_stack *stack, int i);// 1 -> last
void		ps_rotate_all(t_push *push);

void		ps_r_rotate(t_stack *stack, int i);// last -> 1
void		ps_r_all_rotate(t_push *push);

int			ps_st_ln(t_stack *stack);// list length
int			ps_n_ln(t_intl *n);// n* list lenght

void		ps_print(t_stack *stack);// вывод списка
void		ps_free(t_push *push);

int			put_ind(t_push *push);
long long	ps_atoi(char *str);
void		put_last_a(t_intl *k, t_push *push);
int			num_check(char **argv);
int			ret_err(void);

int			init_struct(t_push *push);
int			ps_get_med(t_stack *stack);
void		get_ind(t_push *push);
void		ps_sort_a_3(t_push *push);
void		ps_b_fill(t_push *push);

int			ps_find(t_push *push, t_intl *b_int);
int			ps_b_rot(t_push *push);
int			ps_b_find(t_push *push);
void		ps_a_fill(t_push *push);
void		ps_a_to_up(t_stack *stack);

int			ps_i(t_push *push, t_intl *buf);
int			ps_i_a(t_push *push, int i, int i_a, int k);
// int			ps_i_a(t_push *push, int i_a, int k);
#endif