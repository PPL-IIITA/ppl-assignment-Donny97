#include <iostream>
#include<string.h>
#include"boy.h"
#include"girl.h"
#include<math.h>
#include<stdlib.h>
#include"generate-boy.cpp"
#include"generate-girl.cpp"
#include"generate-gifts.cpp"
#include"make-couples-alter.cpp"
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
	make_couples_alter();
	return 0;
}
