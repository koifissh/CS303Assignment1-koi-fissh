#pragma once


/*
1) Check if a certain integer exists in the array if the number is present return the index where the
number is present.

2) A function that can modify the value of an integer when called with the index of the integer in
the array and return the new value and old value back to the user.

3) A function that adds a new integer to the end of the array

4) A function which intakes an index of an array and replaces the value with either 0 or removes
the integer altogether.

*/

void menu(int arr[], int& arrSize);
//PRE: Displays Menu and takes in userInput
//POST: Executes the appropriate function


//Arr and arrSize could be private data within a potential vector class
//These functions could be public within a potential vector class

void printArr(int arr[], int& arrSize);
//PRE: UserInput: P character input
//POST: Prints the array

void checkArr(int arr[], int& arrSize);
//PRE: Ask the user if a certain number exist within the array
//POST: Outputs if the number exist within the array.

void modifyArr(int arr[], int& arrSize);
//PRE: Asks the user which index to modify
//POST: Changes the index number within the array

void newArr(int arr[], int& arrSize);
//PRE: Asks user what nummber to add to array
//POST: Adds a new index to the array

void delArr(int arr[], int& arrSize);
//PRE: Ask the user which index to remove
//POST: Removes index and prints array

void loadArr(int arr[], int& arrSize);
//PRE: Takes input.txt as input
//POST: Creates an array based on the input
