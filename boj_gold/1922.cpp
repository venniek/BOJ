#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10002];
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

int find(int dot) // 파인드
{
    if (dot == parent[dot])
        return dot;
    return parent[dot] = find(parent[dot]);
}

void merge(int start, int end) // 유니온
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
	for (int i = 0; i < v; i++) // 부모를 자기 자신으로 초기화
		parent[i] = i;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
        wei.push_back({a, b, c});
	}
    sort(wei.begin(), wei.end(), cmp); // 간선을 오름차순 정렬
	for (int i = 0; i < e; i++)  // 사이클이 존재하지 않도록 연결할 수 있나 보기
	{
		merge(wei[i].x, wei[i].y);
		if (chk)
			res += wei[i].weight;
	}
	cout << res;
	return 0;
}
