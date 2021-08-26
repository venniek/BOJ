#include <iostream>

using namespace std;

int main()
{
	int n;
	char k;
	int ans = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		if (k == '1')
			ans++;
	}
	cout << ans;
	return 0;
}
