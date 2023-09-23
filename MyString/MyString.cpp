#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

#include "MyString.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

//Creates a string of 80 characters
MyString::MyString() {
	length = 80;
	str = new char[length+1];
}

//Creates a string of arbitrary size
MyString::MyString(int size) {
	length = size;
	str = new char[length + 1];

}
//Creates a string and initializes it with the string from the user
MyString::MyString(const char* input) {
	length = strlen(input) + 1;
	str = new char[length];
	strcpy_s(str, length, input);
}

//Get string
char* MyString::GetStr()
{
	return this->str;
}

//Enter string
void MyString::EnterString()
{
	char tempStr[10000];
	cout << "Enter string: ";
	cin.ignore();
	cin.getline(tempStr, sizeof(tempStr));
	this->length = strlen(tempStr) + 1;
	this->str = new char[length];
	strcpy_s(str, length, tempStr);
}

//Print string
void MyString::PrintString()
{
	cout << "(your string):  " << str << endl;
	
}

//copy constructor
MyString::MyString(const MyString& str1)
{
	length =  str1.length;
	str = new char[strlen(str1.str) + 1];
	strcpy_s(str, strlen(str1.str)+1, str1.str);
}

//find substring in string
void MyString::AskStrToCheck()
{
	const char* p;
	char subs[50];
	cout << "Enter substring: ";
	cin >> subs;
	p = strstr(str, subs);
	MyStrStr(str, p);
}

bool MyString::MyStrStr(const char* str, const char* p)
{
	
	if (p) {
		cout << "True!" << endl;
		return true;
	}
	else {
		cout << "False!" << endl;
		return false;
	}
	
}


//find ch in string
int MyString::MyChr(char c)
{
	for (int i = 0; i < length; i++) {
		if (str[i] == c) {
			cout << "Index: ";
			return i;
		}
	}
	return -1;
}

//return string length
int MyString::MyStrLen()
{
	int len = strlen(str) + 1;
	return len;
}

//delete user char
void MyString::MyDelChr(char ch)
{
	int count = 0;
	for (int i = 0; i < this->length; i++) {
		if (this->str[i] == ch) {
			count++;
		}
	}
	//cout << "Count: " << count;

	int len = this->length - count;
	char* rez = new char[len+1];
	//cout << "Len(7): " << len+1;

	for (int i = 0, j = 0; i < this->length+1; i++) {
		if (this->str[i] != ch) {
			rez[j] = this->str[i];
			j++;
		}
	}
	delete[]str;	
	length = len+1;
	str = new char[length+1];
	str = rez;
}

//compare strings
int MyString::MyStrCmp(MyString& b)
{
	if (strcmp(this->str, b.str) == -1) {
		cout << "first line is less than second!" << endl;
		return -1;
	}
	else if (strcmp(this->str, b.str) == 1) {
		cout << "the first line is bigger than the second line!" << endl;
		return 1;
	}
	else if (strcmp(this->str, b.str) == 0) {
		cout << "the lines are the same!" << endl;
		return 0;
	}
}

//operator + overloading
MyString MyString::operator+(const MyString& b)
{
	MyString rez;
	int len1 = this->length - 1;
	int len2 = b.length - 1;
	rez.length = len1 + len2;
	rez.str = new char[len1 + len2 + 1];
	strcpy(rez.str, this->str);
	strcat(rez.str, b.str);
	return rez;
}

//operator > overloading
bool MyString::operator>(MyString& b)
{
	if (strcmp(this->str, b.str) == 1) {
		return true;
	}
	return false;
}

//operator < overloading
bool MyString::operator<(MyString& b)
{
	if (strcmp(this->str, b.str) == -1) {
		return true;
	}
	return false;
}

//operator == overloading
bool MyString::operator==(MyString& b)
{
	if (strcmp(this->str, b.str) == 0) {
		return true;
	}
	return false;
}



//	Destructor
MyString::~MyString() {
	delete[] this->str;
}

