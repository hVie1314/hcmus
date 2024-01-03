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


//-------------------------  Rabin-Karp Algorithm  -------------------------

// #include <iostream>

// void computeLPSArray(char* pat, int M, int* lps);

// // Prints occurrences of txt[] in pat[]
// void KMPSearch(char* pat, char* txt)
// {
//     int M = strlen(pat);
//     int N = strlen(txt);

//     // create lps[] that will hold the longest prefix suffix
//     // values for pattern
//     int lps[M];

//     // Preprocess the pattern (calculate lps[] array)
//     computeLPSArray(pat, M, lps);

//     int i = 0; // index for txt[]
//     int j = 0; // index for pat[]
//     while ((N - i) >= (M - j)) {
//         if (pat[j] == txt[i]) {
//             j++;
//             i++;
//         }

//         if (j == M) {
//             printf("Found pattern at index %d ", i - j);
//             j = lps[j - 1];
//         }

//         // mismatch after j matches
//         else if (i < N && pat[j] != txt[i]) {
//             // Do not match lps[0..lps[j-1]] characters,
//             // they will match anyway
//             if (j != 0)
//                 j = lps[j - 1];
//             else
//                 i = i + 1;
//         }
//     }
// }

// // Fills lps[] for given pattern pat[0..M-1]
// void computeLPSArray(char* pat, int M, int* lps)
// {
//     // length of the previous longest prefix suffix
//     int len = 0;

//     lps[0] = 0; // lps[0] is always 0

//     // the loop calculates lps[i] for i = 1 to M-1
//     int i = 1;
//     while (i < M) {
//         if (pat[i] == pat[len]) {
//             len++;
//             lps[i] = len;
//             i++;
//         }
//         else // (pat[i] != pat[len])
//         {
//             // This is tricky. Consider the example.
//             // AAACAAAA and i = 7. The idea is similar
//             // to search step.
//             if (len != 0) {
//                 len = lps[len - 1];

//                 // Also, note that we do not increment
//                 // i here
//             }
//             else // if (len == 0)
//             {
//                 lps[i] = 0;
//                 i++;
//             }
//         }
//     }
// }

// // Driver code
// int main()
// {
//     char txt[] = "ABABDABACDABABCABAB";
//     char pat[] = "ABABCABAB";
//     KMPSearch(pat, txt);
//     return 0;
// }
