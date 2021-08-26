#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
int is_done[9];

void sun(int index)
{
	if (index == n)
	{
		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
		cout << "\n";
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (is_done[i] == 0)
		{
			v.push_back(i);
			is_done[i] = 1;
			sun(index + 1);
			v.pop_back();
			is_done[i] = 0;
		}
	}
}


int main()
{
	cin >> n;
	sun(0);
	return 0;
}
