#include <iostream>
#include <queue>
using namespace std;

int f,s,g,u,d;
int dis[1000002];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> f >> s >> g >> u >> d;
    dis[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
		if (cur + u <= f && dis[cur + u] == 0)
        {
			q.push(cur + u);
            dis[cur + u] = dis[cur] + 1;
        }
		if (cur - d >= 1 && dis[cur - d] == 0)
        {
			q.push(cur - d);
            dis[cur - d] = dis[cur] + 1;
        }
        if (dis[g])
        {
            cout << dis[g] - 1;
            return 0;
        }
    }
    cout << "use the stairs";
    return 0;
}
