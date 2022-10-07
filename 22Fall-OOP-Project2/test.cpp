#include "mystring.h"
int main()
{
	MyString s1("2022Fall-OOP");
	MyString s2("2022");
	int c = 1;
	int p, l;

	while (c) {
		cout << "当前默认字符串为:s1=" << s1 << ", s2=" << s2 << endl << "请选择测试操作:";
		cout << endl << "1. 测试关系运算符==";
		cout << endl << "2. 测试SubString()";
		cout << endl << "3. 测试下标运算符";
		cout << endl << "4. 测试连接运算符+";
		cout << endl << "5. 输入字符串1";
		cout << endl << "6. 输入字符串2";
		cout << endl << "0. 退出";
		cout << endl << "选择功能 (0~6):";
		cin >> c;
		switch (c) {
			case 1:
				cout << "字符串s1为：";
				cout << s1 << endl;
				cout << "字符串s2为：";
				cout << s2 << endl;
				if (s1 == s2)
					cout << "s1和s2相等。" << endl;
				else
					cout << "s1和s2不相等。" << endl;
				break;
			case 2:
				cout << "字符串s1为：";
				cout << s1 << endl;
				cout << "输入子串的起点位置和长度：" << endl;
				cin >> p >> l;
				s2 = s1.SubString(p, l);
				cout << endl << "取子串结果为：";
				cout << s2 << endl;
				break;
			case 3:
				cout << "字符串s1为：";
				cout << s1 << endl;
				cout << endl << "输入字符下标：";
				cin >> p;
				cout << endl << "测试下标运算符结果为：" << endl;
				cout << s1[p] << endl;
				break;
			case 4:
				cout << "字符串s1为：";
				cout << s1 << endl;
				cout << "字符串s2为：";
				cout << s2 << endl;
				s1 = s1 + s2;
				cout << endl << "字符串连接结果为：";
				cout << s1 << endl;
				break;
			case 5:
				cout << endl << "输入字符串1：";
				cin >> s1;
				break;
			case 6:
				cout << endl << "输入字符串2：";
				cin >> s2;
				break;
			default:
				break;
		}
	}
	system("pause");
	return 0;
}
