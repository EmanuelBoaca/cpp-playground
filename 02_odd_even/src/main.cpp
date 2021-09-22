#include <stdio.h>

#include <iostream>
#include <string>

void printOddOrEven(int number)
{
	if (number % 2 == 0)
	{
		printf("EVEN\n");
	}
	else
	{
		printf("ODD\n");
	}
}
bool isNumber(char* stringToBeCheck)
{
	int stringLenght = strlen(stringToBeCheck);
	if (isdigit(stringToBeCheck[0]) || stringToBeCheck[0] == '-')
		for (int index = 1; index < stringLenght; index++)
		{
			if (!isdigit(stringToBeCheck[index]))
				return false;
		}
	else return false;
	return true;
		
}
int main(int argc, char *argv[])
{
	int number = -13;

	// What is this program expected to do?
	// - Shows whether an argument is an ODD or EVEN number.
	// How to launch it?
	// - Execute the binary and pass a parameter to it?
	// - E.g. Open CMD in bin/Debug or bin/Release
	//		  02_odd_even.exe 1		=> Output: ODD
	//		  02_odd_even.exe 2		=> Output: EVEN
	//		  02_odd_even.exe 		=> Output: No program arguments found.
	//		  02_odd_even.exe ABC   => Undefined output (do whatever).
	//		

	// Make sure there are some program arguments available.
	if (argc <= 1)
	{
		printf("No program arguments found.\n");
		return 0;
	}
	
	// TODO(Gusti): i don't know why this doesn't work, but someone please FIX it.
	// --------------- start

	// Get the first argument
	char* firstArgm = argv[1];
//	std::string argumentAsString = argv[1];
//	const char* argumentAsCharArray = argumentAsString.c_str();

	//number = argv[1]; // No
	//should use atoi?
	// or std::stoi?

	//chech if first artgument is a number
	if (!isNumber(firstArgm))
	{
		std::cout << "NAN";
		return 0;
	}
	number = atoi(firstArgm);
	
	//std::cout << argumentAsString << std::endl; // i think this should be removed

	// --------------- stop

	printOddOrEven(number);

	return 0;
}