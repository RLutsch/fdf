
int		ft_match(char *s1, char *s2)
{
	if ((*s1 == *s2 && *s1 != '*')
		|| (*s1 == 0 && *s2 == '*' && (ft_match(s1, s2 + 1) != 0)))
	{
		if (*s1 != 0)
			return (ft_match(s1 + 1, s2 + 1));
		else
			return (1);
	}
	else
	{
		if (*s2 == '*' && *s1)
			return (ft_match(s1 + 1, s2) || ft_match(s1, s2 + 1));
		else
			return (0);
	}
}
