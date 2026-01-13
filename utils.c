/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmota-ga <pmota-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:52:52 by pmota-ga          #+#    #+#             */
/*   Updated: 2026/01/13 11:17:02 by pmota-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->arr = (int *)malloc(sizeof(int) * size);
	if (!stack->arr)
	{
		free(stack);
		return (NULL);
	}
	stack->top = -1;
	stack->size = size;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->arr)
			free(stack->arr);
		free(stack);
	}
}

int	is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || stack->top < 1)
		return (1);
	i = 0;
	while (i < stack->top)
	{
		if (stack->arr[i] > stack->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(t_stack *stack)
{
	int	i;
	char		c;

	if (!stack)
		return ;
	write(1, "Stack: ", 7);
	i = 0;
	while (i <= stack->top)
	{
		if (stack->arr[i] < 0)
		{
			write(1, "-", 1);
			c = '0' + (-stack->arr[i] % 10);
		}
		else
			c = '0' + (stack->arr[i] % 10);
		write(1, &c, 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
