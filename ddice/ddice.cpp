// ddice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "die.h"

void main2();

int main()
{
	printf("Dice sim of two dice rolled repeatedly.");
	main2();
    return 0;
}

void main2()
{
	printf("random_integer");
	//printf("done 123\r\n");
	die d1 = die();
	die d2 = die();

	//array, smallest possible
	//sum of dice range from 2 to 12, which is 11 values
	
	// Sum = 2 stored in rollValueArray[0]
	// Sum = 3 stored in rollValueArray[1]
	// Sum = 4 stored in rollValueArray[2]
	//...
	// Sum = 12 stored in rollValueArray[10]
	// so pattern is sum -2 = index
	// Sum = i stored in rollValueArray[i-2]
	// index goes from zero to 10, values 2 to 12

	unsigned int rollValueArray[11];
	//Init array
	for (int possiblesums = 0; possiblesums < 12; possiblesums++)
	{
		//without initialization, the arrays have values.
		//for example = -858993460
		//FFFFFFFF CCCCCCCC
		rollValueArray[possiblesums] = 0;
		printf("Init array index %i (Sum = %i ) value = %i\r\n", possiblesums, possiblesums+2, rollValueArray[possiblesums]);
	}

	//required number of rolls
	int NUM_ROLLS = 36000;

	//roll 20 times
	int sumOfDice = 0;
	for (int rollNum = 0; rollNum < NUM_ROLLS; rollNum++) {
		int value1 = d1.roll();
		//printf("die 1 rolled a :%i\r\n", value1);

		int value2 = d2.roll();
		//printf("die 2 rolled a :%i\r\n", value2);


		sumOfDice = value1 + value2;
		//printf("sum %i\r\n", sumOfDice);

		if ((sumOfDice) == 0)
		{
			printf("BAD VALUE\r\n");

		}
		if ((sumOfDice) > 12)
		{
			printf("BAD VALUE\r\n");
		}

		//increment array value, index is zero based and sum starts at 2.
		rollValueArray[sumOfDice-2] += 1;

		//printf("-\r\n");
	}

	printf("r\n");
	printf("Distribution of values \r\n");
	for (int possiblesums = 0; possiblesums < 11; possiblesums++)
	{
		printf("Num of times sum=%i was rolled = %i.\r\n", possiblesums+2, rollValueArray[possiblesums]);
	}

	return;

}
