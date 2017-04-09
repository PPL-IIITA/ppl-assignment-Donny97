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
#include"commit-boy-array.cpp"
#include"commit-boy-soarray.cpp"
#include"commit-boy-hash.cpp"
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
	make_couples();
	int c;
	printf("Enter your choice:\n");
	printf("1 for array\n");
	printf("2 for sorted array\n");
	printf("3 for hash table\n");
	scanf("%d",&c);
	if( c == 1 )
		commit_boy_array();
	else if( c == 2 )
		commit_boy_soarray();
	else if( c == 3 )
		commit_boy_hash();
	return 0;
}
