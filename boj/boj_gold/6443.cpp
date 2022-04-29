#include <iostream>
#include <string>
using namespace std;

int n, len;
int a[26];
string ans;

void print_ans(int now)
{
	if (now == len)
	{
		cout << ans << '\n';
		return ;
	}
	for (int i = 0; i < 26; i++)
	{
		if (a[i])
		{
			ans += 'a' + i;
			a[i]--;
			print_ans(now + 1);
			ans.erase(ans.size() - 1, 1);
			a[i]++;
		}
	}
}

int main()
{
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		len = str.size();
		for (int i = 0; i < len; i++)
			a[str[i] - 'a']++;
		print_ans(0);
		for (int i = 0; i < 26; i++)
			a[i] = 0;
	}
}