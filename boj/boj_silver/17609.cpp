#include <iostream>
#include <string>
using namespace std;

int n;
string str;

int main()
{
	cin >> n;
	while (n--)
	{
        int del = 0;
        int ans1 = 0; int ans2 = 0;
		cin >> str;
		int en = str.size() - 1;
		for (int st = 0; st < en; st++)
		{
			if (str[st] != str[en])
			{
				if (del == 1)
				{
					ans1 = 2;
					break;
				}
				if (st + 1 != en && str[en] == str[st + 1])
				{
					st++;
					del = 1;
				}
				else
				{
					ans1 = 2;
					break;
				}
			}
			en--;
		}
		if (del == 1 && ans1 != 2)
			ans1 = 1;
		en = str.size() - 1;
		for (int st = 0; st < en; st++)
		{
			if (str[st] != str[en])
			{
				if (del == 1)
				{
					ans2 = 2;
					break;
				}
				if (st != en - 1 && str[st] == str[en - 1])
				{
					en--;
					del = 1;
				}
				else
				{
					ans2 = 2;
					break;
				}
			}
			en--;
		}
		if (del == 1 && ans2 != 2)
			ans2 = 1;
		cout << min(ans1, ans2) << '\n';
	}
}
