#include <iostream>
using namespace std;

int map[128][128];
int one = 0;
int zero = 0;

void quadtree(int n, int y, int x)
{
    int curr = map[y][x];
    if (n == 1)
    {
         if (curr == 1)
                    one++;
                else
                    zero++;
        return ;
    }
    for (int i = y; i < y + n; i++)
    {
        for (int k = x; k < x + n; k++)
        {
            if (map[i][k] != curr)
            {

                quadtree(n / 2, y, x);
                quadtree(n / 2, y, x + n / 2);
                quadtree(n / 2, y + n / 2, x);
                quadtree(n / 2, y + n / 2, x + n / 2);
                return ;
            }
            else if (i == y + n - 1 && k == x + n - 1)
            {
                if (curr == 1)
                    one++;
                else
                    zero++;
            }
        }

    }
}

int main()
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
            cin >> map[i][k];
    }
    quadtree(n, 0, 0);
    cout << zero << '\n';
    cout << one;
    return 0;
}
