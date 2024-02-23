/*
Bai 7. Viet chuong trinh tim ky tu nao trong 26 chu cai khong xuat hien trong chuoi
*/

#include <iostream>
#include <string>

using namespace std;

void InputString(string &s)
{
	cout << "Enter string: "; 
	getline(cin, s);
}

void CheckNotAppear(string s, string alp)
{
	cout << "Characters not appear in string: ";
	bool printed = true;
	for (int i = 0; i < 26; i++)
	{
		bool isAppear = false;
		for (int j = 0; j < s.size(); j++)
		{
			if (alp[i] == s[j])
			{
				isAppear = true;
				printed = false;
				continue;
			}
		}
		if (!isAppear) {
			cout << alp[i] << " ";
		}
	}
	if (!printed) cout << "none" << endl;
}

int main()
{
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string s = " ";
	InputString(s);
	CheckNotAppear(s, alphabet);
	return 0;
}