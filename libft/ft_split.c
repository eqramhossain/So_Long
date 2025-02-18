/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:17:48 by ehossain          #+#    #+#             */
/*   Updated: 2024/11/23 11:49:32 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char		**ft_split(char const *str, char c);
static void	ft_freeup(char *strs);
static int	ft_countword(const char *str, char c);
static void	ft_strcpy(char *word, char *str, char c, int j);
static char	*ft_stralloc(char *str, char c, int *k);

// int	main(void)
// {
// 	char	str[] = "This/is/a/test/";
// 	char	c;
// 	char	**ptr_split;
//
// 	c = '/';
// 	ptr_split = ft_split(str, c);
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("the ptr_split[%d] = %s\n", i, ptr_split[i]);
// 	}
// 	printf("counted word in str = %d\n", ft_countword(str, c));
// 	return (0);
// }

char	**ft_split(char const *str, char c)
{
	char	**ptr_str;
	int		i;
	int		j;
	int		k;

	if (str == NULL)
		return (NULL);
	i = 0;
	j = ft_countword((char *)str, c);
	k = 0;
	ptr_str = (char **)malloc(sizeof(char *) * (j + 1));
	if (ptr_str == NULL)
		return (NULL);
	ptr_str[j] = NULL;
	while (i < j)
	{
		ptr_str[i] = ft_stralloc(((char *)str), c, &k);
		if (ptr_str[i] == NULL)
		{
			ft_freeup(ptr_str[i]);
		}
		i++;
	}
	return (ptr_str);
}

static int	ft_countword(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word = word + 1;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (word);
		}
		i++;
	}
	return (word);
}

static char	*ft_stralloc(char *str, char c, int *k)
{
	char	*word;
	int		j;
	int		word_len;

	word = NULL;
	j = *k;
	while (str[*k] != '\0')
	{
		if (str[*k] != c)
		{
			word_len = 0;
			while (str[*k + word_len] != '\0' && str[*k + word_len] != c)
				word_len++;
			word = (char *)malloc(sizeof(char) * (word_len + 1));
			if (word == NULL)
				return (NULL);
			*k += word_len;
			break ;
		}
		*k = *k + 1;
	}
	ft_strcpy(word, str, c, j);
	return (word);
}

static void	ft_freeup(char *strs)
{
	int	i;

	i = 0;
	while (strs[i] != '\0')
	{
		free(strs);
		i++;
	}
	free(strs);
}

static void	ft_strcpy(char *word, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != '\0' && str[j + i] != c)
	{
		word[i] = str[j + i];
		i++;
	}
	word[i] = '\0';
}
