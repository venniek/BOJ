#include <iostream>
#include <cmath>
using namespace std;

int ori_r;
int ori_c;

void recur_z(int r, int c, int now, int num) {
    int i = pow(2, now);
    if (ori_r < r || ori_r >= r + i || ori_c < c || ori_c >= c + i)
        return ;
    if (now == 0 && r == ori_r && c == ori_c) {
        cout << num;
        return ;
    }
    i /= 2;
    int n = pow(i, 2);
    recur_z(r, c, now - 1, num);
    recur_z(r, c + i, now - 1, num + n);
    recur_z(r + i, c, now - 1, num + n * 2);
    recur_z(r + i, c + i, now - 1, num + n * 3);
}

int main() {
    int n;

    cin >> n >> ori_r >> ori_c;
    recur_z(0, 0, n, 0);
}