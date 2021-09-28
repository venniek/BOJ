#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
int n, k;
int a[100001];
int mx;
int sum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int en = 0;

    sum = accumulate(a, a+k, sum);
		mx = sum;

	en = k;
    for (int st = 0; st < n - k; st++)
	{
		sum = sum + a[en++] - a[st];
		mx = max(mx, sum);
		if (en == n)
			break;
	}
    cout << mx;
}
