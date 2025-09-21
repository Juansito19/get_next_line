/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:35:02 by jbrosio           #+#    #+#             */
/*   Updated: 2025/05/28 13:58:20 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_buffer(char *buffer)
{
	free(buffer);
	buffer = NULL;
	return (NULL);
}

static char	*update_buffer(char *rest)
{
	char	*new_rest;
	ssize_t	i;

	i = 0;
	if (!rest)
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\0')
		return (free_buffer(rest));
	else if (rest[i] == '\n')
		i++;
	new_rest = ft_substr(rest, i, ft_strlen(rest + i), 0);
	free(rest);
	return (new_rest);
}

static char	*extract_line(char *buffer, char *line)
{
	ssize_t	i;

	i = 0;
	if (!buffer || !buffer[i])
	{
		free(line);
		return (free_buffer(buffer));
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_substr(buffer, 0, i, 0);
	return (line);
}

static char	*read_line(int fd, char *buffer)
{
	char	*aux;
	ssize_t	i;

	if (!buffer)
		buffer = ft_strdup("");
	aux = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux || !buffer)
		return (NULL);
	i = 1;
	while (i > 0 && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, aux, BUFFER_SIZE);
		if (i < 0)
		{
			free(aux);
			return (free_buffer(buffer));
		}
		aux[i] = '\0';
		buffer = ft_strjoin(buffer, aux);
	}
	free(aux);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
	{
		buffer = NULL;
		return (NULL);
	}
	line = NULL;
	line = extract_line(buffer, line);
	if (!line)
	{
		free(line);
		buffer = NULL;
		return (NULL);
	}
	buffer = update_buffer(buffer);
	return (line);
}

// int main(void)
// {
//     int		fd;
//     int		i;
//     char	*line;

// 	line = NULL;
// 	i = 1;
//     fd = open("txt.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("open");
//         return (1);
//     }
//     while ((line = get_next_line(fd)) != NULL)
//     {
//      printf("Esta es la linea [%d] = %s", i, line); // Imprime cada línea
//         free(line);         // Libera la memoria de la línea
// 		i++;
//     }

// 	// line = get_next_line(fd);
//     // printf("Esta es la linea [%d] = %s", i, line);
// 	free(line);
//     close(fd);
//     return 0;
// }