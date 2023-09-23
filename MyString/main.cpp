#include "MyString.h"
#include <iostream>
using namespace std;

int main() {
	MyString str1("Hello");

	//check: copu construct
	MyString str2 = str1;
	cout << "Str1: ";
	str1.PrintString();
	cout << "Str2: ";
	str2.PrintString();
	cout << "------------------------------" << endl;

	//check: find substring in string (if true - the substring is in string)
	str1.AskStrToCheck();
	cout << "------------------------------" << endl;

	//check: find char
	char c;
	cout << "Enter ch to find it index: ";
	cin >> c;
	cout << str1.MyChr(c) << endl;
	cout << "------------------------------" << endl;
	
	//check: str length
	cout << "Length str1 (with 0 terminator): " << str1.MyStrLen() << endl;
	cout << "------------------------------" << endl;

	//check: concatenate strings
	cout << "Concatenate str1 + str2" << endl;
	MyString rez = str1 + str2;
	rez.PrintString();
	cout << "------------------------------" << endl;

	//check: delete user ch
	char ch;
	cout << "Enter char that you want to delete: ";
	cin >> ch;
	rez.MyDelChr(ch);
	rez.PrintString();
	cout << "------------------------------" << endl;

	//check: enter + print user string
	cout << "Enter + print user string" << endl;
	MyString p2;
	p2.EnterString();
	p2.PrintString();
	cout << "------------------------------" << endl;
	
	//check: compare two strings
	cout << "Compare str1 and str2" << endl;
	cout << str1.MyStrCmp(rez) << endl;
	cout << "------------------------------" << endl;

	//check: operator overloading
	cout << "find which statement is true: str1 and str2" << endl;
	if (str1 > str2) {
		cout << "str1 > str2" << endl;
	}
	if (str1 < str2) {
		cout << "str1 < str2" << endl;
	}

	if (str1 == str2) {
		cout << "str1 == str2" << endl;
	}

}