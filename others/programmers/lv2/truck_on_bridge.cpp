#include <queue>
#include <utility>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int i = 0;
    queue<pair<int, int> > q;
    
    q.push({truck_weights[i++], 1});
    sum += q.front().first;
    while (!q.empty())
    {
        answer++;
        if (answer - q.front().second >= bridge_length)
        {
            sum -= q.front().first;
            q.pop();
        }
        if (i < truck_weights.size() && q.size() < bridge_length && sum + truck_weights[i] <= weight)
        {
            q.push({truck_weights[i], answer});
            sum += truck_weights[i++];
        }
    }
    return answer;
}
