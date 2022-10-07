#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <cstring>
using namespace std;

class MyString
{
public:
	MyString() :l(0), str(NULL) {}
	~MyString() { delete[] str; }
	MyString(const MyString& s);
	MyString(const char* s);

	friend ostream& operator<<(ostream& out, const MyString& s);
	friend istream& operator>>(istream& in, MyString& ss);
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

	int length() const { return l; }
	bool IsEmpty() const { return l == 0; }
	const char* c_str() const { return (const char*)str; }
	MyString SubString(int p, int n);
private:
	char* str;
	int l;
};
