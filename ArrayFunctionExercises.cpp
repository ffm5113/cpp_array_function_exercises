// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++:
// From control structures through objects. Pearson. 

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw, setprecision for output width
#include <ctime>    // To access random number generator
using namespace std;

// Global Constant Initialization
const string TITLE = "Array Exercises Program";
const string AUTHOR_LINE = "By Forrest Moulin";
const int ARRAY_SIZE = 10;

// Initialize global int array of size 10
int numbers[ARRAY_SIZE] = {5,4,2,7,6,8,5,2,8,14};

// Function prototypes to notify compiler
void printOriginal(const int  numbersPassed[]);
void squareEachNum(const int numbersPassed[]);
void addRandomNum(const int numbersPassed[]);
void addFollowingNum(const int numbersPassed[]);
void sumAllNums(const int numbersPassed[]);
void displayLargestNum(const int numbersPassed[]);
void placeCommas(int i);

int main()
{
	// Seed the random number generated
	// using the current time
	srand(time(NULL));

	cout << TITLE << endl
		<< AUTHOR_LINE << endl << endl;
	
	// Call functions using numbers array,
	// which is passed as const (read-only)
	printOriginal(numbers);
	squareEachNum(numbers);
	addFollowingNum(numbers);
	sumAllNums(numbers);
	displayLargestNum(numbers);
}
void printOriginal(const int numbersPassed[])
{	// Print original read-only array
	cout << "Original array:" << endl
		<<"{";
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << numbersPassed[i];
		// Comma only after first 9 ints
		placeCommas(i);
	}
	cout << "}" << endl << endl;
}
// Exercise 1: Square each int
void squareEachNum(const int numbersPassed[])
{
	cout << "Excercise # 1" << endl
		<< setw(14) << setfill('-') << " " << endl
		<< "Squared array:" << endl
		<< "{";
	// Make a array that will copy read only
	int numbersCopy[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++)
	{	// Change arrange copy value to square of int
		numbersCopy[i] = 
			numbersPassed[i] * numbersPassed[i];
		cout << numbersCopy[i];
		placeCommas(i);
	}
	cout << "}" << endl << endl;
}
// Exercise 2: Add random int (1-10) to each int
void addRandomNum(const int numbersPassed[])
{
	cout << "Excercise # 2" << endl
		<< setw(14) << setfill('-') << " " << endl
		<< "Added random number array:" << endl
		<< "{";
	// 10 options for random # (0-9) + 1 = 1-10
	int randomNum = rand() % 10 + 1;
	// Make a array that will copy read only
	int numbersCopy[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++)
	{	// Change array copy value to sum with random int
		numbersCopy[i] =
			numbersPassed[i] + randomNum;
		cout << numbersCopy[i];
		placeCommas(i);
	}
}
// Exercise 3: Adding the following int to the current int,
// except for the last int
void addFollowingNum(const int numbersPassed[])
{
	cout << "Excercise # 3" << endl
		<< setw(14) << setfill('-') <<  " " << endl
		<< "Add the following number to each current number,"
		<< endl << "except on the last number:" << endl << "{";
	int numbersCopy[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (i < 9)
		{
			numbersCopy[i] =
				numbersPassed[i] + numbersPassed[i + 1];
		}
		else {
			numbersCopy[i] = numbersPassed[i];
		}
		cout << numbersCopy[i];
		placeCommas(i);
	}
	cout << "}" << endl << endl;
}
// Exercise 4: Sum all the array ints
void sumAllNums(const int numbersPassed[])
{
	cout << "Excercise # 4" << endl
		<< setw(14) << setfill('-') << " " << endl
		<< "Sum of all array numbers:" << endl;
	int sum = 0;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		sum += numbersPassed[i];
	}
	cout << sum << endl << endl;
}
// Exercise 5: Display the largest int of the array
void displayLargestNum(const int numbersPassed[]) {
	cout << "Excercise # 5" << endl
		<< setw(14) << setfill('-') << " " << endl
		<< "Largest of all original array numbers:" << endl;
	int largestNum;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == 0)
		{	// Set first number to largest
			largestNum = numbersPassed[i];
		}	// Find largest on each iteration
		else if (numbersPassed[i] > largestNum)
		{
			largestNum = numbersPassed[i];
		}
	}
	cout << largestNum << endl;
}
// Comma only after first 9 ints
void placeCommas(int i)
{
	if (i < 9)
	{
		cout << ",";
	}
}
/*
* CONSOLE OUTPUT
* Array Exercises Program
* By Forrest Moulin
*
* Original array:
* {5,4,2,7,6,8,5,2,8,14}
*
* Excercise # 1
* -------------
* Squared array:
* {25,16,4,49,36,64,25,4,64,196}
*
* Excercise # 3
* -------------
* Add the following number to each current number,
* except on the last number:
* {9,6,9,13,14,13,7,10,22,14}
*
* Excercise # 4
* -------------
* Sum of all array numbers:
* 61
*
* Excercise # 5
* -------------
* Largest of all original array numbers:
* 14
*/
