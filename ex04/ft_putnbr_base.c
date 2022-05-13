/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 04:00:22 by xcarroll          #+#    #+#             */
/*   Updated: 2022/02/27 17:13:16 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_char_illegal(char c, char *c_arr)
{
	int	i;

	i = 0;
	while (c_arr[i] != '\0')
	{
		if (c_arr[i] == c || c_arr[i] == '%' || c_arr[i] == '=')
			return (1);
		else if ((c_arr[i] >= '*' && c_arr[i] <= '/'))
			return (1);
		else if ((c_arr[i] < '!' || c_arr[i] > '~'))
			return (1);
		i++;
	}
	return (0);
}

void	print_base(int nbr, char *base_char, int radix)
{
	if (nbr < radix)
	{
		ft_putchar(base_char[nbr]);
	}
	else
	{
		print_base(nbr / radix, base_char, radix);
		print_base(nbr % radix, base_char, radix);
	}
}

/*
1 = True
0 = False
*/
void	ft_putnbr_base(int nbr, char *base)
{
	int		radix;
	int		base_valid;
	char	base_buffer[1000];

	radix = 0;
	base_valid = 1;
	while (base[radix] != '\0')
	{
		if (is_char_illegal(base[radix], base_buffer))
			base_valid = 0;
		base_buffer[radix] = base[radix];
		radix++;
	}
	if (base_valid && radix > 1)
		print_base(nbr, base, radix);
}

/*
int	main(void)
{
	ft_putnbr_base(42069, "0123456789abcdefghijklmnopqr");
}
*/