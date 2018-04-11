#include "stdafx.h"
#include "die.h"

#include "stdio.h"
#include <iostream> 
//#include "stdafx.h"
#include <ctime>
#include <cstdlib>

die::die()
{
}


die::~die()
{
}

int die::roll()
{
	//printf("time = :%i\r\n", timeval);


	int random_integer = 0;
	int lowest = 1, highest = 6;
	int range = (highest - lowest) + 1;

	int random_num = 1 + rand() % 6;
	//printf("random_num = :%i\r\n", random_num);

	//for (int index = 0; index < 20; index++) {	
	//	random_num = 1 + rand() % 6;
	//	printf("random_num = :%i\r\n", random_num);
	//}
	return random_num;
}