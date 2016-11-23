
void	ft_strclr(char *s)
{
	if (s == 0)
		return ;
	while (*s)
		*s++ = 0;
}
