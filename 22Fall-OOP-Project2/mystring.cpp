#include "mystring.h"

MyString::MyString(const MyString& s)
{
	l = strlen(s.c_str());
	try {
		str = new char[l + 1];
	}
	catch (bad_alloc& e)
	{
		cerr << e.what();
	}
	strcpy(str, s.c_str());
}

MyString::MyString(const char* s) 
{
	l = strlen(s);
	try {
		str = new char[l + 1];
	}
	catch (bad_alloc& e)
	{
		cerr << e.what();
	}
	strcpy(str, s);
	str[l] = '\0';
}

ostream& operator<<(ostream& out, const MyString& s)
{
	if (s.c_str() == nullptr)	out << "未存放字符串";
	else   out << s.c_str();
	return out;
}

istream& operator>>(istream& in, MyString& ss)
{
	string s;
	in >> s;
	char* cs = nullptr;
	try {
		cs = new char[s.length() + 1];
	}
	catch (bad_alloc& e)
	{
		cerr << e.what()<<endl;
	}
	for (int i = 0; i < s.length(); i++)
		cs[i] = s[i];
	cs[s.length()] = '\0';
	ss = cs;
	return in;
}

// 取子串
MyString MyString::SubString(int p, int n)	
{
	if (p < 0 || n < 0 || p + n > length()) throw("输入数据不符合要求,已将s2重置为空字符串");
	char* sub = nullptr;
	try {
		sub = new char[n + 1];
	}
	catch (bad_alloc& e)
	{
		cerr << e.what() << endl;
	}
	const char* s = c_str();
	strncpy(sub, s + p, n);
	sub[n] = '\0';
	MyString ss(sub);
	delete[] sub;
	return ss;
}


MyString MyString::operator +(const MyString& s)
{
	const char* cs1 = c_str();
	const char* cs2 = s.c_str();
	char* cs = nullptr;
	try {
		cs = new char[strlen(cs1) + strlen(cs2) + 1];
	}
	catch (bad_alloc& e)
	{
		cerr << e.what() << endl;
	}
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
	char* cs = nullptr;
	try {
		 cs = new char[strlen(cs1) + strlen(cs2) + 1];
	}
	catch (bad_alloc& e)
	{
		cerr << e.what() << endl;
	}
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
	if (p >= l || p < 0) throw out_of_range("下标越界!");
	return str[p];
}
