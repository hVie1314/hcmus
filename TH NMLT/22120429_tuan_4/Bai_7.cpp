#include <iostream> 
#include <string>
using namespace std;

void UpperCase(char a[]) {
    for (int i = 0; i < strlen(a); i++)
    {
        if (i == 0 || (i > 0 && a[i - 1] == ' ')) 
        {
            if (a[i] >= 'a' && a[i] <= 'z')
                a[i] = a[i] - 32;
        }
        else 
        {
            if (a[i] >= 'A' && a[i] <= 'Z') 
            {
                a[i] = a[i] + 32;
            }

        }
    }
}
int main() 
{
    char s1[10] = "", s2[10] = "", s3[10] = "";
    cout << "Enter your name: ";
    cin >> s1 >> s2 >> s3; 
    UpperCase(s1);
    UpperCase(s2);
    UpperCase(s3);
    cout << "Your name: " << s1 << " " << s2 << " " << s3 << " "<< " " << endl;
    return 0;
}