#include "mystring.h"

MyString& MyString::operator=(const MyString& str)
{
	// TODO: �ڴ˴����� return ���
}

MyString& MyString::operator+(const MyString& str)
{
	// TODO: �ڴ˴����� return ���
}

MyString& MyString::operator+=(const MyString& str)
{
	// TODO: �ڴ˴����� return ���
}

bool MyString::operator==(const MyString& str)
{
	return false;
}

bool MyString::operator!=(const MyString& str)
{
	return false;
}

bool MyString::operator<(const MyString& str)
{
	return false;
}

bool MyString::operator<=(const MyString& str)
{
	return false;
}

bool MyString::operator>(const MyString& str)
{
	return false;
}

bool MyString::operator>=(const MyString& str)
{
	return false;
}

char& MyString::operator[](const int& index)
{
	return str[index];
}

istream& operator>>(istream& in, const MyString& str)
{
	// TODO: �ڴ˴����� return ���
}

ostream& operator<<(ostream& out, const MyString& str)
{
	// TODO: �ڴ˴����� return ���
}
