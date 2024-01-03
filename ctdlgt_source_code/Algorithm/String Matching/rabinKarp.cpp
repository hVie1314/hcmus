#include <iostream>
#include <vector>
#include <string>
#define d 256
#define q INT_MAX // to avoid overflowing and collison

using namespace std;

vector<int> rabinKarpMatching(string text, string pattern)
{
	vector<int> matches;
	int n = text.length();
	int m = pattern.length();
	int t = 0; // hash value of text
	int p = 0; // hash value of pattern
	int h = 1; // h = d^(m - 1) % q
	int i = 0;
	int j = 0;

	// cacl h 
	for (i = 0; i < m - 1; i++)
	{
		h = (d * h) % q;
	}

	// hash first text and pattern
	for (i = 0; i < m; i++)
	{
		t = (d * t + text[i]) % q;
		p = (d * p + pattern[i]) % q; 
	}

	// move the window one by one
	for (i = 0; i <= n - m; i++)
	{
		// if t = p
		// check every sing digit - brute force 
		if (t == p)
		{
			for (j = 0; j < m; j++)
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

		// rehash t 
		if (i < n - m)
		{
			// remove leading digit
			// add tailing digit
			t = (d * (t - text[i] * h) + text[i + m]) % q;
		}
		// if t is negative
		// mod q
		if (t < 0)
		{
			t += q;
		}
	}
	return matches;
}


int main()
{
	string text = "GEEKS FOR GEEKS";
	string pattern = "GEEK";
	vector<int> matches;

	matches = rabinKarpMatching(text, pattern);

	cout << "Pattern found at: ";
	for (int i = 0; i < matches.size(); i++)
	{
		cout << matches[i] << " ";
	}
	return 0;
}