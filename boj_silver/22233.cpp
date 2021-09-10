#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> m;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, t;
    string words;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> words;
        m.insert(make_pair(words, 1));
    }
    for (int i = 0; i < t; i++)
    {
        cin >> words;
        string tmp;
        int k = 0;
        while (1)
        {
            if (words[k] == ',' || words[k] == '\0')
            {
                if (m.find(tmp) != m.end())
                    m.erase(tmp);
                tmp.clear();
            }
            else
                tmp += words[k];
            if (words[k] == '\0')
                break;
            k++;
			if (m.size() == 0)
				break;
        }
        cout << m.size() << '\n';
    }
    return 0;
}
