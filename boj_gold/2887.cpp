#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int x;
    int y;
    int weight;
} tmp;

typedef struct
{
	int x;
	int y;
	int z;
	int num;
} xyz;

vector<tmp> wei;
vector<xyz> grid;
vector<int> parent;
bool chk;
long long res;

bool cmp (tmp wei1, tmp wei2)
{
    if (wei1.weight < wei2.weight)
		return 1;
	return 0;
}

bool cmp_x(xyz grid1, xyz grid2)
{
	if (grid1.x < grid2.x)
		return 1;
	return 0;
}

bool cmp_y(xyz grid1, xyz grid2)
{
	if (grid1.y < grid2.y)
		return 1;
	return 0;
}

bool cmp_z(xyz grid1, xyz grid2)
{
	if (grid1.z < grid2.z)
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
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int v, a, b, c;

	cin >> v;
	parent.push_back(0);
	for (int i = 1; i <= v; i++)
	{
		cin >> a >> b >> c;
		grid.push_back({a, b, c, i});
		parent.push_back(i);
	}
	sort(grid.begin(), grid.end(), cmp_x);
	for (int i = 0; i < v - 1; i++)
		wei.push_back({grid[i].num, grid[i + 1].num, grid[i + 1].x - grid[i].x});
	sort(grid.begin(), grid.end(), cmp_y);
	for (int i = 0; i < v - 1; i++)
		wei.push_back({grid[i].num, grid[i + 1].num, grid[i + 1].y - grid[i].y});
	sort(grid.begin(), grid.end(), cmp_z);
	for (int i = 0; i < v - 1; i++)
		wei.push_back({grid[i].num, grid[i + 1].num, grid[i + 1].z - grid[i].z});
    sort(wei.begin(), wei.end(), cmp);
	for (int i = 0; i < wei.size(); i++)
	{
		merge(wei[i].x, wei[i].y);
		if (chk)
			res += (long long)wei[i].weight;
	}
	cout << res;
	return 0;
}