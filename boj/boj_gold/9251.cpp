#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s1;
	string s2;
	int len1, len2;
	
	cin >> s1;
	cin >> s2;
	len1 = s1.size();
	len2 = s2.size();
	vector < vector <int> > map(len2 + 1, vector <int>(len1 + 1, 0));
	for (int i = 1; i < len2 + 1; i++)
	{
		for (int k = 1; k < len1 + 1; k++)
		{
			int ans;
			if (s1[k - 1] == s2[i - 1])	
				ans = map[i - 1][k - 1] + 1;
			else
				ans = (max(map[i - 1][k], map[i][k - 1]));
			map[i][k] = ans;
		}
	}
	cout << map[len2][len1];
	return 0;
}
