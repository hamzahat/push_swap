/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:38:02 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/16 03:39:19 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//? Move the first node to the last position.
static int ft_rotate(t_stack *stack)
{
    t_node *first;  // Temporary pointer to the first node of the stack.
    t_node *last;   // Temporary pointer to the last node of the stack.

    // Check if the stack is empty or has only one node.
    if (!stack || !stack->first || !stack->first->next)
        return (1);  // Return 1 if the stack is empty or has only one node.

    // Move the first node to the bottom of the stack.
    first = stack->first;           // Save the first node.
    last = stack->bottom;           // Save the last node.
    stack->first = first->next;     // Update the stack's top to the second node.
    stack->first->prev = NULL;      // Set the new top's prev pointer to NULL.
    last->next = first;             // Point the last node's next to the moved node.
    first->prev = last;             // Set the moved node's prev pointer to the last node.
    first->next = NULL;             // Set the moved node's next pointer to NULL.
    stack->bottom = first;          // Update the stack's bottom to the moved node.

    // Recalculate indices for the stack.
    lst_indix(stack);

    return (0);  // Return 0 to indicate success.
}

//? Rotate stack_a (ra)
void ft_rotate_a(t_stack *stack_a)
{
    // Call ft_rotate to perform the operation on stack_a.
    if (ft_rotate(stack_a) == 0)
        write(1, "ra\n", 3);  // Print "ra" if the operation is successful.
}

//? Rotate stack_b (rb)
void ft_rotate_b(t_stack *stack_b)
{
    // Call ft_rotate to perform the operation on stack_b.
    if (ft_rotate(stack_b) == 0)
        write(1, "rb\n", 3);  // Print "rb" if the operation is successful.
}

//? Rotate both stack_a and stack_b (rr)
void ft_rotate_a_b(t_stack *stack_a, t_stack *stack_b)
{
    // Call ft_rotate on both stack_a and stack_b.
    if (ft_rotate(stack_a) == 0 && ft_rotate(stack_b) == 0)
        write(1, "rr\n", 3);  // Print "rr" if both operations are successful.
}