#include <iostream>
#include <string>
#define HASH_SIZE 97
using namespace std;

int hashString(const string str)
{
	int i = 0;
	int j = 9;
	while (str[i] != '\0')
	{
		j = (31 * j + str[i]) % HASH_SIZE;
		i++;
	}
	return j;
}

int main()
{
    
    return 0;
}