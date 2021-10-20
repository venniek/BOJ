#include <iostream>
#include <algorithm>
using namespace std;

int parent[1002];
char gender[1002];
typedef struct {
	int x;
    int y;
    int weight;
} s_var;
s_var wei[10002];
bool chk;
int res, cnt;

bool cmp (s_var wei1, s_var wei2)
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
    int v, e, a, b, c;

	cin >> v >> e;
	for (int i = 1; i <= v; i++)
	{
		cin >> gender[i];
		parent[i] = i;
	}
	for (int i = 0; i < e; i++)
	{
		cin >> wei[i].x;
		cin >> wei[i].y;
		cin >> wei[i].weight;
		if (gender[wei[i].x] == gender[wei[i].y])
			wei[i].weight = 1001;
	}
    sort(wei, wei + e, cmp);
	for (int i = 0; i < e; i++)
	{
		if (wei[i].weight == 1001)
			break;
		merge(wei[i].x, wei[i].y);
		if (chk)
		{
			cnt++;
			res += wei[i].weight;
		}
	}
	if (cnt != v - 1)
		res = -1;
	cout << res;
	return 0;
}
