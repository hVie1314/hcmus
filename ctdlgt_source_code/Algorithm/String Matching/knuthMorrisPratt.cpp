#include <iostream>
#include <string>
#include <vector>

using namespace std;

// LPS : longest prefix suffix
vector<int> createLPSArr(string pattern)
{
    int n = pattern.length();
    int len = 0;
    int i = 1;
    vector<int> lps(n);
    lps[0] = 0;
    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len > 0)
            {
                len = lps[len - 1];
            }
            else // len = 0
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMPMatching(string text, string pattern)
{
    vector<int> matches;
    vector<int> lps = createLPSArr(pattern);
    int n = text.length();
    int m = pattern.length();
    int i = 0; // index of text
    int j = 0; // index of pattern

    // n - i : characters remain in text
    // m - j : characters remain in pattern
    while (n - i >= m - j)
    {
        // if match, increase both i and j
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        // found
        if (j == m)
        {
            matches.push_back(i - j);
            j = lps[j - 1]; // replace j
        }
        else if (i < n && text[i] != pattern[j])
        {
            // a mismatch after a match (j > 0)
            if (j > 0)
            {
                // replace j
                j = lps[j - 1];
            }
            else // j = 0
            {
                // a mismatch after a mismatch 
                // just move next
                i++;
            }
        }
    }
    return matches;
}

int main()
{
    string text = "GEEKS FOR GEEKS";
	string pattern = "GEEK";
    vector<int> matches;

    matches = KMPMatching(text, pattern);

    cout << "pattern found at: ";
    for (int i = 0; i < matches.size(); i++)
    {
        cout << matches[i] << " ";
    }

    return 0;
}
