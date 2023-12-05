/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:27:39 by vkettune          #+#    #+#             */
/*   Updated: 2023/12/05 15:55:36 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	end(int j, char *line)
{
	while (line[j] != '\n')
		j++;
	return (j);
}

int	convert_to_num(const char *str)
{
	static const char *num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	static const int num_values = sizeof(num) / sizeof(num[0]);
	int i = 0;
	int a = 0;
	int b = 0;

	printf("num_values: %d\n", num_values);
	while (i < num_values && num[i][b] != '\0')
	{
		printf("Four: %c%c%c%c\n", num[4][0], num[4][1], num[4][2], num[4][3]);
		printf("Comparing '%s' with '%s'\n", str, num[i]);
		printf("Comparing '%c' with '%c'\n", str[a], num[i][b]);
		while (str[a] == num[i][b] && num[i][b] != '\0')
		{
			a++;
			b++;
			printf("Comparing '%c' with '%c'\n", str[a], num[i][b]);
		}
		if (num[i][b] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

int	num(char *line, int j)
{
	int strlen;
	int i = 0;
	strlen = i + len(j, line);
	char	str[] = str[strlen];
	int	k = 0;
	int n = 0;
	while (line[j] != ' ' && line[j] != '\n') // extract the word
		str[k++] = line[j++];
	printf("Str: %s\n", str);
	str[k] = '\0';
	n = convert_to_num(str); // convert the word to a number
	printf("N: %d\n", n);
	/*if (n == -1)
		printf("Invalid input: %s\n", str); // Handle the conversion failure here (e.g., return an error code or take appropriate action)
	*/
	return (n);
}

int	*find_value(int argc, char *argv[])
{
	int	j, sum = 0;
	int	first = -1;
	int	last = -1;
	int	i = 0;
	int	*res;

	while (argv && i < argc) // while there are lines to decode
	{
		FILE *file = fopen("input.txt", "r");
		char line[1000];

		if (file == NULL)
		{
			printf("Failed to open file\n");
			i++;
			continue;
		}
		while (fgets(line, sizeof(line), file) != NULL)
		{
			printf("%s", line);
			j = 0;
			while (first < 0 && line[j] != '\0') // find first num
			{
				if (line[j] >= '0' && line[j] <= '9')
				{
					first = line[j] - '0';
					break ;
				}
				else if (line[j] != ' ')
				{
					printf("test\n");
					first = num(line, j);
					printf("First: %d\n", first);
					fflush (stdout);
					break ;
				}
				else
					j++;
			}
			printf("first: %d\n", first);
			j = end(j, line) - 1;
			while (last < 0 && j >= 0) // find last num
			{
				if (line[j] >= '0' && line[j] <= '9')
				{
					last = line[j] - '0';
					break ;
				}
				else if (line[j] != ' ')
				{
					last = num(line, j);
					break ;
				}
				else
					j--;
			}
			printf("Last: %d\n", last);
			if (first >= 0 && last >= 0)
				sum += (first * 10) + last; // add num from line to the final sum
			first = -1;
			last = -1;
			printf("Sum: %d\n", sum);
		}
		fclose(file); // close the file
		i++;
	}
	if (!(res = (int *)malloc(sizeof(int))))
		return (NULL);
	*res = sum;
	return (res);
}
/*
int	main(int argc, char *argv[])
{
	int	*sum = find_value(argc, argv);
	printf("The sum of all calibration values is %d\n", *sum);
	free(sum);
	return (0);
}*/
