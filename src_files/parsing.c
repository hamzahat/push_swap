/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:42:29 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/16 02:49:16 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//? Validate that all arguments contain only digits and spaces (nothing else)
static void	is_valide_arg(int ac, char *av[])
{
	int	i;

	i = 1; // Start from index 1 because index 0 (av[0]) is the program name ( ./push_swap )

	// ✅ Loop through each argument provided in the command line
	while (i < ac)
	{
		// ✅ Check if the argument contains only digits and spaces
		// - `ft_is_digit(av[i])` returns `-1` if the argument contains invalid characters.
		// - If it does, we immediately print an error message and exit.
		if ((ft_is_digit(av[i]) == -1))
			return (ft_error()); // ❌ Invalid input → Print "Error\n" and exit

		i++; // Move to the next argument
	}
}

//?fun do: it convert the strings to int + check for larg numbers + check for duplication + assing it in the arr 
static void is_valide_number(char *nb[], int *arr)
{
    int i;      // Loop counter for iterating through the `nb` array.
    int tmp;    // Temporary variable to store the converted integer.
    int check;  // Flag to check if `ft_atoi` encountered an error (e.g., overflow).

    i = 0;
    // Loop through each string in the `nb` array.
    while (nb[i])
    {
        // Convert the string to an integer using `ft_atoi`.
        // `ft_atoi` returns the converted integer and sets `check` to 1 if there's an error (e.g., overflow).
        tmp = ft_atoi(nb[i], &check);

        // Check if `ft_atoi` encountered an error or if the number is a duplicate.
        if (check || check_duplicate(tmp, arr, i))
        {
            // If there's an error or a duplicate, print "Error" and exit the program.
            write(1, "Error\n", 6);  // Print "Error" to standard output.
            ft_malloc(0, 0, -1);     // Free all allocated memory and exit the program.
        }

        // If the number is valid and not a duplicate, store it in the `arr` array.
        arr[i] = tmp;

        // Move to the next string in the `nb` array.
        i++;
    }
}

//? the mean fun of parsing of arguments
int *parse_args(int ac, char *av[], int *array_len)
{
    size_t  words_number;  // Number of arguments (words) after splitting.
    char    *str;          // Combined string of all arguments.
    char    **numbers;     // Array of strings (split arguments).
    int     *arr_nb;       // Array of integers (converted from strings).

    // If no arguments are provided, exit the program.
    if (ac == 1)
        exit(0);

    // Validate the arguments (check for invalid characters, etc.).
    is_valide_arg(ac, av);

    // Combine all arguments into a single string separated by spaces.
    str = ft_strjoin(ac, av);

    // Split the combined string into an array of strings (individual numbers).
    numbers = ft_split(str, 32, &words_number);

    // Allocate memory for the integer array using custom ft_malloc.
    arr_nb = ft_malloc(sizeof(int) * words_number, 1, -1);

    // Validate the numbers (check for duplicates, invalid numbers, etc.).
    is_valide_number(numbers, arr_nb);

    // If the array is already sorted, exit the program.
    if (check_sorting(arr_nb, words_number))
        ft_malloc(0, 0, 0);

    // Set the length of the array (number of integers).
    *array_len = words_number;

    // Return the array of integers.
    return (arr_nb);
}
