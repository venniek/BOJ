#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n;
int m;

int compare(vector<int> v, int start)
{
	for (int i = 0; i < start; i++)
	{
		if (v[start] == v[i])
			return (1);
	}
	return (0);
}

void n_and_m(int start)
{
	if (start == m)
	{
		for (int i = 0; i < m; i++)
			cout << v[i] << " ";
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		v[start] = i;
		if (compare(v, start) == 0)
			n_and_m(start + 1);		
	}
}


int main()
{
	cin >> n >> m;
	v.resize(m);
	for (int i = 0; i < m; i++)
		v[i] = 0;
	n_and_m(0);
	return 0;
}
