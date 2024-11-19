/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:47:59 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/19 15:01:10 by mkhlouf          ###   ########.fr       */
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
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, num);
	while (i < ft_strlen(num))
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

int	main(void)
{
	int *ptr;

	// int max = 1459;
	// ptr = &max;
	// int count = ft_printf("Mohammad is %d %s %c %X %x %p", 980, "Mohammad",
			'c',
	// 		max, max, ptr);
	// printf("\nMohammad is %d %s %c %X %x %p", 980, "Mohammad", 'c', max, max,
	// 	ptr);

	/*Test Cases*/
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");
	// Edge Case 1: Null Pointer for `%p` (Printing `NULL` Pointer)
	ft_printf("this is %p %d\n", NULL, 150);
	printf("this is %p %d\n", NULL, 150);
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 2: Pointer with Address `0x0` (Address of a Variable with Value `0`)
	int x = 0;
	ft_printf("%p\n", &x);
	printf("%p\n", &x);
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 3: Minimum Value for Signed Integers (`-2147483648`)
	int min_int = -2147483648;
	ft_printf("%d\n", min_int);
	printf("%d\n", min_int);
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 4: Large Positive Value for Signed Integers (`2147483647`)
	int max_int = 2147483647;
	ft_printf("%d\n", max_int);
	printf("%d\n", max_int);
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 5: Edge Case for `unsigned int` (`0` and `4294967295`)
	unsigned int min_uint = 0;
	unsigned int max_uint = 4294967295;
	ft_printf("%u\n", min_uint);
	printf("%u\n", min_uint);
	ft_printf("%u\n", max_uint);
	printf("%u\n", max_uint);
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 6: Printing Hexadecimal with Upper and Lowercase `%X` and `%x`
	int num = 255;
	ft_printf("%x\n", num); // Lowercase hex
	ft_printf("%X\n", num); // Uppercase hex

	printf("%x\n", num); // Lowercase hex
	printf("%X\n", num); // Uppercase hex
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");
	// Edge Case 7: Printing Single Character (`%c`)
	ft_printf("%c\n", 'A');
	ft_printf("%c\n", 'z');
	ft_printf("%c", '\n'); // Testing newline character

	printf("%c\n", 'A');
	printf("%c\n", 'z');
	printf("%c", '\n'); // Testing newline character
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 8: Empty String (`%s`)
	ft_printf("%s\n", "");
	printf("%s\n", "");
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 9: Normal String (`%s`)
	ft_printf("%s\n", "Hello, World!");
	printf("%s\n", "Hello, World!");
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// // Edge Case 10: Printing Maximum Width for `%s`
	// char long_string[] = "This is a very long string that will test the print behavior for large strings.";
	// ft_printf("%.10s\n", long_string); // Truncating string to 10 characters
	// printf("%.10s\n", long_string);
	// printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 11: Zero Padding for Integers (`%0*d`)
	ft_printf("%05d\n", 42);   // Padding a number with zeros (total width 5)
	ft_printf("%010d\n", -42); // Padding negative number

	printf("%05d\n", 42);   // Padding a number with zeros (total width 5)
	printf("%010d\n", -42); // Padding negative number

	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 12: Negative Number with Width and Precision (`%-5d`)
	ft_printf("%-5d\n", -42);
	printf("%-5d\n", -42);
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 13: Integer Value with Large Width
	ft_printf("%100d\n", 42); // Very large width
	printf("%100d\n", 42);    // Very large width
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 14: Mixing Format Specifiers
	ft_printf("Character: %c, String: %s, Integer: %d, Hex: %x\n", 'A', "Test",
		123, 255);
	printf("Character: %c, String: %s, Integer: %d, Hex: %x\n", 'A', "Test",
		123, 255);
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 15: Edge Case for `%` (Literal Percent Sign)
	ft_printf("Percentage: %%\n");
	printf("Percentage: %%\n");
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 16: Very Large Integer for `%d` and `%u`
	long long large_int = 9223372036854775807;
		// Maximum value for 64-bit signed integer
	ft_printf("%lld\n", large_int);
	ft_printf("%llu\n", (unsigned long long)large_int);

	printf("%lld\n", large_int);
	printf("%llu\n", (unsigned long long)large_int);
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	// Edge Case 17: Zero Values for `%d`, `%u`, `%x`
	ft_printf("%d\n", 0); // For signed int
	ft_printf("%u\n", 0); // For unsigned int
	ft_printf("%x\n", 0); // For hexadecimal
	printf("%d\n", 0);    // For signed int
	printf("%u\n", 0);    // For unsigned int
	printf("%x\n", 0);    // For hexadecimal
	printf("*Test Cases*||*Test Cases*||*Test Cases*||*Test Cases*\n");

	/*end of Test Cases*/
	return (0);
}