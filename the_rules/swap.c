/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:29:41 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/16 03:42:46 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include "../push_swap.h"

//? Swap the first two elements of the stack.
static int ft_swap(t_stack *stack)
{
    t_node *top;    // Temporary pointer to the top node of the stack.
    t_node *second; // Temporary pointer to the second node of the stack.

    // Check if the stack is empty or has only one node.
    if (!stack || !stack->first || !stack->first->next)
        return (1);  // Return 1 if the stack is empty or has only one node.

    // Swap the first and second nodes.
    top = stack->first;          // Save the top node.
    second = top->next;          // Save the second node.
    top->next = second->next;    // Point the top node's next to the third node.
    if (second->next)
        second->next->prev = top; // If the third node exists, update its prev pointer to the top node.
    second->prev = NULL;          // Set the second node's prev pointer to NULL.
    second->next = top;           // Point the second node's next to the top node.
    top->prev = second;           // Set the top node's prev pointer to the second node.
    stack->first = second;        // Update the stack's top to the second node.

    // If the top node is now the last node, update the stack's bottom.
    if (!top->next)
        stack->bottom = top;

    // Recalculate indices for the stack.
    lst_indix(stack);

    return (0);  // Return 0 to indicate success.
}

//? Swap the first two elements of stack_a (sa)
void ft_swap_a(t_stack *stack_a)
{
    // Call ft_swap to perform the operation on stack_a.
    if (ft_swap(stack_a) == 0)
        write(1, "sa\n", 3);  // Print "sa" if the operation is successful.
}

//? Swap the first two elements of stack_b (sb)
void ft_swap_b(t_stack *stack_b)
{
    // Call ft_swap to perform the operation on stack_b.
    if (ft_swap(stack_b) == 0)
        write(1, "sb\n", 3);  // Print "sb" if the operation is successful.
}

//? Swap the first two elements of both stack_a and stack_b (ss)
void ft_swap_a_b(t_stack *stack_a, t_stack *stack_b)
{
    // Call ft_swap on both stack_a and stack_b.
    if (ft_swap(stack_a) == 0 && ft_swap(stack_b) == 0)
        write(1, "ss\n", 3);  // Print "ss" if both operations are successful.
}
