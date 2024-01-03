#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> bruteForceMatching(const string text, const string pattern)
{
    vector<int> matches;
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        for ( ; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == m)
        {
            matches.push_back(i);
        }
    }
    return matches;
}

int main()
{
    string text = "ABRACADABRAABRACADABRAABRACADABRA";
    string pattern = "ABRA";
    vector<int> matches = bruteForceMatching(text, pattern);
    for (int i = 0; i < matches.size(); i++)
    {
        cout << matches[i] << " ";
    }
    return 0;
}