
#include <ft_fc_str.h>
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		size;
	int		i;

	if (s == 0 || f == 0)
		return (0);
	size = ft_strlen(s);
	i = -1;
	str = (char *)malloc((size + 1) * sizeof(*str));
	if (str == 0)
		return (0);
	while (++i < size)
		str[i] = f(s[i]);
	str[i] = 0;
	return (str);
}
