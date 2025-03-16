/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:24:45 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/16 08:40:43 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! helper parsing functions:
#include "../push_swap.h"

//? ft_error: Writes "Error" to the standard error (stderr) and exits with status -1.
void	ft_error(void)
{
	write(2, "Error\n", 6); // ✅ Write "Error\n" to file descriptor 2 (stderr)
	exit(-1); // ❌ Exit the program with an error status (-1)
}

//? args_len: Calculates the total length of all arguments (including spaces).
size_t	args_len(int ac, char *av[])
{
	size_t	len; // Stores the total length of all characters
	size_t	j;   // Iterator for each character inside an argument
	int		i;   // Iterator for arguments

	len = 0; 
	i = 1; // ✅ Start from `1` to ignore `av[0]` (program name)
	while (i < ac)
	{
		j = 0;
		while (av[i][j++]) // ✅ Count the number of characters in each argument
			len++;
		len++; // ✅ Add 1 space after each argument (for separating numbers)
		i++;
	}
	return (len); // ✅ Return the total length
}

//? ft_max: Compares two numbers and returns the largest one.
int	ft_max(int nb_1, int nb_2)
{
	if (nb_1 > nb_2)
		return (nb_1); // ✅ Return the first number if it's larger
	return (nb_2); // ✅ Otherwise, return the second number
}

//? lst_size: Counts the number of nodes in a linked list (stack)
void	lst_size(t_stack *stack)
{
	t_node	*tmp;
	int		counter;

	tmp = stack->first; // ✅ Start at the first node
	counter = 0;
	while (tmp) // ✅ Traverse through the entire list
	{
		counter++; // ✅ Increment the counter for each node
		tmp = tmp->next; // ✅ Move to the next node
	}
	stack->size = counter;	// ✅ Store the total node count in the stack
	middle_lst(stack);		// ✅ Calculate the middle index
}

//? get the middle of the list
void	middle_lst(t_stack *stack)
{
	if (stack->size % 2 == 0)
		stack->middle = stack->size / 2;
	else
		stack->middle = stack->size / 2 + 1;
}
