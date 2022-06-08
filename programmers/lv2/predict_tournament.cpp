#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int cnt = 0;
    while (a != b) {
        ++cnt;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
    }
    return cnt;
}
