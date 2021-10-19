#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100002];
typedef struct {
    int x;
    int y;
    int weight;
} tmp;
vector<tmp> wei;
bool chk;
int res;

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
    return parent[dot] = find(parent[dot]);
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
    int v, e, a, b, c;

	cin >> v >> e;
	for (int i = 0; i < v; i++)
		parent[i] = i;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
        wei.push_back({a, b, c});
	}
    sort(wei.begin(), wei.end(), cmp);
	int mx = 0;
	for (int i = 0; i < e; i++)
	{
		merge(wei[i].x, wei[i].y);
		if (chk)
		{
			mx = wei[i].weight;
			res += wei[i].weight;
		}
	}
	cout << res - mx;
	return 0;
}
