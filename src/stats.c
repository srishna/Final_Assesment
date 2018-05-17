/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <14th Apr 2018 >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)



void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
	printf("*****************ORIGINAL LIST********************\n");
	print_array(test,SIZE);	
	print_statistics(test,SIZE);
	
}

/* Add other Implementation File Code Here */
/*Find minimum number*/
unsigned char find_minimum(unsigned char* list, unsigned int size)
{
   unsigned int i = 1;
   unsigned char temp = *list;

	while(i < size)
	{
		if (temp > *(list+i))
		{
			temp = *(list + i);
		}
	i++;
	}
	printf("Minimum Number = %d\n", temp);
}

/*Find maximum number*/
unsigned char find_maximum(unsigned char* list, unsigned int size)
{
   unsigned int i = 1;
   unsigned char temp = *list;

	while(i < size)
	{
		if (temp < *(list+i))
		{
			temp = *(list + i);
		}
	i++;
	}
	printf("Maximum Number = %d\n", temp);
}

/*Find mean*/
unsigned char find_mean(unsigned char* list, unsigned int size)
{
   unsigned char i = 0;
   unsigned int temp = 0;


	while(i < size)
	{
	   temp += *(list + i++);
	}
	printf("Mean = %d\n", temp/size);
}

/*sort array*/
unsigned char sort_array(unsigned char* list, unsigned int size)
{
   unsigned char i = 0 ,j = 0;
   unsigned int temp = 0;
   unsigned char temp_list[size];  

	//copy contents to local array 
	while(i < size)
	{
		temp_list[i] = *(list + i++);
	}

	/*This is to allign numbers in descending order*/
	i = 0;
	while(i < size)
	{
		j = 0;
		while(j < (size-1))
		{	
			if(*(temp_list+j) < *(temp_list + j+1))
			{
								
				temp = *(temp_list+j);
				*(temp_list+j)  = *(temp_list + j + 1);
				*(temp_list + j +1) = temp;
			}
		j++;
		}
	i++;
	}
	printf("*****************DESCENDING ORDERED LIST********************\n");
	print_array(temp_list, size);

}

/*Find median*/
unsigned char find_median(unsigned char* list, unsigned int size)
{
   unsigned int middle = 0;
   unsigned int median = 0;
	
	sort_array(list,size);
	
	if(size%2 == 0)
	{
	   median = (*(list + middle) + *(list + middle + 1))/2;
	}
	else
	{
	   median = *(list + middle);
	}
	printf("Median = %d\n", median);
}
/*provide statistics*/

unsigned char print_statistics(unsigned char* list, unsigned int size)
{
	printf("*****************STATISTICS********************\n");
  find_minimum(list, size);
  find_maximum(list, size);
  find_mean(list, size);
  find_median(list, size);
}

/* print given array*/
unsigned char print_array(unsigned char* list, unsigned int size)
{
	unsigned int i = 0;

	while(i < size)
	{
		printf("%d\t", *(list + i++));
	}
	printf("\n");
}	

