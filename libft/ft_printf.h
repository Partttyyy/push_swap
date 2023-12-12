/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:00:08 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 06:52:05 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *format_str, ...);
int	ft_fprintf(int fd, const char *format_str, ...);
int	logic_part(va_list *arg, const char **format_str, int *written_bytes, int fd);

int	ft_printf_handle_c(va_list *arg, int *written_bytes, int fd);
int	ft_printf_handle_di(va_list *arg, int *written_bytes, int fd);
int	ft_printf_handle_p(va_list *arg, int *written_bytes, int fd);
int	ft_printf_handle_percent(int *written_bytes, int fd);
int	ft_printf_handle_s(va_list *arg, int *written_bytes, int fd);
int	ft_printf_handle_u(va_list *arg, int *written_bytes, int fd);
int	ft_printf_handle_x(va_list *arg, int *written_bytes, int fd);
int	ft_printf_handle_xx(va_list *arg, int *written_bytes, int fd);

#endif