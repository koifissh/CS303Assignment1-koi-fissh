#include "function.h"
#include <iostream>
#include <string>
#include <array>
#include <fstream>

using namespace std;

/*
1) Check if a certain integer exists in the array if the number is present return the index where the
number is present.

2) A function that can modify the value of an integer when called with the index of the integer in
the array and return the new value and old value back to the user.

3) A function that adds a new integer to the end of the array

4) A function which intakes an index of an array and replaces the value with either 0 or removes
the integer altogether.

*/

//Displays Menu to use functions
void menu(int arr[], int& arrSize) {
    string userInput = " ";
    while (userInput != "Q") {
        cout << endl;
        cout << "C - Check if an integer exist in the array" << endl
                << "M - Modify a value of an integer on an index" << endl
                << "A - Add a new integer to the end of the array" << endl
                << "R - Remove an index of the array" << endl
                << "P - Output the array" << endl
                << "Q - Quit" << endl;
        cout << "Enter an input: ";
        cin >> userInput;

        switch (toupper(userInput[0])) {
        case 'C':
            //Check Array Function
            checkArr(arr, arrSize);
            printArr(arr, arrSize);
            break;
        case 'M':
            //Modify Array Function
            modifyArr(arr, arrSize);
            printArr(arr, arrSize);
            break;
        case 'A':
            //Pushback Array Function
            newArr(arr, arrSize);
            printArr(arr, arrSize);
            break;
        case 'R':
            //Delete index within Array Function
            delArr(arr, arrSize);
            printArr(arr, arrSize);
            break;
        case 'P':
            //Print Array Function
            printArr(arr, arrSize);
            break;
        default:
            if (userInput != "Q") {
                cout << "Not a valid input - Enter another input: " << endl;
                break;
            }
            
        }

    }
    if (userInput == "Q") {
        exit(0);
    }

}


//Print Array
void printArr(int arr[], int& arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Array Size: " << arrSize << endl;
}

//Check integer within array
void checkArr(int arr[], int& arrSize) {
    bool numCheck = false;
    string userInput = "Error";
    int userNum;

    while (userInput == "Error") {
        try {
            cout << "Type a number to search: ";
            cin >> userInput;
            userNum = stoi(userInput);
        }
        catch (...) {
            cout << "Error - Not a valid input" << endl;
            userInput = "Error";
        }
    }
    

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == userNum) {
            cout << "Found " << arr[i] << " at index " << i << endl;
            numCheck = true;
        }
    }
    if (numCheck == false) {
        cout << "The number: " << userInput << " does not exist within the array" << endl;
    }

}

//Modify an index within the array
void modifyArr(int arr[], int& arrSize) {
    string userInput = "-1";
    string userNum;
    bool numCheck = false;
    int userIndex;

        while (stoi(userInput) > (arrSize-1) || stoi(userInput) < 0) {
            try {
                cout << "Type a valid index position 0-" << (arrSize - 1) << " to replace: ";
                cin >> userInput;
                userIndex = stoi(userInput);
            
            }
            catch(...){
                cout << "There was an error in your input" << endl;
                userInput = "-1";

            }
          
        }

        for (int i = 0; i < arrSize; i++) {
            if (i == userIndex) {
                cout << "Found " << arr[i] << " at index " << i << endl;
                while (numCheck == false) {
                    try {

                        cout << "What number would you like to replace it with: ";
                        cin >> userNum;

                        cout << "Old Value: " << arr[i] << endl;
                        arr[i] = stoi(userNum);
                        cout << "New Value: " << arr[i] << endl;
                        numCheck = true;

                    }
                    catch (...) {
                        cout << "There was an error in your input" << endl;
                        numCheck = false;
                    }
                }
            }
        }

}

//Adds new index to array
void newArr(int arr[], int& arrSize) {
    string userInput;
    arrSize = arrSize + 1;
    bool numCheck = false;
    int* array = new int[arrSize];
    delete[] array;


    for (int i = 0; i < arrSize; i++) {
        if (i == (arrSize - 1)) {
            while (numCheck == false) {
                try {
                    cout << "What number would you like to add: ";
                    cin >> userInput;
                    arr[i] = stoi(userInput);
                    numCheck = true;
                }
                catch (...) {
                    cout << "There was an error in your input" << endl;
                    numCheck = false;
                }

            }
        }

    }

}

//Deletes an index from the array
void delArr(int arr[], int& arrSize) {
    int userIndex;
    string userInput = "-1";
    int origSize = arrSize;

    if (arrSize > 0) {

        while (stoi(userInput) > (arrSize - 1) || stoi(userInput) < 0) {
            try {
                cout << "Type a valid index position 0-" << (arrSize - 1) << " to delete: ";
                cin >> userInput;
                userIndex = stoi(userInput);
            }
            catch (...) {
                cout << "There was an error in your input - Enter within the valid range" << endl;
                userInput = "-1";
                arrSize = origSize;
            }

        }

        arrSize = arrSize - 1;
        for (int j = userIndex; j < arrSize; j++)
            arr[j] = arr[j + 1];

        int* array = new int[arrSize];
        delete[] array;


    }
    else {
        cout << "Array is empty" << endl;
    }

}

//Reads in data from input file
void loadArr(int arr[], int& arrSize) {
    fstream fin;
    fin.open("input.txt");

    string row;
    int numInput = 0;
    while (fin.good()) {

        fin >> numInput;
        arrSize = arrSize + 1;
        int* array = new int[arrSize];

        if (arrSize > 0) {
            arr[arrSize - 1] = numInput;
        }

    }

    fin.close();
}
