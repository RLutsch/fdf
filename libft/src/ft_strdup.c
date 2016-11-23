
#include <ft_fc_str.h>
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*strcopy;
	int		size;
	int		i;

	i = -1;
	size = ft_strlen(str);
	strcopy = (char *)malloc((size + 1) * sizeof(*strcopy));
	while (++i < size)
		strcopy[i] = str[i];
	strcopy[i] = 0;
	return (strcopy);
}
