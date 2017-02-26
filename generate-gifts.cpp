#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "gift.h"
using namespace std;

void generate_gift()
{
	srand(time(NULL));
	Gift gift[50];
	int i;

	for(i=0;i<50;i++)
	{
		gift[i].price = rand() % 2000 +1;
		gift[i].value = rand() % 2000 +1;
		gift[i].type = rand() % 3 + 1;
		gift[i].used = 0;
		if(gift[i].type == 1)
		{
			gift[i].lux_rating = 0;
			gift[i].util_value = 0;
			gift[i].util_class = 0;
			gift[i].diff = 0;
		}
		else if(gift[i].type == 2)
		{
			gift[i].lux_rating = rand() % 5 + 1;
			gift[i].util_value = 0;
			gift[i].util_class = 0;
			gift[i].diff = rand() % 5 + 1;
		}
		else 
		{
			gift[i].lux_rating = 0;
			gift[i].util_value = rand() % 5 + 1;
			gift[i].util_class = rand() % 5 + 1;
			gift[i].diff = 0;
		}
	}
	
	ofstream myfile ("gift.txt");
	for(i=0;i<50;i++)
	{
		myfile << gift[i].price<<" "<<gift[i].value<<" "<<gift[i].type<<" "<<gift[i].lux_rating<<" "<<gift[i].diff<<" "<<gift[i].util_value<<" "<<gift[i].util_class<<" "<<gift[i].used<<endl;
	}

	myfile.close();
}
