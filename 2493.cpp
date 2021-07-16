#include <iostream>
#include <stack>
#include <utility>
using namespace std;
int N, x;
stack<pair<int,int> > s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> x;
        if (s.empty())
            cout << 0 << " ";
        else
        {
            while (!s.empty() && s.top().first < x)
            {
                s.pop();
                if (s.empty())
                {
                    cout << 0 << " ";
                    break ;
                }
            }
            if (!s.empty() && s.top().first > x)
                cout << s.top().second << " ";
        }
        s.push({x,i});
    }
}
