/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:42:51 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/16 02:56:13 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* sorting logic
#include "../push_swap.h"

void ft_sort_numbers(t_stack *stack_a, t_stack *stack_b, int elements_nb)
{
    //* Handle sorting based on the number of elements:
    if (elements_nb <= 10 && elements_nb > 5)
        ft_sort_ten(stack_a, stack_b);      // Sort 6 to 10 elements
    else if (elements_nb == 5)
        ft_sort_five(stack_a, stack_b);    // Sort exactly 5 elements
    else if (elements_nb == 4)
        ft_sort_four(stack_a, stack_b);    // Sort exactly 4 elements
    else if (elements_nb == 3)
        ft_sort_three(stack_a);            // Sort exactly 3 elements
    else if (elements_nb == 2)
        ft_sort_two(stack_a);             // Sort exactly 2 elements
    else
        ft_sort_large(stack_a, stack_b);  // Sort more than 10 elements
}

//! remark :
/* 
	* 3 numbers => 2 OR 3 instructions 				(done)
	* 4 numbers => 0 OR 3 instructions				(done)
	* 5 numbers => 8 OR 12 instructions				(done)
	* 10 numbrers => less than 30 instruction 		(done)
	* 100 numbers => less than 700 instructions 	(done)
	* 500 numbers => less than 5500 instructions 	(done)
*/
