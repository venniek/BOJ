#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int big = n > m ? n : m;
    int small = n > m ? m : n;
    int tmp = big - small;
    
    if (n == m)
    {
        answer.push_back(n);
        answer.push_back(n);
        return answer;
    }
    while (1)
    {
        if (n % tmp == 0 && m % tmp == 0)
            break;
        big = max(small, tmp);
        small = min(small, tmp);
        tmp = big - small;
    }
    answer.push_back(tmp);
    answer.push_back((long long)n * m / tmp);
    return answer;
}
