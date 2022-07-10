#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day;
    for (int i = 0; i < progresses.size(); i++) {
        int tmp = (100 - progresses[i]) / speeds[i] + ((100 - progresses[i]) % speeds[i] != 0);
        day.push_back(tmp);
    }
    int cnt = 1;
    for (int i = 0; i < day.size(); i++) {
        if (i == day.size() - 1 || day[i] < day[i + 1]) {
            answer.push_back(cnt);
            cnt = 1;
        }
        else
            cnt++;
    }
    return answer;
}
