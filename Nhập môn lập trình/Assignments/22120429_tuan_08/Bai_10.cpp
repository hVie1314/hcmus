/*
Bai 10. Dem so lan xuat hien nhieu nhat cua tu trong chuoi.
		Neu co nhieu tu xuat hien bang nhau, chi can in ra mot tu.
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void InputString(string &s)
{
	cout << "Enter string: "; 
	getline(cin, s);
}

void MostAppeartWord(string s)
{
	string Dict = " ";
	/*
	* mang Dict luu gia tri thanh tung cap
	* key (index chan): luu thu tu cua tu trong mang 
	* value (index le): luu so lan xuat hien cua tu trong mang
	*/
	stringstream ss1(s); // cat tung tu trong mang
	string word1 = " ";
	int key = 0;
	while (ss1 >> word1)
	{
		Dict.push_back(char(key));
		key++;
		int value = 0;
		stringstream ss2(s);
		string word2 = " ";
		while (ss2 >> word2)
		{
			if (word1 == word2) value++;
		}
		char tmp = (char)value;
		Dict.push_back(char(value)); // push tung cap key-value vao string
	}
	// tim gia tri value co so lan xuat hien nhieu nhat
	int maxIndex = 1;
	for (int i = 3; i < Dict.size(); i = i + 2)
	{
		if (Dict[i] > Dict[maxIndex])
		{
			maxIndex = i;
		}
	}

	// tu xuat hien nhieu nhat co thu tu maxIndex - 1
	int count = 0;
	stringstream ss2(s);
	string word2 = " ";
	while (ss2 >> word2)
	{
		if (count == maxIndex - 1)
		{
			cout << word2 << endl;
			break;
		}
		count++;
	}
}

int main()
{
	string s = " ";
	InputString(s);
	MostAppeartWord(s);
	return 0;
}