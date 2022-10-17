/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:24:48 by mgruson           #+#    #+#             */
/*   Updated: 2022/05/25 12:59:15 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (((char unsigned *)s)[i] == (unsigned char)c)
		{
			return ((char unsigned *)s + i);
		}
		i++;
	}
	return (NULL);
}

/*
int main()
{
    char *tab;

    tab = "bonjour";
    ft_memchr(tab, 'o', 7);
    return (0);


	TO PRINT TO UNDERSTAND : 

	attention au depart tu avais  ecrit ds le if : 
	- (*(char *)(s + i) != '\0' && i < n) 
	- (*(char unsigned *)s) + i) car ca incremente

	printf("%d\n", ((char unsigned *)s)[0]);
	printf("%p\n", (char unsigned *)s);
	printf("%d\n", (((char unsigned *)s)[i]));
	printf("%p\n", (char unsigned *)s + i);
}*/