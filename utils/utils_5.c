/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 06:33:14 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/16 09:06:08 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! helper functions:
#include "../push_swap.h"

//? Get the smallest node in the list.
t_node	*get_small_node(t_stack *stack)
{
	t_node	*tmp;	// Temporary pointer to traverse the stack.
	t_node	*small;	// Pointer to the smallest node.

	// Check if the stack is empty.
	if (!stack || !stack->first)
		return (NULL);

	// Initialize pointers.
	tmp = stack->first;
	small = tmp;

	// Traverse the stack to find the smallest node.
	while (tmp)
	{
		if (tmp->number < small->number)
			small = tmp;	// Update the smallest node.
		tmp = tmp->next;	// Move to the next node.
	}
	return (small);		// Return the smallest node.
}
//? Move the smallest node to the top of the stack.
void	move_to_top(t_stack	*stack)
{
	t_node	*small;		// Pointer to the smallest node.

	// Get the smallest node in the stack.
	small = get_small_node(stack);
	if (small->indix > stack->middle)
	{
		// Use reverse rotate to move it to the top.
		while (stack->first != small)
			ft_reverse_rotate_a(stack);
	}
	// If the smallest node is in the upper half of the stack:
	else
	{
		// Use rotate to move it to the top.
		while (stack->first != small)
			ft_rotate_a(stack);
	}
}
//? Index all nodes of the list starting from 1.
void	lst_indix(t_stack *stack)
{
	t_node	*tmp;	// Temporary pointer to traverse the stack.
	int		i;		// Index counter.

	// Traverse the stack and assign indices to each node.
	tmp = stack->first;
	i = 1;
	while (tmp)
	{
		tmp->indix = i;		// Assign the current index to the node.
		tmp = tmp->next;	// Move to the next node.
		i++;				// Increment the index.
	}
}
//? Find the middle node (the middle number) in the stack.
int	get_middle_node(t_stack *stack)
{
	int		count;		// Counter for the node's position.
	t_node	*tmp;		// Temporary pointer to traverse the stack.
	t_node	*tmp_2;		// Temporary pointer to compare nodes.

	// Check if the stack is empty.
	if (!stack || !stack->first)
		return (0);

	// Traverse the stack to find the middle node.
	tmp = stack->first;
	while (tmp)
	{
		count = 1;
		tmp_2 = stack->first;
		// Count how many nodes have a smaller number than the current node.
		while (tmp_2)
		{
			if (tmp->number > tmp_2->number)
				count++;
			tmp_2 = tmp_2->next;
		}
		// If the count matches the middle index, return the node's number.
		if (count == stack->middle)
			return (tmp->number);
		tmp = tmp->next;	// Move to the next node.
	}
	return (0);
}

//? Append a node to the end of the list with a given value.
void	lst_add_back(t_stack *stack, int value)
{
	t_node		*tmp;	// Temporary pointer for the new node.

	// Allocate memory for the new node.
	tmp = ft_malloc(sizeof(t_node), 1, -1);
	
	// Initialize the new node.
	tmp->number = value;
	tmp->next = NULL;
	tmp->prev = NULL;

	// If the stack is empty, set the new node as the first and bottom node.
	if (!stack->first)
	{
		stack->first = tmp;
		stack->bottom = tmp;
		return ;
	}
	
	// Append the new node to the end of the stack.
	tmp->prev = stack->bottom;
	stack->bottom->next = tmp;
	stack->bottom = tmp;
}
