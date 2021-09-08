#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int start = 0;
    
    while (1)
    {
        for (int i = start; i < progresses.size(); i++)
            progresses[i] += speeds[i];
        if (progresses[start] >= 100)
        {
            queue<int> q;
            while (start < progresses.size() && progresses[start] >= 100)
                q.push(start++);
            answer.push_back(q.size());
        }
        if (start == progresses.size())
            break;
    }
    return answer;
}
