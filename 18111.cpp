#include <iostream>

using namespace std;
int N, M, B;
int map[500][500];

long long sum_map(int cur)
{
	long long time = 0, cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] > cur)
			    time += 2 * (map[i][j] - cur);
			else 
				time += cur - map[i][j];
			cnt += map[i][j] - cur;
        }
    }
	return (cnt + B >= 0 ? time : -1);
}

int main()
{
	long long ans;
    int mx = 0, mn = 1000;
    cin >> N >> M >> B;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            mx = max(mx, map[i][j]);
			mn = min(mn, map[i][j]);
        }
    }
	while (sum_map(mn) == -1)
		mn++;
	ans = sum_map(mn);
	int hei = mn;
    for (int i = mn + 1; i <= mx; i++)
	{
		long long tmp = sum_map(i);
		if (tmp > 0 && tmp <= ans)
		{
			ans = tmp;
			hei = i;
		}
	}
	cout << ans << " " << hei;
	return 0;
}