#include "mystring.h"
int main()
{
	MyString s1("SHU");
	MyString s2("OOP");
	MyString s3;

	int c = 1;
	int p, l;
	
	while (c) {
		cout << "��ǰĬ���ַ���Ϊ:s1=" << s1 << ", s2=" << s2 << endl << "��ѡ����Բ���:";
		cout << endl << "1. ���Թ�ϵ�����==";
		cout << endl << "2. ����SubString()";
		cout << endl << "3. �����±������";
		cout << endl << "4. �������������+��+=";
		cout << endl << "5. �����ַ���1";
		cout << endl << "6. �����ַ���2";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ���� (0~6):";
		cin >> c;
		switch (c) {
			case 1:
				cout << "�ַ���s1Ϊ��";
				cout << s1 << endl;
				cout << "�ַ���s2Ϊ��";
				cout << s2 << endl;
				if (s1 == s2)
					cout << "s1��s2��ȡ�" << endl;
				else
					cout << "s1��s2����ȡ�" << endl;
				break;
			case 2:
				cout << "�ַ���s1Ϊ��";
				cout << s1 << endl;
				cout << "�����Ӵ������λ�úͳ��ȣ�" << endl;
				cin >> p >> l;
				try { s2 = s1.SubString(p, l); }
				catch (const char* msg) 
				{ 
					cerr << msg << endl; 
					s2 = "";
				}
				cout << endl << "ȡ�Ӵ����Ϊ��";
				cout << s2 << endl;
				break;
			case 3:
				cout << "�ַ���s1Ϊ��";
				cout << s1 << endl;
				cout << endl << "�����ַ��±꣺";
				cin >> p;
				cout << endl << "�����±���������Ϊ��" << endl;
				try {
					cout << s1[p] << endl; 
				}
				catch (out_of_range& e)
				{
					cerr << e.what() << endl;
				}
				break;
			case 4:
				cout << "�ַ���s1Ϊ��";
				cout << s1 << endl;
				cout << "�ַ���s2Ϊ��";
				cout << s2 << endl;
				s3 = s1 + s2;
				cout << endl << "�ַ������ӽ����ʹ��+��Ϊ��";
				cout << s3 << endl;
				s1 += s2;
				cout << endl << "�ַ������ӽ����ʹ��+=��Ϊ��";
				cout << s1 << endl;
				break;
			case 5:
				cout << endl << "�����ַ���1��";
				cin >> s1;
				break;
			case 6:
				cout << endl << "�����ַ���2��";
				cin >> s2;
				break;
			default:
				break;
		}
	}
	system("pause");
	return 0;
}
