#include <iostream>
#include <string>
using namespace std;

int alpha[26];
int n, pangram;

int main()
{
    string tmp;
    cin >> n;
	getline(cin, tmp);
    for (int k = 1; k <= n; k++)
    {
        string answer;
		getline(cin, tmp);
        for (int i = 0; i < 26; i++)
            alpha[i] = 0;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] >= 'a' && tmp[i] <= 'z')
                alpha[tmp[i] - 'a']++;
            else if (tmp[i] >= 'A' && tmp[i] <= 'Z')
                alpha[tmp[i] - 'A']++;
        }
        pangram = 3;
        for (int i = 0; i < 26; i++)
            pangram = min(pangram, alpha[i]);
        if (pangram == 0)
            answer = "Not a pangram";
        else if (pangram == 1)
            answer = "Pangram!";
        else if (pangram == 2)
            answer = "Double pangram!!";
        else
            answer = "Triple pangram!!!";
        cout << "Case " << k << ": " << answer << '\n';
    }
    return 0;
}