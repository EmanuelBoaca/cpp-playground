#include <iostream>
void showArguments(int nrArg, char* argumentList[])
{
	for (int i = 1; i < nrArg; i++)
	{
		std::cout << argumentList[i] << std::endl;
	}
}
int main(int argn, char* argv[])
{
	showArguments(argn, argv);
	return 0;
}