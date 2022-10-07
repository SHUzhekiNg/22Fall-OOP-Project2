#include "mystring.h"

MyString::MyString(const MyString& s)
{
	l = strlen(s.c_str());
	str = new char[l + 1];
	strcpy(str, s.c_str());
}

MyString::MyString(const char* s)
{
	l = strlen(s);
	str = new char[l + 1];
	strcpy(str, s);
	str[l] = '\0';
}

ostream& operator<<(ostream& out, const MyString& s)
{
	out << s.c_str();
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

// 取子串
MyString MyString::SubString(int p, int n)
{
	if (0 <= p && p + n < length() && 0 <= n) {
		char* sub = new char[n + 1];
		const char* s = c_str();
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
	const char* cs1 = c_str();
	const char* cs2 = s.c_str();
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
		l = strlen(s.c_str());
		str = new char[l + 1];
		strcpy(str, s.c_str());
	}
	return *this;
}


MyString& MyString::operator +=(const MyString& s) {
	const char* cs1 = c_str();
	const char* cs2 = s.c_str();
	char* cs = new char[strlen(cs1) + strlen(cs2) + 1];
	strcpy(cs, cs1);
	strcat(cs, cs2);
	MyString s1(cs);
	*this = s1;
	delete[] cs;
	return *this;
}

bool MyString::operator ==(const MyString& s)
{
	return strcmp(c_str(), s.c_str()) == 0;
}

bool MyString::operator <(const MyString& s)
{
	return strcmp(c_str(), s.c_str()) < 0;
}

bool MyString::operator >(const MyString& s)
{
	return strcmp(c_str(), s.c_str()) > 0;
}

bool MyString::operator <=(const MyString& s)
{
	return strcmp(c_str(), s.c_str()) <= 0;
}

bool MyString::operator >=(const MyString& s)
{
	return strcmp(c_str(), s.c_str()) >= 0;
}

bool MyString::operator !=(const MyString& s)
{
	return strcmp(c_str(), s.c_str()) != 0;
}

char& MyString::operator [](int p) const
{
	if (p >= l) cerr << "下表越界！" << endl;
	return str[p];
}
