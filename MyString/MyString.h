#pragma once
#include <iostream>

using namespace std;
class MyString
{
private:
	char* str;
	int length;
	
public:
	MyString();	
	MyString(int size);
	MyString(const char* input);
	char* GetStr();


	void EnterString();
	void PrintString();
	
	MyString(const MyString& str1);
	void AskStrToCheck();
	bool MyStrStr(const char* str, const char* p);
	int MyChr(char c);	//find ch in string
	int MyStrLen();		//get length of string
	void MyDelChr(char ch);
	int MyStrCmp(MyString& b);

	MyString operator+(const MyString& b);	//strcat (str1 + str2)
	bool operator>(MyString& b);		//>
	bool operator<(MyString& b);		//<
	bool operator ==(MyString& b);		//==


	~MyString();

};

