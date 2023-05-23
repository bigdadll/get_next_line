/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltamim <maltamim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:44:13 by maltamim          #+#    #+#             */
/*   Updated: 2023/02/10 12:44:14 by maltamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strchr(char *box, int the_newline_value)
{
	int i;

	i = 0;
	while (box[i] && box[i] != the_newline_value)
		i++;
	if (box[i] == the_newline_value)
		return (0);
	return (1);
}

char	*ft_substr(char *box, unsigned int i, size_t len)
{
	char	*str;
	size_t	stlen;
	size_t	j;

	if (!box)
		return(NULL);
	j = 0;
	stlen = ft_strlen(box);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < stlen && len > 1)
		str[j++] = box[i++];
	str[j] = '\0';
	if (!str[0])
	{
		free(str);
		return (NULL);
	}
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*c;

	c = (char *) s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t c, size_t s)
{
	void	*p;

	p = malloc(c * s);
	if (!p)
	{
		free(p);
		return (NULL);
	}
	ft_bzero(p, c * s);
	return (p);
}

char	*ft_str_init(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	str[0] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_str_init();
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = 0;
	free(s1);
	return (str);
}
