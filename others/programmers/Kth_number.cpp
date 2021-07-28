#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    int len = commands.size();
    for (int i = 0; i < commands.size(); i++)
    {
        priority_queue<int, vector<int>, greater<int> > tmp;
        
        for (int k = commands[i][0] - 1; k <= commands[i][1] - 1; k++)
            tmp.push(array[k]);
        for (int k = 0; k < commands[i][2] - 1; k++)
            tmp.pop();
        answer.push_back(tmp.top());
    }
    return answer;
}
