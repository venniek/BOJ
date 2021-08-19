#innclude <iostream>
using namespace std;

int d[2][100002];
int map[2][100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
    cin >> t;
	while (t-- > 0)
	{
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int k = 0; k < n; k++)
				cin >> map[i][k];
		}
		d[0][0] = map[0][0];
		d[1][0] = map[1][0];
		d[0][1] = map[0][1] + d[1][0];
		d[1][1] = map[1][1] + d[0][0];
		for (int i = 2; i < n; i++)
		{
			d[0][i] = max(d[1][i - 1], d[1][i -2]) + map[0][i];
			d[1][i] = max(d[0][i - 1], d[0][i -2]) + map[1][i];
		}
		cout << max(d[0][n - 1], d[1][n - 1]) << '\n';
	}
	return 0;
}
