/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:41:57 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/16 02:54:14 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! main logic
#include "../push_swap.h"

int main(int ac, char *av[])
{
    t_stack *stack_a;  // Stack A (main stack to sort)
    t_stack *stack_b;  // Stack B (auxiliary stack)
    int     *args;     // Array of integers from parsed arguments
    int     arr_len;   // Length of the arguments array

//* Parse command-line arguments into an array of integers
    args = parse_args(ac, av, &arr_len);

//* Allocate memory for stack_a and stack_b
    stack_a = ft_malloc(sizeof(t_stack), 1, -1);  // Allocate stack_a
    stack_b = ft_malloc(sizeof(t_stack), 1, -1);  // Allocate stack_b

//* Initialize stack_a with the parsed arguments
    ft_new_list(stack_a, args, arr_len);

//* Sort the elements in stack_a using stack_b
    ft_sort_numbers(stack_a, stack_b, arr_len);

//* Free all allocated memory (0 leaks)
    ft_malloc(0, 0, 0);  // Custom memory cleanup function

    return (0);  // Exit program
}
