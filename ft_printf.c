/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:14:15 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/04/03 20:31:09 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

/*
** update libft
*/
int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int res;

	if (!str)
		return (-1);
	res = 0;
	while (*str)
	{
		res += ft_putchar(*str);
		str++;
	}
	return (res);
}


/*:
**  update header
**  %[parameter][flags][width][.precision][length]type
*/

typedef struct	s_args
{
	int type;
	int	has_flags;
	int	flags;
	int has_width;
	int width;
	int precision;
	int has_precision;
	int err;
}				t_args;

int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9')
}

int	ft_atoi(const char *str)
{
	size_t	val;
	int		sign;

	val = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = 44 - *str++;
	while (ft_isdigit(*str))
	{
		val = (10 * val) + *str - '0';
		str++;
	}
	if ((val >= LLONG_MAX) && sign == 1)
		return (-1);
	if ((val > LLONG_MAX) && sign == -1)
		return (0);
	return (sign * val); 
}

int	readargs(char *str, t_args *args)
{
	
}

int ft_printf(const char * format, ...)
{
	char	*itr;
	int		res;
	va_list	ap;
	t_args	args;


	itr = (char *)format;
	if (!itr)
		return (-1);
	va_start(ap, format);
	res = 0;
	while (*itr)
	{
		if (*itr == '%')
		{
			itr += readargs(itr, &args);	//placeholder를 벗어날 때까지 읽는다.
			res += ft_put_conv(ap, &args);	//가변인자를 포맷에 맞게 변환 출력시킨다. 에러가 발생할 수 있는 순간에서 어떻게 ?
			continue;
		}
		res += ft_putchar(*itr);
		itr++;
	}
	va_end(ap);
	return (res);
}

#ifdef TEST
# define F(...) \
    ft_printf(__VA_ARGS__)
#else
# include <stdio.h>
# define F(...) \
    printf(__VA_ARGS__)
#endif				//전처리 전에 이루어지므로 일찍 끝나도 무관한 것 같다.


int	main(void)
{
	printf("test ")
	F("%s is %d years old.\n", "zelda", 20);
	return (0);
}

