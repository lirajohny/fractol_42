/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:09:49 by jlira             #+#    #+#             */
/*   Updated: 2024/04/11 18:55:01 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *s1 && (*s1 == *s2))
	{
		i++;
		s1++;
		s2++;
	}
	if (i == n)
		return (0);
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	if (s[i] != '\0')
	{
		write(fd, s, 1);
		ft_putstr_fd(s + 1, fd);
	}
}
