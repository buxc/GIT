#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <map>
#include <time.h>

using namespace std;
/*
0 = Vasili
1 = Dimit
2 = Peter
3 = John
4 = Josh
5 = Chris
*/
int main()
{
	/*set up map of names to numbers*/
	map<int, string> map;
	map[0] = "Vasili";
	map[1] = "Dimit";
	map[2] = "Peter";
	map[3] = "John";
	map[4] = "Josh";
	map[5] = "Chris";
	int names[6] = {0,1,2,3,4,5};
	int teams[6] = {0};
	int index;
	int counter = 0; 
	bool condition = true;
	srand(time(NULL));
	while(condition)
	{
		index = rand() % 6;
		if(names[index] != -1)
		{
			teams[counter] = index;
			names[index] = -1;
			counter++;
		}
		if(counter == 6)
		{	
			condition = false;
		}
	}
	/*get input from user*/
	cout << "How many teams, 2 or 3?" << endl;	
	int answer;
	cin >> answer;
	if(answer == 2)
	{
		/*output teams. First 3 are team 1 + second 3 are team 2*/
		cout << "Team 1:" << endl;
		for(int i = 0; i < 3; i++)
		{
			cout <<'\t'<< map[teams[i]] << endl;
		}
		cout << endl << "Team 2:" << endl;
		for(int i = 3; i < 6; i++)
		{
			cout <<'\t'<<map[teams[i]] << endl;
		}
		cout << endl;
	}
	else if(answer == 3)
	{
		cout << "Team 1:" << endl;
		for(int i = 0; i < 2; i++)
		{
			cout <<'\t' << map[teams[i]] << endl;
		}
		cout << endl << "Team 2:" << endl;
		for(int i = 2; i < 4; i++)
		{
			cout <<'\t' << map[teams[i]] << endl;
		}
		cout << endl << "Team 3:" << endl;
		for(int i = 4; i < 6; i++)
		{
			cout <<'\t' << map[teams[i]] << endl;
		}
	}
	else
	{
		cout << "Please enter either 2 or 3 only." << endl;
	}

	
}
