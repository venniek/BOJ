#include <iostream>
#include <vector>
using namespace std;
int T, N ,money, tmp;


int main()
{
    cin >> T;
    while (T--)
    {
		vector<int> coin;
        cin >> N;
        for (int i = 0; i < N ; i++)
        {
            cin >> tmp;
            coin.push_back(tmp);
        }
        cin >> money;

	    int d[10001] = {0,};
        d[0] = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = coin[i]; j <= money; j++)
            {
                d[j] += d[j - coin[i]];
            }
        }
		cout << d[money] << '\n';
    }
    return 0;
}
