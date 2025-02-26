/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:42:29 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/02/26 15:29:13 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_error()
{
	write(2, "Error\n", 6);
	// return (-1);
	exit(-1);
}

// int	ft_has_duplicate(char c, char *str, int len)
// {
// 	int i = 0;
// 	while (i < len)
// 	{
// 		if (c == str[i])
// 			return (ft_error());
// 		i++;
// 	}
// 	return (0);
// }

static char	*ft_strjoin(int ac, char *av[])
{
	char    *str;
	int len = 0;
	int i = 1;
	int j = 0;
	while (i < ac)
	{
	  j = 0;
		while (av[i][j++])
		  len++;
		len++;
		i++;
	}
	str = malloc(sizeof(char) * (len + 1));
	i = 1;
	len = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
				str[len++] = av[i][j++];
		str[len++] = ' ';
		i++;
	}
	str[len] = 0;
	return (str);
}

static int	ft_isdigit(char *str)
{
	int	key;

	key = 0;
	while (*str)
	{
		if (*str != 32)
		{
			if (*str == '-' || *str == '+')
				str++;
			key = 1;
			if (!(*str >= '0' && *str <= '9'))
				return (-1);
		}
		str++;
	}
	if (key == 0)
		return (-1);
	return (0);
}

int	parse_args(int ac, char *av[]) // add all the strings in one string ( heap )
{
	char	*str;
	char	*arr;
	int	i;

	i = 1;
	if (ac == 1)
		return (0);
	while (i < ac)
	{
		if((ft_isdigit(av[i]) == -1))
			return (ft_error());
		i++;
	}
	str = ft_strjoin(ac, av); // combine all arguments in one string
	printf("%s\n", str);
	
	// split(numbers); splite all numbers to samll strings. every string contain 1 number ex: "   1  "
	char **numbers = ft_splite(str, 32);
	arr = malloc(sizeof(int) * (ac - 1));
	// pass all the strings to atoi one by one ( check for larg numbers )
	// check for duplicate numbers
		// if yes = Error
		// if no = add number to tmp arr
	// if argvs pass all this return the tmp array of valid numbers
	// put every number in a node in the stack A.


	return (3);
}



int main (int ac, char *av[])
{
	printf("%d\n", parse_args(ac, av));
}




//* argument handling & validations
/*
./push_swap "   a1 "
./push_swap 1 2 3 4 "" "   " not_char
ERROR


- out of range ( max_int min_int )   Error \n            (to do)
- ila 2 ar9am m3awdin                Error \n            (to do)
- ila knot msortine                  return 0            (to do)
- ila " 3 4 5"                       Error \n            (to do)
- ila ac < 2                         return 0            (done)
- ila ""                             Error \n            (done)
- ila "    "                         Error \n            (done)

*/
