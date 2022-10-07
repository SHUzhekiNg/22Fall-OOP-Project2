#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <cstring>
using namespace std;

class MyString
{
public:
	MyString() :length(0), str(NULL) {}
	~MyString() { delete[] str; }
	MyString(const MyString& s);
	MyString(const char* s);

	friend ostream& operator<<(ostream& out, const MyString& s);
	friend istream& operator>>(istream& in, MyString& s);
	MyString operator +(const MyString& s);
	MyString& operator =(const MyString& s);
	//MyString& operator +=(const MyString& s);
	bool operator ==(const MyString& s);
	bool operator <(const MyString& s);
	bool operator >(const MyString& s);
	bool operator <=(const MyString& s);
	bool operator >=(const MyString& s);
	bool operator !=(const MyString& s);
	char& operator [](int p) const;

	int GetLength() const { return length; }
	bool IsEmpty() const { return length == 0; }
	const char* Cstr() const { return (const char*)str; }
	MyString SubString(int p, int n);
private:
	char* str;
	int length;
};
