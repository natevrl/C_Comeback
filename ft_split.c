#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    
    while (str[i])
        i++;
    return (i);
}

int is_space(char c)
{
    if (c == '\0' || c == '\n' || c == ' ' || c == '\t')
        return (1);
    return (0);
}

int next_space(int debut, char *str)
{
    int i = 0;

    while (!is_space(str[++debut]))
        i++;
    return (i);
}

int	number_of_tabs(char *str)
{
	int	i = -1;
	int	number = 0;

	while (str[++i])
	{
		if (!is_space(str[i]))
		{
			i += next_space(i - 1, str) - 1;
			number += 1;
		}
	}
	return (number);
}

char *split_copy(char *str, int debut, int taille)
{
    int i = -1;
    char *tab = malloc(sizeof(char) * taille + 1);
    if (!tab)
        return (NULL);
    while (++i < taille)
    {
        tab[i] = str[debut];
        debut++; 
    }
    tab[i] = '\0';
    return (tab);
}

char **ft_split(char *str)
{
    int i = -1;
    int f = 0;
    int j;
    char **tab_of_split;

    if (!str)
        return (NULL);
    tab_of_split = malloc(sizeof(char *) * (number_of_tabs(str) + 1));
    if (!tab_of_split)
        return (NULL);
    while (++i < ft_strlen(str))
    {
        if (!is_space(str[i]))
        {
            j = i;
            while (!is_space(str[i]))
                i++;
            tab_of_split[f] = split_copy(str, j, i - j);
            f++;
        }
    }
    tab_of_split[f] = 0;
    return (tab_of_split);
}

void free_tab(char **tab)
{
    int i = -1;
    while (tab[++i])
    {
        free(tab[i]);
    }
    free(tab);
}

int main(void)
{
    char **res = ft_split(" je       suis    beau     ");
    int i = 0;
    while (res[i])
    {
        printf("t[%d] = $%s$\n", i, res[i]);
        i++;
    }
    printf("%s",res[i]);
    free_tab(res);
}