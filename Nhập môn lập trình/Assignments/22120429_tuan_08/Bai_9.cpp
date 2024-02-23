/*
Bai 9. kiem tra chuoi 1 co xuat hien trong chuoi 2 hay khong?
*/

#include <iostream>
#include <string>

using namespace std;

void InputString(string &s)
{
	cout << "Enter string: "; 
	getline(cin, s);
}

void Check(string s1, string s2)
{
	int n = s1.size();
	bool appear = false;
	for (int i = 0; i < s2.size() - n + 1; i++)
	{
		if (s1[0] == s2[i])
		{
			string tmp = s2.substr(i, n);
			if (s1 == tmp)
			{
				cout << "String 1 appears in string 2" << endl;
				appear = true;
				break;
			}
		}
	}
	if (!appear) cout << "String 1 do not appeart in string 2" << endl;
}

int main()
{
	string s1 = " ";
	string s2 = " ";
	InputString(s1);
	InputString(s2);
	Check(s1, s2);
	return 0;
}