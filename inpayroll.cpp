//inpayroll file
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	
	const int SIZE = 6;
	long int empId[SIZE] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850 };
	double hours[SIZE] = { 40, 25.25, 30, 10, 50, 35.20 };
	double payRate[SIZE] = { 8, 9.25, 10.50, 12, 10.20, 7.50 };
	int last = -1;
	ofstream outputFile;
	outputFile.open("inpayroll.txt");


	for (int index = 0; index < SIZE; index++)
	{
		outputFile << empId[index] << " " << hours[index] << " " << payRate[index] << endl;
	}
	outputFile << last;
	outputFile.close();

	return 0;
}