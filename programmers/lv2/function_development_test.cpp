#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day;
    
    for (int i = 0; i < progresses.size(); i++){
        int tmp = (100 - progresses[i]) / speeds[i] + ((100 - progresses[i]) % speeds[i] != 0);
        day.push_back(tmp);
    }
    int cnt = 0;
    int saveidx = 0;
    for (int i = 0; i < day.size(); i++){
        if (day[saveidx] < day[i]){
            answer.push_back(cnt);
            cnt = 1;
            saveidx = i;
        } else {
            cnt++;
        }
    }
    answer.push_back(cnt);
    return answer;
}
