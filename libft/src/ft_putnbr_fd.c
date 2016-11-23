
#include <ft_fc_print.h>
#include <ft_fc_conversion.h>

void	ft_putnbr_fd(int n, int fd)
{
	ft_putstr_fd(ft_itoa(n), fd);
}
