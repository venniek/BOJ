#include <iostream>
#include <string>

using namespace std;

int main()
{
	int ans = 0;
	string s;
	string t;

	cin >> s >> t;
	while (s.size() < t.size())
	{
		if (t.back() == 'A')
			t.pop_back();
		else
		{
			t.pop_back();
			for (int i = 0; i < t.size() / 2; i++)
				swap(t[i], t[t.size() - 1 - i]);
		}
		if (s.size() == t.size() && s.compare(t) == 0)
			ans = 1;
	}
	cout << ans;
	return 0;
}
