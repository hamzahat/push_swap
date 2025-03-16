/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:40:51 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/16 03:31:32 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//? Move the first node of one stack to the top of the other.
static int ft_push(t_stack *dest, t_stack *src)
{
    t_node *top;  // Temporary pointer to the top node of the source stack.

    // Check if the source stack is empty.
    if (!src || !src->first)
        return (1);  // Return 1 if the source stack is empty.

    // Move the top node from the source stack to the destination stack.
    top = src->first;          // Save the top node of the source stack.
    src->first = top->next;    // Update the source stack's top to the next node.
    if (src->first)
        src->first->prev = NULL;  // If the source stack is not empty, update the new top's prev pointer.
    else
        src->bottom = NULL;       // If the source stack is now empty, set its bottom to NULL.

    // Insert the moved node at the top of the destination stack.
    top->next = dest->first;  // Point the moved node's next to the destination stack's current top.
    top->prev = NULL;         // Set the moved node's prev to NULL (since it's the new top).
    if (dest->first)
        dest->first->prev = top;  // If the destination stack is not empty, update its top's prev pointer.
    else
        dest->bottom = top;       // If the destination stack is empty, set its bottom to the moved node.

    dest->first = top;  // Update the destination stack's top to the moved node.

    // Update indices and sizes of both stacks.
    lst_indix(dest);  // Recalculate indices for the destination stack.
    lst_indix(src);   // Recalculate indices for the source stack.
    lst_size(dest);   // Recalculate the size of the destination stack.
    lst_size(src);    // Recalculate the size of the source stack.

    return (0);  // Return 0 to indicate success.
}

//? Push top of stack_b to stack_a (pa)
void ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
    // Call ft_push to move the top node from stack_b to stack_a.
    if (ft_push(stack_a, stack_b) == 0)
        write(1, "pa\n", 3);  // Print "pa" if the operation is successful.
}

//? Push top of stack_a to stack_b (pb)
void ft_push_b(t_stack *stack_b, t_stack *stack_a)
{
    // Call ft_push to move the top node from stack_a to stack_b.
    if (ft_push(stack_b, stack_a) == 0)
        write(1, "pb\n", 3);  // Print "pb" if the operation is successful.
}
