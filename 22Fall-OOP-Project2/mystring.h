#pragma once
#include <iostream>
using namespace std;

class MyString {
public:
	MyString();
	~MyString();
	MyString(const MyString& str);
	MyString& operator= (const MyString& str);

	friend istream& operator>> (istream& in, const MyString& str);
	friend ostream& operator<< (ostream& out, const MyString& str);
	friend MyString& operator+ (const MyString& str1, const MyString& str2);

	int length(void);
private:
	char str[10000];
};