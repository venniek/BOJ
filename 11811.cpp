#include <iostream>

using namespace std;

int main()
{
	int n;
	int tmp;
	int ans;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ans = 0;
		for (int k = 0; k < n; k++)
		{
			cin >> tmp;
			ans |= tmp;
		}
		cout << ans << " ";
	}
	return 0;
}
