/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:32:48 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/10 14:34:56 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void fill_c_4(char matrix[4][4], int column){
	
		matrix[0][column] = '1';
		matrix[1][column] = '2';
		matrix[2][column] = '3';
		matrix[3][column] = '4';
}

void fill_c_4_r(char matrix[4][4], int column){
	
		matrix[0][column] = '1';
		matrix[1][column] = '2';
		matrix[2][column] = '3';
		matrix[3][column] = '4';
}

void fill_r_4(char matrix[4][4], int row){
	
		matrix[row][0] = '1';
		matrix[row][1] = '2';
		matrix[row][2] = '3';
		matrix[row][3] = '4';
}

void fill_r_4_r(char matrix[4][4], int row){
	
		matrix[row][0] = '1';
		matrix[row][1] = '2';
		matrix[row][2] = '3';
		matrix[row][3] = '4';
}
/******************/
void fill_c_32(char matrix[4][4], int column){
	if (matrix[0][0] == '1' || matrix[0][1] == '1' || matrix[0][2] == '1' || matrix[0][3] == '1')
	{
		matrix[0][column] = '2';
		matrix[1][column] = '3';
		matrix[2][column] = '4';
		matrix[3][column] = '1';
	}
	else
		{
		matrix[0][column] = '1';
		matrix[1][column] = '2';
		matrix[2][column] = '4';
		matrix[3][column] = '3';
	}
}

void fill_c_32_r(char matrix[4][4], int column){
	if (matrix[3][0] == '1' || matrix[3][1] == '1' || matrix[3][2] == '1' || matrix[3][3] == '1')
	{
		matrix[0][column] = '2';
		matrix[1][column] = '3';
		matrix[2][column] = '4';
		matrix[3][column] = '1';
	}
	else
		{
		matrix[0][column] = '1';
		matrix[1][column] = '2';
		matrix[2][column] = '4';
		matrix[3][column] = '3';
	}
}



void fill_r_32(char matrix[4][4], int row){
	if (matrix[0][0] == '1' || matrix[1][0] == '1' || matrix[2][0] == '1' || matrix[3][0] == '1')
	{
		matrix[row][0] = '2';
		matrix[row][1] = '3';
		matrix[row][2] = '4';
		matrix[row][3] = '1';
	}
	else
	{
		matrix[row][0] = '1';
		matrix[row][1] = '2';
		matrix[row][2] = '4';
		matrix[row][3] = '3';
	
	}
		
}

void fill_r_32_r(char matrix[4][4], int row){
	
		if (matrix[0][3] == '1' || matrix[1][3] == '1' || matrix[2][3] == '1' || matrix[3][3] == '1')
	{
		matrix[row][0] = '2';
		matrix[row][1] = '3';
		matrix[row][2] = '4';
		matrix[row][3] = '1';
	}
	else
	{
		matrix[row][0] = '1';
		matrix[row][1] = '2';
		matrix[row][2] = '4';
		matrix[row][3] = '3';
	
	}
	
	

}

/******************************** 3 to 1 functions ****************************/
void fill_c_31(char matrix[4][4], int column)
{
	if (matrix[0][0] == '2' || matrix[0][1] == '2' || matrix[0][2] == '2' || matrix[0][3] == '2')
	{
		if (matrix[1][0] == '1' || matrix[1][1] == '1' || matrix[1][2] == '1' || matrix[1][3] == '1')
		}
			matrix[0][column] = '2';
			matrix[1][column] = '3';
			matrix[2][column] = '1';
			matrix[3][column] = '4';
		}
		else
		{
		matrix[0][column] = '2';
		matrix[1][column] = '1';
		matrix[2][column] = '3';
		matrix[3][column] = '4';
		}
	}
	else
		{
		matrix[0][column] = '1';
		matrix[1][column] = '3';
		matrix[2][column] = '2';
		matrix[3][column] = '4';
	}
}

void fill_c_31_r(char matrix[4][4], int column)
{
	if (matrix[3][0] == '2' || matrix[3][1] == '2' || matrix[3][2] == '2' || matrix[3][3] == '2')
	{
		if (matrix[2][0] == '1' || matrix[2][1] == '1' || matrix[2][2] == '1' || matrix[2][3] == '1')
		}
			matrix[0][column] = '4';
			matrix[1][column] = '1';
			matrix[2][column] = '3';
			matrix[3][column] = '2';
		}
		else
		{
		matrix[0][column] = '4';
		matrix[1][column] = '3';
		matrix[2][column] = '1';
		matrix[3][column] = '2';
		}
	}
	else
		{
		matrix[0][column] = '4';
		matrix[1][column] = '2';
		matrix[2][column] = '3';
		matrix[3][column] = '1';
	}
}

/*****/

void fill_r_31(char matrix[4][4], int row){
	if (matrix[0][0] == '2' || matrix[1][0] == '2' || matrix[2][0] == '2' || matrix[3][0] == '2')
	{
		if (matrix[0][1] == '1' || matrix[1][1] == '1' || matrix[2][1] == '1' || matrix[3][1] == '1')
		{
			matrix[row][0] = '2';
			matrix[row][1] = '3';
			matrix[row][2] = '1';
			matrix[row][3] = '2';
		}
		else
		{
			matrix[row][0] = '2';
			matrix[row][1] = '1';
			matrix[row][2] = '3';
			matrix[row][3] = '4';
		}
	
	
	}
	else
		{
			matrix[row][0] = '1';
			matrix[row][1] = '3';
			matrix[row][2] = '2';
			matrix[row][3] = '4';
		
		}
			
}

void fill_r_31(char matrix[4][4], int row){
	if (matrix[0][3] == '2' || matrix[1][3] == '2' || matrix[2][3] == '2' || matrix[3][3] == '2')
	{
		if (matrix[0][2] == '1' || matrix[1][2] == '1' || matrix[2][2] == '1' || matrix[3][2] == '1')
		{
			matrix[row][0] = '2';
			matrix[row][1] = '3';
			matrix[row][2] = '1';
			matrix[row][3] = '2';
		}
		else
		{
			matrix[row][0] = '2';
			matrix[row][1] = '1';
			matrix[row][2] = '3';
			matrix[row][3] = '4';
		}
	
	
	}
	else
		{
			matrix[row][0] = '1';
			matrix[row][1] = '3';
			matrix[row][2] = '2';
			matrix[row][3] = '4';
		
		}
			
}

/************************************************/
int main (int argc, char* argv[])
{
	int i=0;
	int j=0;
	/*colup*/
	char col1up = argv[1][0];
	char col2up = argv[1][1];
	char col3up = argv[1][2];
	char col4up = argv[1][3];
	/*coldown*/
	char col1down = argv[1][4];
	char col2down = argv[1][5];
	char col3down = argv[1][6];
	char col4down = argv[1][7];
	/*rowright*/
	char row1left = argv[1][8];
	char row2left = argv[1][9];
	char row3left = argv[1][10];
	char row4left = argv[1][11];
	/*row right*/
	char row1right = argv[1][12];
	char row2right = argv[1][13];
	char row3right = argv[1][14];
	char row4right = argv[1][15];
	

	printf("%c\n",col1up);
	printf("%c\n",col2up);
	printf("%c\n",col3up);
	printf("%c\n",col4up);
	

	char matrix[4][4]={{'x','x','x','x'},{'x','x','x','x'},{'x','x','x','x'},{'x','x','x','x'}};
	
	if (col1up == '4' && col1down == '1')
		fill_c_4(matrix, 0);
	if(col2up == '4' && col2down == '1')
		fill_c_4(matrix, 1);
	if(col3up == '4' && col3down == '1')
		fill_c_4(matrix, 2);
	if(col4up == '4' && col4down == '1')
		fill_c_4(matrix, 3);
		
	if (col1down == '4' && col1up == '1' )
		fill_c_4_r(matrix, 0);
	if(col2down == '4' && col2up == '1')
		fill_c_4_r(matrix, 1);
	if(col3down == '4' && col3up == '1')
		fill_c_4_r(matrix, 2);
	if(col4down == '4' && col4up == '1')
		fill_c_4_r(matrix, 3);
		
	if (row1left == '4' && row1right == '1')
		fill_r_4(matrix, 0);
	if(row2left == '4' && row2right == '1')
		fill_r_4(matrix, 1);
	if(row3left == '4' && row3right == '1')
		fill_r_4(matrix, 2);
	if(row4left == '4' && row4right == '1')
		fill_r_4(matrix, 3);
		

	if (row1right == '1' && row1left == '4')
		fill_r_4_r(matrix, 0);
	if(row2right == '1' && row2left == '4')
		fill_r_4_r(matrix, 1);
	if(row3right == '1' && row3left == '4')
		fill_r_4_r(matrix, 2);
	if(row4right == '1' && row4left == '4')
		fill_r_4_r(matrix, 3);
			
	/******************************************/

	if (col1up == '3' && col1down == '2')
		fill_c_32(matrix, 0);
	if (col2up == '3' && col2down == '2')
		fill_c_32(matrix, 1);
	if (col3up == '3' && col3down == '2')
		fill_c_32(matrix, 2);
	if (col4up == '3' && col4down == '2')
		fill_c_32(matrix, 3);

	if (col1up == '2' && col1down == '3')
		fill_c_32_r(matrix, 0);
	if (col2up == '2' && col2down == '3')
		fill_c_32_r(matrix, 1);
	if (col3up == '2' && col3down == '3')
		fill_c_32_r(matrix, 2);
	if (col4up == '2' && col4down == '3')
		fill_c_32_r(matrix, 3);
	
	if (row1left == '3' && row1right == '2')
		fill_r_32(matrix, 0);
	if(row2left == '3' && row2right == '2')
		fill_r_32(matrix, 1);
	if(row3left == '3' && row3right == '2')
		fill_r_32(matrix, 2);
	if(row4left == '3' && row4right == '2')
		fill_r_32(matrix, 3);
		

	if (row1right == '2' && row1left == '3')
		fill_r_32_r(matrix, 0);
	if(row2right == '2' && row2left == '3')
		fill_r_32_r(matrix, 1);
	if(row3right == '2' && row3left == '3')
		fill_r_32_r(matrix, 2);
	if(row4right == '2' && row4left == '3')
		fill_r_32_r(matrix, 3);

		/*************************/
		
		
	if (col1up == '3' && col1down == '1')
		fill_c_31(matrix, 0);
	if (col2up == '3' && col2down == '1')
		fill_c_31(matrix, 1);
	if (col3up == '3' && col3down == '1')
		fill_c_31(matrix, 2);
	if (col4up == '3' && col4down == '1')
		fill_c_31(matrix, 3);

	if (col1up == '1' && col1down == '3')
		fill_c_31_r(matrix, 0);
	if (col2up == '1' && col2down == '3')
		fill_c_31_r(matrix, 1);
	if (col3up == '1' && col3down == '3')
		fill_c_31_r(matrix, 2);
	if (col4up == '' && col4down == '3')
		fill_c_31_r(matrix, 3);
	
	if (row1left == '3' && row1right == '1')
		fill_r_31(matrix, 0);
	if(row2left == '3' && row2right == '1')
		fill_r_31(matrix, 1);
	if(row3left == '3' && row3right == '1')
		fill_r_31(matrix, 2);
	if(row4left == '3' && row4right == '1')
		fill_r_31(matrix, 3);
		

	if (row1right == '1' && row1left == '3')
		fill_r_31_r(matrix, 0);
	if(row2right == '1' && row2left == '3')
		fill_r_31_r(matrix, 1);
	if(row3right == '1' && row3left == '3')
		fill_r_31_r(matrix, 2);
	if(row4right == '1' && row4left == '3')
		fill_r_31_r(matrix, 3);
		
		
		****************************

	
		
	while( i < 4) {
			while (j < 4)
			{
					printf("%c ", matrix[i][j]); 
					j++;
			}
			j=0;
			printf("%s", "\n"); 
			i++;
			
			

	}
	
	return (0);
}
