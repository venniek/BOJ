#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> absolutes, vector<bool> signs) {
    long long answer = 0;
    
    for (int i = 0; i < signs.size(); i++)
        answer += (long long)absolutes[i] * (signs[i] == true ? 1 : -1);
    return answer;
}
