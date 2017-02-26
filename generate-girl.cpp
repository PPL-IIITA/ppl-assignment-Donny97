#include<fstream>
#include<cstring>
using namespace std;
void generate_girl(){
  int i;
  char random[][20]={"Lore","Durelia","Delana","Donnette","Ashli","Precious","Jacquiline","Yang","Latoyia","Huong"};
  char name[20];
  int type, maal, dimaag, moneyreq, typereq; 
  ofstream myfile;
  myfile.open ("girl.txt");
  for( i = 0; i< 10; i++)
  {
  		type = rand() % 3 + 1;
  		maal = rand() % 10 + 1;
  		moneyreq = rand() % 45000 + 1;
  		dimaag = rand() % 10 + 1;
  		typereq = rand() % 10 + 1;
  		strcpy(name,random[i]);
  		myfile << name << " " << type << " " << moneyreq << " " << maal << " " << typereq << "\n";
  }
  myfile.close();
}
