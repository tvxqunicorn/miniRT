/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:58:58 by xli               #+#    #+#             */
/*   Updated: 2021/05/05 18:52:33 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	x;
	int	sign;

	i = 0;
	x = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		x = x * 10 + (str[i] - '0');
		i++;
	}
	return (sign * x);
}

static void	ft_atoi_max_norm_0(char **str, long long *x, long long sign,
	long long flag)
{
	while (**str && **str >= '0' && **str <= '9')
	{
		if (flag == 0LL)
		{
			*x = *x * 10LL + (**str - '0');
			if (*x >= 2147483647LL && sign == 1LL)
				flag = 1LL;
			if (*x > 2147483647LL && sign == -1LL)
				flag = -1LL;
		}
		(*str)++;
	}
}

int	ft_atoi_max(char **str)
{
	long long	x;
	long long	sign;
	long long	flag;

	x = 0LL;
	sign = 1LL;
	flag = 0LL;
	while (**str && ft_isdigit(**str) == 0 && **str != '+' && **str != '-')
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1LL;
		(*str)++;
	}
	ft_atoi_max_norm_0(str, &x, sign, flag);
	if (flag == 1LL)
		return (2147483647);
	if (flag == -1LL)
		return (-2147483648);
	return ((int)(sign * x));
}

double	ft_atodouble(char **str)
{
	double	ans;
	double	num;

	if (!str || !(*str))
		return (0.0);
	while (**str && ft_isdigit(**str) == 0 && **str != '.')
		(*str)++;
	ans = (double)ft_atoi(*str);
	while (**str && ft_isdigit(**str))
		(*str)++;
	if (**str != '.')
		return (ans);
	(*str)++;
	num = (double)ft_atoi(*str);
	while (**str && ft_isdigit(**str))
	{
		(*str)++;
		num /= 10.0;
	}
	return (ans + num);
}

double	ft_neg_double(char **str, char *msg)
{
	double	sign;

	if (!str || !msg || !str[0])
		return (0.0);
	while (**str && ft_isdigit(**str) && **str != '.' && **str != '-')
		(*str)++;
	sign = 1.0;
	if (**str == 0)
	{
		printf("%s ", msg);
		error_exit("not found\n");
	}
	if (**str == '-')
	{
		sign *= -1.0;
		(*str)++;
		if (!ft_isdigit(**str))
			error_exit("negative number in wrong format\n");
	}
	return (sign * ft_atodouble(str));
}
