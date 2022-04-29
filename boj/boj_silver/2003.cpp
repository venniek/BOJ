#include <iostream>
using namespace std;
int n, m;
int a[10001];
int sum;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    int en = 0;
	sum += a[0];
    for (int st = 0; st < n; st++)
	{
		while (en < n && sum < m)
        {
            en++;
            if(en != n) sum += a[en];
        }
        if (sum == m)
			ans++;
		if (en == n)
			break;
		sum -= a[st];
	}
    cout << ans;
}
