/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:39:58 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/16 08:17:58 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! helper parsing functions :
#include "../push_swap.h"

//? ft_atoi: Convert a string to an integer and check for overflow.
int	ft_atoi(const char *str, int *check)
{
	long	num;		// Variable to store the converted number.
	int		signe;		// Variable to store the sign of the number.

	*check = 0;			// Initialize the overflow check flag to 0 (no overflow).
	signe = 1;			// Initialize the sign to positive.
	num = 0;			// Initialize the number to 0.

	// Skip leading whitespace characters.
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	// Handle optional sign (+ or -).
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -signe;		// Set the sign to negative if '-' is found.
		str++;					// Move to the next character.
	}
	// Convert the string to a number.
	while (*str <= '9' && *str >= '0')
	{
		num = (num * 10) + (*str++ - 48);	// Convert the character to a digit and add to the number.
		// Check for overflow (outside the range of a 32-bit signed integer).
		if ((num * signe) > 2147483647 || (num * signe) < -2147483648)
			return ((*check = 1));	// Set the overflow flag to 1. and return it (error)
	}
	// Return the converted number with the correct sign.
	return (num * signe);
}

//? ft_strjoin: take the 2D array (argv[]) and return it in one string
char	*ft_strjoin(int ac, char *av[])
{
	char	*str;	// Pointer to store the final joined string
	size_t	len;	// Total length needed for the final string
	size_t	j;		// Index for iterating through characters of each argument
	int		i;		// Index for iterating through arguments

	// ✅ Step 1: Calculate the total length needed for the final string
	// - `args_len(ac, av)` returns the total number of characters in all arguments + spaces.
	len = args_len(ac, av);

	// ✅ Step 2: Allocate memory for the final string
	// - `ft_malloc(sizeof(char) * (len + 1), 1, 1)` dynamically allocates memory.
	// - `+1` is added for the null terminator (`\0`).
	str = ft_malloc(sizeof(char) * (len + 1), 1, 1);

	// ✅ Step 3: Initialize variables for copying characters
	i = 1;		// Start from index 1 (ignore `av[0]`, which is the program name)
	len = 0;	// Reset len to use it as the current writing position in `str`

	// ✅ Step 4: Copy all arguments into the allocated `str`
	while (i < ac)	// Loop through each argument
	{
		j = 0;
		while (av[i][j])	// Copy characters from the current argument
			str[len++] = av[i][j++];

		// ✅ Step 5: Add a space (`32` in ASCII) between arguments . for this case: "1" "2"
		// - This ensures numbers are separated properly when later processed.
		str[len++] = 32;
		i++;	// Move to the next argument
	}
	return (str);	// ✅ The final string contains all arguments joined together, separated by spaces.
}

//? ft_is_digit: Checks if the given string contains only digits and spaces (nothing else)
int	ft_is_digit(char *str)
{
	int	key;	// Flag to check if at least one digit is found

	key = 0;	// Initialize the flag to 0 (no digits found yet)
	while (*str)
	{
		if (*str != 32)	// ✅ Ignore spaces (ASCII 32)
		{
			if (*str == '-' || *str == '+')	// ✅ Allow a single '+' or '-' sign at the beginning of a number
				str++;	// Move to the next character after the sign
			key = 1;	// Set flag to 1 since we encountered a non-space character
			if (!(*str >= '0' && *str <= '9'))	// ❌ If the character is **not** a digit, return an error (-1)
				return (-1);
			if (*(str + 1) == '-' || *(str + 1) == '+')	// ❌ If there is a '+' or '-' **in the middle** of the number, return an error
				return (-1);
		}
		str++;	// Move to the next character
	}
	if (key == 0)	// ❌ If the string only contained spaces, return an error (-1)
		return (-1);
	return (0);		// ✅ The string is valid (only contains digits and spaces)
}

//? check_duplicate: Checks if a number already exists in the array
int	check_duplicate(int nb, int *arr, int len)
{
	int	i;

	i = 0;	// Start iterating from the beginning of the array
	while (i < len)	// Loop through the array
	{
		if (arr[i] == nb)	// ✅ If the number `nb` matches any number in the array, return 1 (duplicate found)
			return (1);
		i++;	// Move to the next element
	}
	return (0);	// ✅ No duplicates found, return 0
}

//? check_sorting: Checks if an array is sorted in ascending order
//? remark!: len - 1 because we already check the last index ( arr[i + 1] )
int	check_sorting(int *arr, size_t len)
{
	size_t	i;

	i = 0; // Start from the first index
	while (i < len - 1) // Loop through the array until the second-to-last element
	{
		// ❌ If any element is greater than the next one, the array is NOT sorted
		if (arr[i] > arr[i + 1])
			return (0);
		i++; // Move to the next element
	}

	// ✅ If we finish the loop without finding an issue, the array is sorted
	return (1);
}
