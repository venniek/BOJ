#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> num;

int solution(int n) {
    int answer = 3;
    
    if (n == 2)
        return 1;
    if (n < 5)
        return 2;
    if (n < 7)
        return 3;
    for (int i = 7; i <= n; i += 2)
    {
        bool tmp = true;
        for (int j = 3; j <= sqrt(i); j += 2)
        {
            if (i % j == 0)
            {
                tmp = false;
                break;
            }
        }
        if (tmp == true)
            answer++;
    }
    return answer;
}
