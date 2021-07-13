#include <iostream>

using namespace std;

int ans[11];

void find_ans(int n)
{
	if (n <= 3 || ans[n] != 0)
		return ;
	for (int i = 4; i <= n; i++)
		ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
}

int main()
{
	int t, n;
	
	cin >> t;
	while (t-- > 0)
	{
		cin >> n;
		ans[1] = 1;
		ans[2] = 2;
		ans[3] = 4;
		find_ans(n);
		cout << ans[n] << endl;
	}
	return 0;
}
		
