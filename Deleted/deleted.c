
void pass_radix_10(t_stacks *stack, int div_base)
{
	int j;
	int i;
	int bottom;
	int position;

	j = 0;
	i = 0;
	position = 0;
	bottom = stack->bottom_a;
	while (j <= 9 && stack->bottom_a != -1 )
	{
		if(have_values(stack->stacka, bottom ,j, div_base))
		{
			i = 0;
			bottom = stack->bottom_a;
			while (i <= bottom)
			{
				if(check_sorted_radix(stack, 0))
				{
					j = 9;
					stack->sorted = 1;
					break;
				}					
				if(get_bit_digit((stack->stacka[0]), div_base) == j)
				{
					push_b(stack);
				}			
				else
				{
					position = value_position(stack->stacka, stack->bottom_a,j, div_base);
					if (position == -1)
						break;
					if(position <= stack->bottom_a / 2)
						rotate_a(stack);
					else if (position > stack->bottom_a / 2)
						reverse_rotate_a(stack);
				} 
					if (stack->bottom_a == 2)
					{
						j = 9;
						break;
					}
				i++;
			}
		}
		j++;
	}

}


void up_to_10(t_stacks *stack)
{
		pass_radix_10(stack, 0);
		if(stack->sorted == 1)
			{
				if(stack->bottom_b != -1)
					push_all_b(stack);
			}
		else
		{
		sort3(stack);
		push_all_b(stack);
		}
}




void pass_radix_a(t_stacks *stack, int div_base)
{
	int j;
	int i;
	int bottom;
	int position;

	j = 0;
	i = 0;
	position = 0;
	bottom = stack->bottom_a;
	while (j <= 9 && stack->bottom_a != -1)
	{
		if(have_values(stack->stacka, bottom ,j, div_base))
		{
			i = 0;
			bottom = stack->bottom_a;
			while (i <= bottom)
			{
				if(get_bit_digit((stack->stacka[0]), div_base) == j)
					push_b(stack);			
				else
				{
					position = value_position(stack->stacka, stack->bottom_a,j, div_base);
					if(position <= stack->bottom_a / 2)
						rotate_a(stack);
					else if (position > stack->bottom_a / 2)
						reverse_rotate_a(stack);
				}
				if (div_base == stack->digits_number - 1)
				{
					if(stack->bottom_a == 9)
						{
							j = 9;
							break;
						}
				}
				i++;
			}
		}
		j++;
	}
}

void big_stack(t_stacks *stack)
{
	int i;

	i = 0;
	while (i < stack->digits_number)
	{
		pass_radix_a(stack, i);
		if(i == stack->digits_number - 1)
		 	up_to_10(stack);
		push_all_b(stack);
		i++;
	}
}