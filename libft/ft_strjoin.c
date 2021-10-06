/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:49:26 by pkari             #+#    #+#             */
/*   Updated: 2021/09/06 14:49:28 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*strnew;
	int		n;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	strnew = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!strnew)
		return (NULL);
	n = -1;
	while (s1[++n])
		strnew[n] = s1[n];
	free(s1);
	s1 = NULL;
	n = -1;
	while (s2[++n] != '\0')
		strnew[n + i] = s2[n];
	strnew[i + n] = '\0';
	return (strnew);
}
