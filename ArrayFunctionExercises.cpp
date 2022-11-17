// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++:
// From control structures through objects. Pearson. 

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw, setprecision for output width
#include <ctime>    // To access random number generator
using namespace std;

// Global Constant Initialization
const string TITLE = "Array Function Exercises Program";
const string AUTHOR_LINE = "By Forrest Moulin";
const int ARRAY_SIZE = 10;

// Initialize global int array of size 10
int numbers[ARRAY_SIZE] = {10,20,18,14,12,16,10,20,16,14};

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
	cout << "Exercise # 1" << endl
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
	cout << "Exercise # 2" << endl
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
	cout << "Exercise # 3" << endl
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
	cout << "Exercise # 4" << endl
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
	cout << "Exercise # 5" << endl
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
* Array Function Exercises Program
* By Forrest Moulin
* 
* Original array:
* {10,20,18,14,12,16,10,20,16,14}
* 
* Exercise # 1
* -------------
* Squared array:
* {100,400,324,196,144,256,100,400,256,196}
* 
* Exercise # 3
* -------------
* Add the following number to each current number,
* except on the last number:
* {30,38,32,26,28,26,30,36,30,14}
* 
* Exercise # 4
* -------------
* Sum of all array numbers:
* 150
* 
* Exercise # 5
* -------------
* Largest of all original array numbers:
* 20
*/
