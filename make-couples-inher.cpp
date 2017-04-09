#include <iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include "gift.cpp"
#include<fstream>
using namespace std;
void make_couples_inher(){
	Girl G[10];
	Boy B[20];
	char name[20];
	int compatibility[10];
    int type, maal, dimaag, moneyreq, typereq, budget, maalreq, cool; 
	int i = 0, j, couple[10]= {0}, check[20]= {0};
	
	
	
	
	ifstream myfile("girl.txt");
	if(myfile.is_open())
	{
		for( i =0; i< 10; i++)
			myfile >>  G[i].name >> G[i].type >> G[i].moneyreq >> G[i].maal >> G[i].typereq;
	}
	
	ifstream file("boy.txt");
	if(file.is_open())
	{
		for( i =0; i< 20; i++)
			file >>  B[i].name >> B[i].type >> B[i].budget >> B[i].cool >> B[i].maalreq >> B[i].dimaag;
	}
	
	
	for( i = 0; i <10 ; i++)
    {
    	for (j=0; j<20; j++)
		{
			if(G[i].moneyreq <= B[j].budget)
			{
				if(B[j].maalreq <= G[i].maal)
				{
					if(G[i].type == 1)
					{
						if(B[j].cool >= G[i].typereq)
							if(check[j] == 0)
							{
								couple[i] = j;
								check[j]++;
							}
					}
					
					if(G[i].type == 3)
					{
						if(B[j].dimaag >= G[i].typereq)
							if(check[j] == 0)
							{
								couple[i] = j;
								check[j]++;
							}
					}
					
					if(G[i].type == 2)
					{
						if(B[j].budget >= G[i].typereq)
							if(check[j] == 0)
							{
								couple[i] = j;
								check[j]++;
							}
					}
					
				}
			}
			
		
		}	
    	
	}
	for ( i=0; i<10; i++)
	{
		if(couple[i]!=0)
			printf("%s      %s\n",G[i].name,B[couple[i]].name);
	}

	ofstream coufile;
  coufile.open ("couple.txt");
  for( i = 0; i< 10; i++)
  {
  		if(couple[i]!=0)
  			coufile << G[i].name << " " << B[couple[i]].name << " \n";
  }
  coufile.close();
  
  
  	
	  
int couple_count, minIndex=0,moneySpent = 0,moneyLeft,maxGIndex=0;
	bool luxury_gift = false;
	Gift gifts[50];
	
	int total_cost[50] = {0};
	int total_value[50] = {0};
	for(i=0;i<10;i++)
	{
		moneySpent = 0;
		moneyLeft = B[couple[i]].budget;
		luxury_gift = false;
		if(i>=1)
		{
			for(j=0;j<50;j++)
			{
				if(gifts[j].used==0)
				{
					minIndex = j;
					break;
				}
			}
		}
		for(j=0;j<50;j++)
		{
			if(gifts[j].price<gifts[minIndex].price && gifts[j].used==0)
			{
				minIndex = j; 
			}
			if(gifts[j].price>gifts[maxGIndex].price && gifts[j].used==0)
			{
				maxGIndex = j;
			}
		}
		
		
		
		for(j=0;j<50;j++)
		{
			if(B[couple[i]].type == 1)
			{
				if(gifts[j].used == 1 || gifts[minIndex].price>B[couple[i]].budget || gifts[minIndex].price > moneyLeft || moneySpent > G[i].moneyreq)
					continue;
				else
				{
					if(gifts[minIndex].used == 0)
					{
						gifts[minIndex].used = 1;
						moneySpent += gifts[minIndex].price;
						moneyLeft -= gifts[minIndex].price;
						total_cost[i]+= gifts[minIndex].price;
						total_value[i]+=gifts[minIndex].value;
						cout<< "Couple "<<i<<": Gift of price "<<gifts[minIndex].price<<"and value "<<gifts[minIndex].value<<" was given by "<<B[couple[i]].name<<" to "<<G[i].name<<endl;
						cout<<"MISER\n";
					}

				}

			}
			else if(B[couple[i]].type == 2)
			{
				if(gifts[j].used == 1 || gifts[j].price>B[couple[i]].budget ||gifts[minIndex].price > moneyLeft || moneySpent >= G[i].moneyreq)
					continue;
				else
				{
					gifts[j].used = 1;
					moneySpent += gifts[j].price;
					moneyLeft -= gifts[j].price;
					total_cost[i]+= gifts[j].price;
					total_value[i]+=gifts[j].value;
					cout<< "Couple "<<i<<": Gift of price "<<gifts[j].price<<"and value "<<gifts[i].value<<" was given by "<<B[couple[i]].name<<" to "<<G[i].name<<endl;
					cout<<"GENEROUS\n";
				}
			}
			else
			{
				if(gifts[j].used == 1 || gifts[minIndex].price>B[couple[i]].budget || gifts[minIndex].price > moneyLeft || moneySpent > G[i].moneyreq)
					continue;
				else
				{
					if(gifts[j].type == 2 && luxury_gift == false)
					{
						gifts[j].used = 1;
						luxury_gift = true;
						moneySpent +=gifts[j].price;
						moneyLeft -= gifts[j].price;
						total_cost[i]+= gifts[j].price;
						total_value[i]+=gifts[j].value;
						cout<< "Couple "<<i<<": Gift of price "<<gifts[j].price<<"and value "<<gifts[i].value<<" was given by "<<B[couple[i]].name<<" to "<<G[i].name<<endl;
						cout<<"LUXURY\n";
					}
					else
					{
					gifts[j].used = 1;
					moneySpent += gifts[j].price;
					moneyLeft -= gifts[j].price;
					total_cost[i]+= gifts[j].price;
					total_value[i]+=gifts[j].value;
					cout<< "Couple "<<i<<": Gift of price "<<gifts[j].price<<"and value "<<gifts[i].value<<" was given by "<<B[couple[i]].name<<" to "<<G[i].name<<endl;
					cout<<"LUXURY\n";
					}

				}
			}
		}
	}
	int couple_happy[10]={0};
	for(i=0;i<10;i++)
	{
		if(G[i].type == 0) 
		{
		     G[i].happiness = log(total_cost[i] - moneyreq);
		
		}
		else if(G[i].type == 1)
		{
			G[i].happiness = (total_cost[i]-moneyreq) + total_value[i];
		}
		else
		{
			G[i].happiness = (int)exp((total_cost[i] - moneyreq)%5);
		}
		
		
		if(B[couple[i]].type == 0)
		{
			B[couple[i]].happiness = budget - total_cost[i];
		
	
		}
		else if (B[couple[i]].type == 1)
		{
			B[couple[i]].happiness = G[i].happiness;
		
		}	

		else
		{
			B[couple[i]].happiness = G[i].dimaag;
		}
		
		couple_happy[i] = B[couple[i]].happiness+G[i].happiness;
	
		
		
		compatibility[i] = (B[couple[i]].budget - G[i].moneyreq) + abs(B[couple[i]].cool - G[i].maal) + abs(G[i].dimaag - B[couple[i]].dimaag);
		
		
	}
	cout<<endl<<"2 Happiest couple are \n";
	int arr[10] = {0};
	int maxIndex = 0; 
	for(i=0;i<2;i++)
	{
		for(j=0;j<10;j++)
		{
			if(arr[j]==0)
			{
				maxIndex = j;
				break;
			}
		}
		for(j = 0;j<10;j++)
		{
			if(arr[j] == 0 && couple_happy[j] > couple_happy[maxIndex])
			{
				maxIndex = j;

			}
		}
		cout<<B[couple[maxIndex]].name <<" "<<G[maxIndex].name <<" "<<couple_happy[maxIndex]<<endl;
		arr[maxIndex] = 1;
	}
	cout<<endl;
	cout<<"2 Most Compatible couple are \n";
	
	arr[10] = {0};
	int  maxCIndex = 0; 
	for(i=0;i<2;i++)
	{
		for(j=0;j<10;j++)
		{
			if(arr[j]==0)
			{
				maxCIndex = j;
				break;
			}
		}
		for(j = 0;j<10;j++)
		{
			if(arr[j] == 0 && compatibility[j] > compatibility[maxCIndex])
			{
				maxCIndex = j;

			}
		}
		cout<<B[couple[maxCIndex]].name <<" "<<G[maxCIndex].name <<" "<<compatibility[maxCIndex]<<endl;
		arr[maxCIndex] = 1;
	}
  
  
  
}
