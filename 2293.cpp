#include <iostream>
#include <vector>
using namespace std;
int coin[105];
int d[10005];
int n , k, tmp;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n ;i++)
		cin >> coin[i];
	d[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
			d[j] += d[j - coin[i]];
	}
    cout << d[k];
}
