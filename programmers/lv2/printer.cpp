#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

queue<pair<int, int>> q;

int find_max()
{
    int mx = 0;
    for (int i = 0; i < q.size(); i++)
    {
        mx = max(mx, q.front().second);
        q.push(q.front());
        q.pop();
    }
    return mx;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;

    
    for (int i = 0; i < priorities.size(); i++)
        q.push(make_pair(i, priorities[i]));
    while (!q.empty())
    {
        int mx = find_max();
        while (q.front().second != mx)
        {
            q.push(q.front());
            q.pop();
        }
        if (q.front().first == location)
            break;
        else
        {
            q.pop();
            answer++;
        }
    }
    return answer + 1;
}
