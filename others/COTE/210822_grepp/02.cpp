#include <string>
#include <vector>
#include <iostream>
using namespace std;

int map[101][101];

int solution(int n, int m, int k) {
    int answer = -1;
    
    if (n > m)
        return 0;
    if (m / k > n)
        return 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= i && j <= n; j++)
        {
            if ((j == 1 && i <= k) || i == j)
            {
                map[i][j] = 1;
                continue;
            }
            for (int l = 1; l <= k && l < i; l++)
                map[i][j] += map[i - l][j - 1];
            map[i][j] %= 1000007;
        }
    }
    answer = map[m][n];
    return answer;
}
