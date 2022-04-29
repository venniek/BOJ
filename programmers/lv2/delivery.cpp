#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define PII pair<int, int>
using namespace std;

vector<PII> line[55];
int dis[55];

void find_ans(int start)
{
    dis[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    pq.push({start, 0});
    while (!pq.empty())
    {
        int cur = pq.top().first;
        int distance = pq.top().second;
        pq.pop();
        if (dis[cur] != distance)
            continue;
        for (int i = 0; i < line[cur].size(); i++)
        {
            int next = line[cur][i].first;
            int nextdis = distance + line[cur][i].second;
            if (nextdis < dis[next])
            {
                dis[next] = nextdis;
                pq.push({next, nextdis});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for (int i = 0; i < 55; i++)
        dis[i] = 2147483647;
    for (int i = 0; i < road.size(); i++)
    {
        line[road[i][0]].push_back({road[i][1], road[i][2]});
        line[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    find_ans(1);
    for (int i = 1; i <= N; i++)
    {
        if (dis[i] <= K)
            answer++;
    }
    return answer;
}
