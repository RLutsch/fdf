
#include <ft_fc_str.h>
#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
