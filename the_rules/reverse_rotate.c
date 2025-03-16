/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:43:09 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/16 03:36:16 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//? Move the last node to the first position.
static int ft_reverse_rotate(t_stack *stack)
{
    t_node *last;  // Temporary pointer to the last node of the stack.

    // Check if the stack is empty or has only one node.
    if (!stack || !stack->first || !stack->first->next)
        return (1);  // Return 1 if the stack is empty or has only one node.

    // Move the last node to the top of the stack.
    last = stack->bottom;           // Save the last node.
    stack->bottom = last->prev;     // Update the stack's bottom to the second-to-last node.
    stack->bottom->next = NULL;     // Set the new bottom's next pointer to NULL.
    last->prev = NULL;              // Set the moved node's prev pointer to NULL.
    last->next = stack->first;      // Point the moved node's next to the current top node.
    stack->first->prev = last;      // Update the current top's prev pointer to the moved node.
    stack->first = last;            // Update the stack's top to the moved node.

    // Recalculate indices for the stack.
    lst_indix(stack);

    return (0);  // Return 0 to indicate success.
}

//? Reverse rotate stack_a (rra)
void ft_reverse_rotate_a(t_stack *stack_a)
{
    // Call ft_reverse_rotate to perform the operation on stack_a.
    if (ft_reverse_rotate(stack_a) == 0)
        write(1, "rra\n", 4);  // Print "rra" if the operation is successful.
}

//? Reverse rotate stack_b (rrb)
void ft_reverse_rotate_b(t_stack *stack_b)
{
    // Call ft_reverse_rotate to perform the operation on stack_b.
    if (ft_reverse_rotate(stack_b) == 0)
        write(1, "rrb\n", 4);  // Print "rrb" if the operation is successful.
}

//? Reverse rotate both stack_a and stack_b (rrr)
void ft_reverse_rotate_a_b(t_stack *stack_a, t_stack *stack_b)
{
    // Call ft_reverse_rotate on both stack_a and stack_b.
    if (ft_reverse_rotate(stack_a) == 0 && ft_reverse_rotate(stack_b) == 0)
        write(1, "rrr\n", 4);  // Print "rrr" if both operations are successful.
}
