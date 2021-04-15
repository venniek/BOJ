#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int i = 0;
    int len;
    
    len = size(absolutes);
    while (i < len)
    {
        answer += absolutes[i] * (signs[i] == true ? 1 : -1);
        i++;
    }
    return answer;
}
