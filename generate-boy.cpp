#include<fstream>
#include<cstring>
using namespace std;
void generate_boy(){
  int i;
  char random[][20]={"Salvatore","Eusebio","Isiah","Christopher","James","Derick","Bernard","Robbie","Tony","Cesar","Werner","Faustino","Alfonso","Abe","Sandy","Perry","Lucio","Dong","Michale","Coleman"};	
  char name[20];
  int type, cool, dimaag, budget, maalreq; 
  std::ofstream myfile;
  myfile.open ("boy.txt");
  for( i = 0; i< 20; i++)
  {
  		type = rand() % 3 + 1;
  		cool = rand() % 10 + 1;
  		budget = rand() % 50000 + 1;
  		dimaag = rand() % 10 + 1;
  		maalreq = rand() % 10 + 1;
  		std::strcpy(name,random[i]);
  		myfile << name << " " << type << " " << budget << " " << cool << " " << maalreq << " " << dimaag << "\n";
  }
  myfile.close();
}

