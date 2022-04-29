#include <iostream>
using namespace std;

int map[505][505];

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)  {
            cin >> map[i][j];
            if (i == 0)
                continue;
            else if (j == 0 || j == i)
                map[i][j] += map[i - 1][max(0, j - 1)];
            else
                map[i][j] += max(map[i - 1][j], map[i - 1][j - 1]);
        }
    }
    for (int i = 0; i < n; i++)
        map[n - 1][0] = max(map[n - 1][0], map[n - 1][i]);
    cout << map[n - 1][0];
}