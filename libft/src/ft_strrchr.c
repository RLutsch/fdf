
#include <ft_fc_str.h>

char	*ft_strrchr(const char *str, int c)
{
	int		size;

	size = ft_strlen(str);
	while (size >= 0)
	{
		if (str[size] == (char)c)
			return ((char *)&str[size]);
		size--;
	}
	return (0);
}
