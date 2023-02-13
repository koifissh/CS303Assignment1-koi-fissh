#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "function.h"

using namespace std;


int main() {

	//Creeates an array
	int numSize = 0;
	int numArr[1];

	//Reads input from input.txt
	loadArr(numArr, numSize);

	//Prints the array from input.txt
	printArr(numArr, numSize);

	//Displays menu to access functions
	menu(numArr, numSize);


}