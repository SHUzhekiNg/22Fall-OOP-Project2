#pragma once
#include <iostream>
using namespace std;

class Mystring {
public:
	Mystring();
	~Mystring();
	Mystring(const Mystring& str);
	Mystring& operator= (const Mystring& str);

	friend istream& operator>> (istream& in, const Mystring& str);
	friend ostream& operator<< (ostream& out, const Mystring& str);
	friend Mystring& operator+ (const Mystring& str1, const Mystring& str2);

	int length(void);
private:
	char str[10000];
};