#include <iostream>
#include <queue>
using namespace std;

int N, K;
int dis[100005];
queue<int> q;

void fill(int n, int cur)
{
    q.push(n);
    dis[n] = dis[cur] + 1;
}

int main()
{
    cin >> N >> K;
    dis[N] = 1;
    q.push(N);
    while (!dis[K])
    {
        int cur = q.front();
        q.pop();
		if (cur + 1 <= 100000 && dis[cur+1] == 0)
            fill(cur + 1, cur);
		if (cur - 1 >= 0 && dis[cur-1] == 0)
            fill(cur - 1, cur);
		if (cur * 2 <= 100000 && dis[cur * 2] == 0)
            fill(cur * 2, cur);
    }
    cout << dis[K] - 1;
    return 0;
}
