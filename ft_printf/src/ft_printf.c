/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:47:59 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/19 18:44:12 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	after_specifier(unsigned char c, va_list args, int *count)
{
	if (c == 'd')
		ft_putnbr((va_arg(args, int)), count);
	else if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'i')
		ft_putnbr((va_arg(args, int)), count);
	else if (c == 'p')
		ft_putptr((va_arg(args, void *)), count);
	else if (c == '%')
		ft_putchar('%', count);
	else if (c == 'u')
		ft_putnbr_unsigned((va_arg(args, unsigned int)), count);
	else if (c == 'x')
		ft_putnbr_hex((va_arg(args, unsigned int)), count, 'x');
	else if (c == 'X')
		ft_putnbr_hex((va_arg(args, unsigned int)), count, 'X');
	else
		printf("Error");
}
int	ft_printf(const char *num, ...)
{
	va_list	args;
	unsigned		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, num);
	while (num[i] != '\0')
	{
		if (num[i] == '%')
		{
			after_specifier(num[i + 1], args, &count);
			i = i + 2;
		}
		else
		{
			ft_putchar(num[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {


// 	/*Test Cases*/
// 	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");
// 	// Edge Case 1: Null Pointer for `%p` (Printing `NULL` Pointer)
// 	ft_printf("this is %p %d\n", NULL, 150);
// 	printf("this is %p %d\n", NULL, 150);
// 	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

// 	// Edge Case 2: Pointer with Address `0x0` (Address of a Variable with Value `0`)
// 	int x = 0;
// 	ft_printf("%p\n", &x);
// 	printf("%p\n", &x);
// 	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

// 	// Edge Case 3: Minimum Value for Signed Integers (`-2147483648`)
// 	int min_int = -2147483648;
// 	ft_printf("%d\n", min_int);
// 	printf("%d\n", min_int);
// 	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

// 	// Edge Case 4: Large Positive Value for Signed Integers (`2147483647`)
// 	int max_int = 2147483647;
// 	ft_printf("%d\n", max_int);
// 	printf("%d\n", max_int);
// 	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

// 	// Edge Case 5: Edge Case for `unsigned int` (`0` and `4294967295`)
// 	unsigned int min_uint = 0;
// 	unsigned int max_uint = 4294967295;
// 	ft_printf("%u\n", min_uint);
// 	printf("%u\n", min_uint);
// 	ft_printf("%u\n", max_uint);
// 	printf("%u\n", max_uint);
// 	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

// 	// Edge Case 6: Printing Hexadecimal with Upper and Lowercase `%X` and `%x`
// 	int num = 255;
// 	ft_printf("%x\n", num); // Lowercase hex
// 	ft_printf("%X\n", num); // Uppercase hex

// 	printf("%x\n", num); // Lowercase hex
// 	printf("%X\n", num); // Uppercase hex
// 	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");
// 	// Edge Case 7: Printing Single Character (`%c`)
// 	ft_printf("%c\n", 'A');
// 	ft_printf("%c\n", 'z');
// 	ft_printf("%c", '\n'); // Testing newline character

// 	printf("%c\n", 'A');
// 	printf("%c\n", 'z');
// 	printf("%c", '\n'); // Testing newline character
// 	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

// 	// Edge Case 8: Empty String (`%s`)
// 	ft_printf("%s\n", "");
// 	printf("%s\n", "");
// 	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

// 	// Edge Case 9: Normal String (`%s`)
// 	ft_printf("%s\n", "Hello, World!");
// 	printf("%s\n", "Hello, World!");
// 	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

// 	// Edge Case 14: Mixing Format Specifiers
// 	ft_printf("Character: %c, String: %s, Integer: %d, Hex: %x\n", 'A', "Test",
// 		123, 255);
// 	printf("Character: %c, String: %s, Integer: %d, Hex: %x\n", 'A', "Test",
// 		123, 255);
// 	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

// 	// Edge Case 15: Edge Case for `%` (Literal Percent Sign)
// 	ft_printf("Percentage: %%\n");
// 	printf("Percentage: %%\n");

// 	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

// 	// Edge Case 17: Zero Values for `%d`, `%u`, `%x`
// 	ft_printf("%d\n", 0); // For signed int
// 	ft_printf("%u\n", 0); // For unsigned int
// 	ft_printf("%x\n", 0); // For hexadecimal
// 	printf("%d\n", 0);    // For signed int
// 	printf("%u\n", 0);    // For unsigned int
// 	printf("%x\n", 0);    // For hexadecimal
// 	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");


// 	printf("%u\n", -100);
// 	ft_printf("%u\n", -100);
// 	/*end of Test Cases*/
// 	return (0);
// }