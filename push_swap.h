/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:41:28 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/16 10:02:28 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

//! remove this line :
#include <stdio.h>

//? ft_safe_malloc struct:
typedef struct s_mem_node
{
	void				*address;
	struct s_mem_node	*next;
}	t_mem_node;

//? linked_list struct:
typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
	int				cost_to_top;
	int				total_cost;
	int				number;
	int				indix;
}	t_node;

//? stack struct:
typedef struct s_stack
{
	t_node	*first;
	t_node	*bottom;
	int		middle;
	int		size;
}	t_stack;

//! parsing funs:
int		ft_is_digit(char *str);
int		*parse_args(int ac, char *av[], int *array_len);
int		check_sorting(int *arr, size_t len);
int		ft_atoi(const char *str, int *check);
int		check_duplicate(int nb, int *arr, int len);
void	ft_error(void);
void	*ft_malloc(size_t size, int key, int exit_status);
char	**ft_split(const char *str, char c, size_t *words_nb);
char	*ft_strjoin(int ac, char *av[]);
size_t	count_word(const char *str, char c);
size_t	args_len(int ac, char *av[]);

//! linked_list_fun:
void	mv_cheap_nod_top(t_stack *stack_a, t_stack *stack_b, t_node *cheap_nod);
void	ft_new_list(t_stack *stack, int *arr_args, int arr_len);
void	lst_add_back(t_stack *stack, int value);
void	middle_lst(t_stack *stack);
int		get_middle_node(t_stack *stack);
void	move_to_top(t_stack	*stack);
void	lst_indix(t_stack *stack);
void	lst_size(t_stack *stack);
t_node	*get_small_node(t_stack *stack);
t_node	*find_cheapest_node(t_stack *stack_b);

//! the rules fun:
void	ft_swap_a(t_stack *stack_a);
void	ft_swap_b(t_stack *stack_b);
void	ft_swap_a_b(t_stack *stack_a, t_stack *stack_b);
void	ft_push_a(t_stack *stack_a, t_stack *stack_b);
void	ft_push_b(t_stack *stack_b, t_stack *stack_a);
void	ft_rotate_a(t_stack *stack_a);
void	ft_rotate_b(t_stack *stack_b);
void	ft_rotate_a_b(t_stack *stack_a, t_stack *stack_b);
void	ft_reverse_rotate_a(t_stack *stack_a);
void	ft_reverse_rotate_b(t_stack *stack_b);
void	ft_reverse_rotate_a_b(t_stack *stack_a, t_stack *stack_b);
void	find_target(t_stack *stack_a, t_stack *stack_b);
void	calculate_costs(t_stack *stack_a, t_stack *stack_b);
int		ft_max(int nb_1, int nb_2);

//! sorting fun;
void	ft_sort_numbers(t_stack *stack_a, t_stack *stack_b, int elements_nb);
void	ft_sort_ten(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_five(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_four(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_three(t_stack *stack_a);
void	ft_sort_two(t_stack *stack_a);
void	ft_sort_large(t_stack *stack_a, t_stack *stack_b);

//! !!!    remove this    !!!
void print_stack(t_stack *stack, char stack_name);

#endif
