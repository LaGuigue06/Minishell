
#include "minishell.h"

int execute_pwd(t_data *data)
{
    ft_putstr_fd(data->pwd, 1);
    ft_putchar_fd('\n', 1);
    return (0);
}
