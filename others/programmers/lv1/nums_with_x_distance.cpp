#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    answer.push_back(x);
    for (int i = 2; i <= n; i++)
        answer.push_back((long long)x * i);
    return answer;
}
