#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

int parent[10002];
typedef struct {
    int x;
    int y;
    double weight;
} tmp;
vector<tmp> wei;
vector<pair<int, int> > xy;
bool chk;
double res;

bool cmp (tmp wei1, tmp wei2)
{
    if (wei1.weight < wei2.weight)
		return 1;
	return 0;
}

int find(int dot)
{
    if (dot == parent[dot])
        return dot;
    return find(parent[dot]);
}

void merge(int start, int end)
{
	chk = false;
	start = find(start);
	end = find(end);
	
	if (start == end)
		return ;
	parent[start] = end;
	chk = true;
}


int main(void)
{
    int v, e, a, b;

	cin >> v >> e;
	for (int i = 1; i <= v; i++)
	{
		cin >> a >> b;
		xy.push_back({a, b});
		parent[i] = i;
	}
	for (int i = 1; i <= v - 1; i++)
		for (int j = i + 1; j <= v; j++)
			wei.push_back({i, j, sqrt(pow(xy[i - 1].first - xy[j - 1].first, 2) + pow((xy[i - 1].second - xy[j - 1].second), 2))});
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b;
		merge(a, b);
	}
    sort(wei.begin(), wei.end(), cmp);
	for (int i = 0; i < v * (v - 1) / 2; i++)
	{
		merge(wei[i].x, wei[i].y);
		if (chk)
			res += wei[i].weight;
	}
	printf("%0.2lf", res);
	return 0;
}