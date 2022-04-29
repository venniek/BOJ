#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
    int n;
    int t;

    string clothes;

    cin >> n;
    while (n--)
    {
        cin >> t;
        int ans = 1;
        map<string, int> m;

        for (int i = 0; i < t; i++)
        {
            cin >> clothes >> clothes;
            if (m.find(clothes) == m.end())
            {
                m.insert(make_pair(clothes, 2));
            }
            else
            {
                m[clothes]++;
            }
        }
        for (auto i : m)
        {
            ans *= i.second;
        }
        ans--; // 아무것도 안입는거 빼기
        cout << ans << '\n';
    }
}


