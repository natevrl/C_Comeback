#include <stdio.h>
#include <unistd.h>
#include <string.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i = -1;
	while (str[++i])
	{
		ft_putchar(str[i]);
	}
}

char *ft_strcat(char *s1, char *s2)
{
	int i = 0;
	int j = -1;

	while (s1[i])
		i++;
	while (s2[++j])
		s1[i++] = s2[j];
	s1[i] = '\0';
	return (s1);
}

int already_seen(char *str, int index)
{
	int i = -1;
	while (++i < index)
	{
		if (str[i] == str[index])
			return (1);
	}
	return (0);
}

void ft_union(char *s1, char *s2)
{
	int i = -1;
	char *cat = ft_strcat(s1, s2);
	while (cat[++i])
	{
		if (!already_seen(s1, i))
			ft_putchar(s1[i]);
	}
	ft_putchar('\n');
}

int main(int ac, char **av)
{
	if (ac != 3)
		return (ft_putchar('\n'), 0);
	ft_union(av[1], av[2]);
	return (0);
}
