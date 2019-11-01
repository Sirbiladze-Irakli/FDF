/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:25:57 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/01 18:24:26 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			count_words(char *line, char c, char end)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (line[++i] != end)
		if (line[i] == c)
			count++;
	return (count);
}
