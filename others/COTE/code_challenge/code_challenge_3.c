#include <string>
#include <vector>
#include <cmath>

using namespace std;

int is_square(int n)
{
    return ((int)sqrt(n) * (int)sqrt(n) == n ? 1 : 0);
}

int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left; i <= right; i++)
    {
        if (is_square(i) == 0)
            answer += i;
        else
            answer -= i;
    }
    return answer;
}
