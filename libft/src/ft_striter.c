
void	ft_striter(char *s, void (*f)(char *))
{
	if (s == 0 || f == 0)
		return ;
	while (*s)
		f(s++);
}
