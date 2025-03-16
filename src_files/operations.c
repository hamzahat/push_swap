/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:42:44 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/16 00:34:36 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* sorting operations
#include "../push_swap.h"

//? Sort 3 numbers in stack_a
void	ft_sort_three(t_stack *stack_a)
{
	// ✅ Case 1: If the first number is the largest, rotate (ra)
	// - This moves the largest number to the bottom, bringing the other two up.
	// - Example: [3, 1, 2] → (ra) → [1, 2, 3]
	if (stack_a->first->number > stack_a->first->next->number && stack_a->first->number > stack_a->bottom->number)
		ft_rotate_a(stack_a);

	// ✅ Case 2: If the second number is the largest, reverse rotate (rra)
	// - This moves the largest number to the bottom.
	// - Example: [1, 3, 2] → (rra) → [2, 1, 3]
	else if (stack_a->first->next->number > stack_a->first->number && stack_a->first->next->number > stack_a->bottom->number)
		ft_reverse_rotate_a(stack_a);

	// ✅ Case 3: If the first two numbers are out of order, swap (sa)
	// - Example: [2, 1, 3] → (sa) → [1, 2, 3]
	if (stack_a->first->number > stack_a->first->next->number)
		ft_swap_a(stack_a);
}

//? Sort 4 numbers in stack_a
void	ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	// ✅ Step 1: Move the smallest number to the top of stack_a
	// - This ensures we can push it easily to stack_b
	move_to_top(stack_a);

	// ✅ Step 2: Push the smallest number to stack_b
	// - This temporarily removes it, reducing the problem to sorting 3 numbers.
	ft_push_b(stack_b, stack_a);

	// ✅ Step 3: Sort the remaining 3 numbers in stack_a
	// - Since we already implemented `ft_sort_three`, we reuse it.
	ft_sort_three(stack_a);

	// ✅ Step 4: Push the smallest number back from stack_b to stack_a
	// - Now that stack_a is sorted, we reinsert the smallest number.
	ft_push_a(stack_a, stack_b);
}

//? Sort 5 numbers in stack_a
void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	// ✅ Step 1: Move the smallest number to the top of stack_a
	// - This ensures we can push it easily to stack_b
	move_to_top(stack_a);

	// ✅ Step 2: Push the smallest number to stack_b
	// - This temporarily removes it, reducing the problem to sorting 4 numbers.
	ft_push_b(stack_b, stack_a);

	// ✅ Step 3: Sort the remaining 4 numbers in stack_a
	// - Since we already implemented `ft_sort_four`, we reuse it.
	ft_sort_four(stack_a, stack_b);

	// ✅ Step 4: Push the smallest number back from stack_b to stack_a
	// - Now that stack_a is sorted, we reinsert the smallest number.
	ft_push_a(stack_a, stack_b);
}
//? Sort numbers from 6 to 10 in stack_a
void	ft_sort_ten(t_stack *stack_a, t_stack *stack_b)
{
	// ✅ Step 1: Move numbers from stack_a to stack_b until only 5 numbers remain
	while (stack_a->size > 5)
	{
		// Move the smallest number to the top of stack_a before pushing
		move_to_top(stack_a);
		// Push the smallest number to stack_b
		ft_push_b(stack_b, stack_a);
	}

	// ✅ Step 2: Sort the remaining 5 numbers in stack_a
	// - We already implemented `ft_sort_five`, so we reuse it
	ft_sort_five(stack_a, stack_b);

	// ✅ Step 3: Push back all numbers from stack_b to stack_a
	// - Since stack_a is already sorted, we just reinsert them
	while (stack_b->size > 0)
		ft_push_a(stack_a, stack_b);
}

//? Sort numbers > 10 using the Turkish Algorithm
void	ft_sort_large(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*small_node;
	int		middle;

	// ✅ Step 1: Find the middle value and smallest node
	middle = get_middle_node(stack_a);  // Get the middle value of stack_a
	small_node = get_small_node(stack_a); // Find the smallest node in stack_a

	// ✅ Step 2: Push elements from stack_a to stack_b until only 5 remain
	while (stack_a->size > 5)
	{
		ft_push_b(stack_b, stack_a); // Push top of stack_a to stack_b

		// If the number pushed is greater than the middle value, rotate stack_b
		// - This helps distribute large numbers evenly in stack_b for better sorting.
		if (stack_b->first->number >= middle)
			ft_rotate_b(stack_b);
	}

	// ✅ Step 3: Sort the remaining 5 elements in stack_a
	ft_sort_five(stack_a, stack_b);

	// ✅ Step 4: Push elements back from stack_b to stack_a in sorted order
	while (stack_b->size)
	{
		find_target(stack_a, stack_b); // Find the correct target in stack_a for each node in stack_b
		calculate_costs(stack_a, stack_b); // Calculate the cost to move each node to its correct position
		mv_cheap_nod_top(stack_a, stack_b, find_cheapest_node(stack_b)); // Move the cheapest node to the top and push it
	}

	// ✅ Step 5: Move the smallest element to the top of stack_a
	while (small_node != stack_a->first)
	{
		// If the smallest node is in the first half of stack_a, rotate upwards
		if (small_node->indix <= stack_a->middle)
			ft_rotate_a(stack_a);
		else
			ft_reverse_rotate_a(stack_a); // If in the second half, rotate downwards
	}
}
