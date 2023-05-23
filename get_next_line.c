/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltamim <maltamim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:43:47 by maltamim          #+#    #+#             */
/*   Updated: 2023/03/19 01:06:34 by maltamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*readline(char	*box,  int fd)
{
	int	r;
	char *buff = malloc((BUFFER_SIZE + 1) * sizeof(char));

	r = 1;
	while (r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[r] = '\0';
		if (!buff[0])
			break ;
		box = ft_strjoin(box, buff);
		if (!ft_strchr(box, '\n'))
			break ;
	}
	free(buff);
	return (box);
}

char	*get_line(char *box)
{
	int		i;
	char	*f;

	i = 0;
	while (box[i] != '\0')
	{
		if (box[i] == '\n')
		{
			f = ft_substr(box, 0, i + 1);
			return (f);
		}
		i++;
	}
	return (box);
	
}

char	*refrash(char *box)
{
	int 	i;
	char	*sec_box;
	size_t	len;

	i = 0;
	if (!box[0])
		return (NULL);
	while (box[i])
	{
		if (box[i] == '\0' || box[i] == '\n')
		{
			len = ft_strlen(box);
			sec_box = ft_substr_box(box, i + 1, len);
			printf("%ld\n", len);
			return (sec_box);
		}
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*box;
	char		*str;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483647)
		return (NULL);
	box = readline(box, fd);
	if (!box)
		return (NULL);
	str = get_line(box);
	if (!str)
		return (NULL);
	box = refrash(box);
	return (str);
}


int main(void)
{	
	// int fd = 2;
	int fd = open("trytext1.txt", O_RDONLY);
	if (fd < 0) 
	{
  		perror("Error opening file");
  		exit(EXIT_FAILURE);
	}
	char *line = get_next_line(fd);
	// printf("%s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
		// free(line);
		// line = get_next_line(fd);
		
		// line = get_next_line(fd);
		// printf("%s", line);
	int i = 1;
	// while(line)
	// {
	// 	// printf("%d line :)", i);
	// 	printf("%s ", line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// 	// i++;
	// }
	free(line);
}
