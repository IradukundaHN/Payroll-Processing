
//Header files
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Global variables
const int NUM = 6;

//Functions prototypes
int getId();
int binarySearch(long int[], int, int);
int searchList(long int[], int, int);
void selectionSort(long int[], double[], double[], double[], int);


int main()
{
	long int empId[NUM]={ 5658845, 4520125, 7895122, 8777541, 8451277, 1302850 };
	double hours[NUM] = { 40, 25.25, 30, 10, 50, 35.20 };
	double payRate[NUM] = { 8, 9.25, 10.50, 12, 10.20, 7.50 };
	double wages[NUM];
	string fileName;

	cout << "\t\tPAYROLL PROCESSING" << endl;

	cout << "Enter the name of the input file: ";
	getline(cin, fileName);
	ifstream inFile;
	inFile.open(fileName);

	if (!inFile)
		cout << "Error opening!";
	else
	{
		cout << "Enter the name of the outpout file: ";
		getline(cin, fileName);
		ofstream outFile;
		outFile.open(fileName);


		outFile << "\t\tPAYROLL PROCESSING" << endl;
		outFile << "\nEmployees in order entered: " << endl;
		outFile << "\nEmployee Number" << "\t" << "   Hours worked" << "\t\t" << "Payrate per hour" << "\t" << "Wages" << endl;
		
		for (int index = 0; index<NUM; index++)
			outFile << setw(10) << empId[index] << fixed << showpoint << setprecision(2) << setw(18) << hours[index] << setw(23) << payRate[index] << setw(18) << (wages[index] = hours[index] * payRate[index]) << endl;

		int ID2 =getId();
		//call function linear search
		int result2 = searchList(empId, NUM, ID2);
		if (result2 == -1 || result2>20) //value not found 
			cout << "The number you entered is invalid.";
		else
		{
				cout << "The number you entered you entered is valid.";
				cout << "\nEmployee " << ID2 << " worked " << fixed << showpoint << setprecision(2) << hours[result2] << " hours " << "at $" << payRate[result2] << " per hour and earned " << "$" << fixed << showpoint << setprecision(2) << wages[result2];		
		}

		int ID = getId();
		selectionSort(empId, hours, payRate, wages, NUM);	
		int result = binarySearch(empId, NUM, ID);
		if (result ==-1 || result>20) //value not found 
			cout << "The number you entered is invalid.";
		else
		{
				cout << "The number you entered you entered is valid.";
				int b = result;
				cout << "\nEmployee " << ID << " worked " << hours[b] << " hours " << "at $" << payRate[b] << " per hour and earned " << "$" << fixed << showpoint << setprecision(2) << wages[b];

		}
		

		outFile << "\nEmployee numbers in ascending order: " << endl;
		outFile << "\nEmployee Number" << "\t" << "   Hours worked" << "\t\t" << "Payrate per hour" << "\t" << "Wages" << endl;

		//call function void selectionSort

		selectionSort(empId, hours, payRate, wages, NUM);
		for (int count = 0; count < NUM; count++)
		{
			outFile << setw(10) << empId[count] << fixed << showpoint << setprecision(2) << setw(18) << hours[count] << setw(23) << payRate[count] << setw(18) << (wages[count] = hours[count] * payRate[count]) << endl;
		}

		outFile << "\nProgrammer: " << name;

		outFile.close();
	}

	cout << "\nProcessing complete.\n";

	return 0;
}

/******************************************************
*The function getId does not take any parameter       *
*It prompts the user the ID number                    *
*It return the ID number as an integer                *
*******************************************************/
int getId()
{
	int empId;
	cout << "\nEnter an employee number for your search: ";
	cin >> empId;

	return empId;
}


/*****************************************************************************************
* The function binarySearch use the linear search algorithm to search the employee ID    *
* It takes three parameters, the array to store the employee ID numbers as long integer, *
   the size of the array, and the value in search                                        *
*It returns position as an integer once found                                            *
******************************************************************************************/

int binarySearch(long int array[], int size, int value)
{
	int first = 0;
	int last = size-1;
	int middle;
	int position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (array[middle] == value)
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	 }
	 return position;
}

/*****************************************************************************************
* The function searchList use the linear search algorithm to search the employee ID      *
* It takes three parameters, the array to store the employee ID numbers as long integer, *
   the size of the array, and the value in search                                        *
*It returns position as an integer once found                                            *
******************************************************************************************/

int searchList(long int list[], int size, int value)
{
	int index = 0;
	int position = -1;
	bool found = false;
	while (index < size && !found)
	{
		if (list[index] == value)
		{
			found = true;
			position = index;
		} 
		index++;
	}
	return position;
}


/**************************************************************************************
* The selectionSort function use the selection sort algorithm                         *
* It takes five parameters                                                            *
* It sorts in ascending order the information of the payroll based on the employee ID *
***************************************************************************************/

void selectionSort(long int empId[], double hours[],double payRate[],double wages[],int size)
{
	int minindex, startScan;
	long int minValue1;
	double minValue2, minValue3, minValue4;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minindex = startScan;
		minValue1 = empId[startScan];
		minValue2 = hours[startScan];
		minValue3 = payRate[startScan];
		minValue4 = wages[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (empId[index] < minValue1)
			{
				minValue1 = empId[index];
				minindex = index;

				minValue2 = hours[index];
				minindex = index;

				minValue3 = payRate[index];
				minindex = index;

				minValue4 = wages[index];
				minindex = index;

			}
		}
		empId[minindex] = empId[startScan];
		empId[startScan] = minValue1;

		hours[minindex] = hours[startScan];
		hours[startScan] = minValue2;

		payRate[minindex] = payRate[startScan];
		payRate[startScan] = minValue3;

		wages[minindex] = wages[startScan];
		wages[startScan] = minValue4;
		
	}
}

