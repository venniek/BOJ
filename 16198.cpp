#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int tmpe;
vector<int> energysum;

void energy(int tmpe, vector<int> w)
{
	if (w.size() == 2)
	{
		energysum.push_back(tmpe);
		return ;
	}
	for (int i = 1; i < w.size() - 1; i++)
	{
		int save = w[i];
		tmpe += w[i - 1] * w[i + 1];
		w.erase(w.begin() + i);
		energy(tmpe, w);
		w.insert(w.begin() + i, save);
		tmpe -= w[i - 1] * w[i + 1];
	}
}

int main()
{
	int tmp;
	vector<int> w;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		w.push_back(tmp);
	}
	energy(0, w);
	cout << *max_element(energysum.begin(), energysum.end());
	return 0;
}
