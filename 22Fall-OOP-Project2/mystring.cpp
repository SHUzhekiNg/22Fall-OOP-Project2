#include "mystring.h"

MyString::MyString(const MyString& s)
{
	length = strlen(s.Cstr());
	str = new char[length + 1];
	strcpy(str, s.Cstr());
}

MyString::MyString(const char* s)
{
	length = strlen(s);
	str = new char[length + 1];
	strcpy(str, s);
	str[length] = '\0';
}


ostream& operator<<(ostream& out, const MyString& s)
{
	out << s.Cstr();
	return out;
}

istream& operator>>(istream& in, MyString& ss)
{
	string s;
	in >> s;
	char* cs = new char[s.length() + 1];
	for (int i = 0; i < s.length(); i++)
		cs[i] = s[i];
	cs[s.length()] = '\0';
	ss = cs;
	return in;
}

// È¡×Ó´®
MyString MyString::SubString(int p, int n)
{
	if (0 <= p && p + n < GetLength() && 0 <= n) {
		char* sub = new char[n + 1];
		const char* s = Cstr();
		strncpy(sub, s + p, n);
		sub[n] = '\0';
		MyString ss(sub);
		delete[] sub;
		return ss;
	}
	else {
		MyString ss("");
		return ss;
	}
}


MyString MyString::operator +(const MyString& s)
{
	const char* cs1 = Cstr();
	const char* cs2 = s.Cstr();
	char* cs = new char[strlen(cs1) + strlen(cs2) + 1];
	strcpy(cs, cs1);
	strcat(cs, cs2);
	MyString s1(cs);
	delete[] cs;
	return s1;
}

MyString& MyString::operator =(const MyString& s)
{
	if (&s != this) {
		delete[] str;
		length = strlen(s.Cstr());
		str = new char[length + 1];
		strcpy(str, s.Cstr());
	}
	return *this;
}

/*
MyString& MyString::operator +=(const MyString& s) {
	const char* cs1 = Cstr();
	const char* cs2 = s.Cstr();
	char* cs = new char[strlen(cs1) + strlen(cs2) + 1];
	strcpy(cs, cs1);
	strcat(cs, cs2);
	MyString s1(cs);
	*this = s1;
	delete[] cs;
	return *this;
}
*/
bool MyString::operator ==(const MyString& s)
{
	return strcmp(Cstr(), s.Cstr()) == 0;
}

bool MyString::operator <(const MyString& s)
{
	return strcmp(Cstr(), s.Cstr()) < 0;
}

bool MyString::operator >(const MyString& s)
{
	return strcmp(Cstr(), s.Cstr()) > 0;
}

bool MyString::operator <=(const MyString& s)
{
	return strcmp(Cstr(), s.Cstr()) <= 0;
}

bool MyString::operator >=(const MyString& s)
{
	return strcmp(Cstr(), s.Cstr()) >= 0;
}

bool MyString::operator !=(const MyString& s)
{
	return strcmp(Cstr(), s.Cstr()) != 0;
}

char& MyString::operator [](int p) const
{
	return str[p];
}
