#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> v;
vector<int> ans;

void lotto(int cur, int cnt)
{
    if (cnt == 6)
    {
		for (int i = 0; i < 6; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return ;
    }
	for (int i = cur; i < k; i++)
	{
		ans.push_back(v[i]);
		lotto(i + 1, cnt + 1);
		ans.pop_back();
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		lotto(0, 0);
		v.clear();
		cout << '\n';
    }
    
}
