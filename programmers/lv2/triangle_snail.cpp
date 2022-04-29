#include <string>
#include <vector>
using namespace std;

int map[1001][1001];

void dir_xy(int *x, int *y, int dir)
{
    if (dir == 0)
        *y += 1;
    else if (dir == 1)
        *x += 1;
    else
    {
        *x -= 1;
        *y -= 1;
    }
}

vector<int> solution(int n) {
    vector<int> answer;
    int num = 1;
    int x = 1, y = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            dir_xy(&x, &y, i % 3);
            map[y][x] = num;
            num++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= i; k++)
            answer.push_back(map[i][k]);
    }
    return answer;
}


// dont need dir_xy
// just divide using if
// x++, y++, x--, y-- 
