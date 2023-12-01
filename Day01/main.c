/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:53:34 by vkettune          #+#    #+#             */
/*   Updated: 2023/12/01 14:40:59 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int combine(int first, int last)
{
	int num = first * 10;
	num += last;
	return (num);
}

int strlen_i(int i, char **argv)
{
	int j = 0;

	while (argv[i][j] != '\0')
		j++;
	return (j);
}

int	*find_value(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int first = -1;
	int last = -1;
	int sum = 0;
	int *res;

	while (argv[i] != NULL && i < argc) // while there are lines to decode
	{
		j = 0;
		while (first < 0 && argv[i][j] != '\0') // find first num
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9') // is digit?
				first = argv[i][j] - '0';
			else
				j++;
		}
		j = strlen_i(i, argv) - 1;
		while (last < 0 && j >= 0) // find last num
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9') // is digit?
			{
				last = argv[i][j] - '0';
				break; // Exit the loop once the last digit is found
			}
			else
				j--;
		}
		if (first >= 0 && last >= 0)
			sum += combine(first, last); // add num from line to the final sum
		first = -1;
		last = -1;
		i++;
	}
	if (!(res = (int *)malloc(sizeof(int))))
      return (NULL);
	*res = sum;
	return (res);
}

/*
int main(int argc, char *argv[])
{
    int *sum = find_value(argc, argv);
    if (sum != NULL)
    {
        printf("The sum of all calibration values is %d\n", *sum);
        free(sum);
    }
    else
    {
        printf("Failed to allocate memory.\n");
    }
    return 0;
}
*/
