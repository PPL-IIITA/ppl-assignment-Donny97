#include <iostream>
#include<string.h>
#include"boy.h"
#include"girl.h"
#include<math.h>
#include<stdlib.h>
#include"generate-boy.cpp"
#include"generate-girl.cpp"
#include"generate-gifts.cpp"
#include"make-couples.cpp"
#include"breakup_couples.cpp"
#include<fstream>
using namespace std;
void generate_girl();
void give_gifts();
void generate_boy();
void make_couples();
int main( ) {
	generate_girl();
	generate_boy();
	generate_gift();
	int t,i;
	printf("No. of Gift giving meetings in a month:\n");
	scanf("%d",&t);
	make_couples();
	for( i=0; i<t-1; i++ )
	{
		breakup_couples();	
	}
	return 0;
}
