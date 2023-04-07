/*
	Title:  	variableAssignment.cpp
	Author:  	April Crockett
	Date:  		5-30-2017
	Purpose:  	Example for assignment statements
*/
#include<iostream>
using namespace std;

int main()
{
	int number = 5; //initialization statement
	int length(20); //another way to initialize a variable
	int width, height, depth = 2, num = 48;

	width = 47; //assignment statement
	height = 28; //assignment statement
	cout << endl << "The value of number is "<< number << endl;
	cout << "Width: " << width << ", Length: " << length;
	cout << ", Height: " << height << ", Depth: " << depth << endl;
	
	cout << "The value of num is: " << num << endl;
	num = 7; //changing the value in num
	cout << "The value of num is: " << num << endl;
	
	return 0;
}


















