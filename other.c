/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:09:49 by jlira             #+#    #+#             */
/*   Updated: 2024/04/26 12:15:41 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check(char **av, int ac)
{
	int		i;
	int		j;
	char	*s;
	int		invalid;

	i = 2;
	j = 0;
	invalid = 0;
	while (i < ac)
	{
		j = 0;
		s = av[i];
		while (s[j] != '\0')
		{
			if ((s[j] != '-' && s[j] != '+' && s[j] != '.')
				&& !((s[j] >= '0' && s[j] <= '9')))
				invalid++;
			j++;
		}
		i++;
	}
	if (invalid > 0)
		return (1);
	return (0);
}

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

void	msg_malloc_err(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}
