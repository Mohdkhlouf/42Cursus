# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 14:11:43 by mkhlouf           #+#    #+#              #
#    Updated: 2024/08/22 14:12:24 by mkhlouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
cc="gcc"
src=*.c
cflags="-c -Wall -Werror -Wextra"
lib_name="libft.a"

$cc $cflags $src
ar rc $lib_name *.o
ranlib $lib_name
rm *.o

