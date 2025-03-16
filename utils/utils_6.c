/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:04:24 by hamza_hat         #+#    #+#             */
/*   Updated: 2025/03/16 10:01:06 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! helper functions:
#include "../push_swap.h"

//? Create stack_A and fill it with the array of arguments.
void	ft_new_list(t_stack *stack, int *arr_args, int arr_len)
{
	int	i;

	i = 0;
	// Check if the array of arguments is NULL.
	if (!arr_args)
		return ;
	// Add each argument to the stack.
	while (i < arr_len)
	{
		lst_add_back(stack, arr_args[i]);	// Append the argument to the stack.
		i++;	// Move to the next argument.
	}
	// Update indices and size of the stack.
	lst_indix(stack);
	lst_size(stack);
}
//? Find the target node in stack_A for each node in stack_B.
void	find_target(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_b;	// Pointer to traverse stack_B.
	t_node	*tmp;		// Pointer to traverse stack_A.
	t_node	*target;	// Pointer to store the target node.

	current_b = stack_b->first;	// Start from the top of stack_B.

	// Traverse stack_B to find targets in stack_A.
	while (current_b)
	{
		tmp = stack_a->first;	// Start from the top of stack_A.
		target = NULL;			// Reset the target for the current node.

		// Traverse stack_A to find the smallest node larger than current_b.
		while (tmp)
		{
			if (tmp->number > current_b->number)
			{
				if (!target || tmp->number < target->number)
					target = tmp;	// Update the target if a smaller node is found.
			}
			tmp = tmp->next;	// Move to the next node in stack_A.
		}
		// If no target is found, use the smallest node in stack_A.
		if (!target)
			target = get_small_node(stack_a);
		current_b->target = target;		// Assign the target to the current node in stack_B.
		current_b = current_b->next;	// Move to the next node in stack_B.
	}
}
//? Calculate the cost to move each node in stack_B to the top and its target.
void	calculate_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_b;		// Pointer to traverse stack_B.

	// Find targets for all nodes in stack_B.
	find_target(stack_a, stack_b);
	current_b = stack_b->first;		// Start from the top of stack_B.
	// Traverse stack_B to calculate costs.
	while (current_b)
	{
		// Calculate the cost to move the current node to the top of stack_B.
		if (current_b->indix <= stack_b->middle)
			current_b->cost_to_top = current_b->indix;	// Cost for upper half.
		else
			current_b->cost_to_top = stack_b->size - current_b->indix;	// Cost for lower half.

		// Calculate the cost to move the target node to the top of stack_A.
		if (current_b->target->indix <= stack_a->middle)	// Cost for upper half.
			current_b->target->cost_to_top = current_b->target->indix;	// Cost for lower half.
		else
			current_b->target->cost_to_top = stack_a->size - current_b->target->indix;

		// Calculate the total cost based on the positions of the current node and its target.
		if ((current_b->indix < stack_b->middle && current_b->target->indix < stack_a->middle) || (current_b->indix >= stack_b->middle && current_b->target->indix >= stack_a->middle))
			current_b->total_cost = ft_max(current_b->cost_to_top, current_b->target->cost_to_top);	// Use the maximum cost.
		else
			current_b->total_cost = current_b->cost_to_top + current_b->target->cost_to_top;	// Sum the costs.

		current_b = current_b->next;	// Move to the next node in stack_B.
	}
}

//? Find the cheapest node in stack_B (the one with the lowest total cost).
t_node	*find_cheapest_node(t_stack *stack_b)
{
	t_node	*current_b;		// Pointer to traverse stack_B.
	t_node	*cheapest_node;	// Pointer to store the cheapest node.

	current_b = stack_b->first;	 // Start from the top of stack_B.
	cheapest_node = stack_b->first;	// Assume the first node is the cheapest.

	// Traverse stack_B to find the node with the lowest total cost.
	while (current_b)
	{
		if (current_b->total_cost < cheapest_node->total_cost)
			cheapest_node = current_b;	// Update the cheapest node.
		current_b = current_b->next;	// Move to the next node.
	}
	return (cheapest_node);		// Return the cheapest node.
}

//? Move the cheapest node and its target to the top of their stacks, then push to stack_A.
void	mv_cheap_nod_top(t_stack *stack_a, t_stack *stack_b, t_node *cheap_nod)
{
	// Move the cheapest node and its target to the top of their stacks.
	while (cheap_nod != stack_b->first || cheap_nod->target != stack_a->first)
	{
		// If both nodes are in the upper half, rotate both stacks.
		if (cheap_nod != stack_b->first && cheap_nod->target != stack_a->first && cheap_nod->indix <= stack_b->middle && cheap_nod->target->indix <= stack_a->middle)
			ft_rotate_a_b(stack_a, stack_b);
			
		// If both nodes are in the lower half, reverse rotate both stacks.
		else if (cheap_nod != stack_b->first && cheap_nod->target != stack_a->first && cheap_nod->indix > stack_b->middle && cheap_nod->target->indix > stack_a->middle)
			ft_reverse_rotate_a_b(stack_a, stack_b);

		// If the cheapest node is in the upper half, rotate stack_B.
		else if (cheap_nod != stack_b->first && cheap_nod->indix <= stack_b->middle)
			ft_rotate_b(stack_b);

		// If the cheapest node is in the lower half, reverse rotate stack_B.
		else if (cheap_nod != stack_b->first && cheap_nod->indix > stack_b->middle)
			ft_reverse_rotate_b(stack_b);
			
		// If the target node is in the upper half, rotate stack_A.
		else if (cheap_nod->target != stack_a->first && cheap_nod->target->indix <= stack_a->middle)
			ft_rotate_a(stack_a);
			
		// If the target node is in the lower half, reverse rotate stack_A.
		else if (cheap_nod->target != stack_a->first && cheap_nod->target->indix > stack_a->middle)
			ft_reverse_rotate_a(stack_a);
	}
	 // Push the cheapest node from stack_B to stack_A.
	ft_push_a(stack_a, stack_b);
}
