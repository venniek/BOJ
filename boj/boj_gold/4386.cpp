#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int parent[10002];
typedef struct {
    int x;
    int y;
    float weight;
} tmp;
vector<tmp> wei;
vector<pair<float, float> > dot;
bool chk;
float res;

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
    int v;
	float a, b, c;
	cin >> v;
	for (int i = 0; i < v; i++) // 부모를 자기 자신으로 초기화
		parent[i] = i;
	for (int i = 0; i < v; i++)
	{
		cin >> a >> b;
        dot.push_back({a, b});
	}
	for (int i = 0; i < v - 1; i++)
	{
		for (int j = i + 1; j < v; j++)
		{
			wei.push_back({i, j, (float)sqrt(pow(dot[i].first - dot[j].first, 2) + pow(dot[i].second - dot[j].second, 2))});
		}
	}
    sort(wei.begin(), wei.end(), cmp);
	for (int i = 0; i < v * (v - 1) / 2; i++)
	{
		merge(wei[i].x, wei[i].y);
		if (chk)
			res += wei[i].weight;
	}
	printf("%0.2f", res);
	return 0;
}
