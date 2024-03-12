
#include "minishell.h"

int execute_pwd(t_data *data, int output_fd)
{
    ft_putstr_fd(data->pwd, output_fd);
    ft_putchar_fd('\n', output_fd);
    return (0);
}
