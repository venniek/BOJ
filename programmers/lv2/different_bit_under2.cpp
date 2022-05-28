#include <string>
#include <vector>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long n: numbers) {
        int cnt = 0;
        while ((n >> cnt) & 1) { ++cnt; }
        answer.push_back(n + (1LL << max((cnt - 1), 0)));
    }
    return answer;
}
