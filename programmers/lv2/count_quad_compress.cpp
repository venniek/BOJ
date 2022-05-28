#include <string>
#include <vector>
using namespace std;

int one;
int zero;

void check_quad(vector<vector<int> > &arr, int r, int c, int n) {
    int tmp = arr[r][c];
    if (n != 1) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (arr[r + i][c + k] != tmp) {
                    check_quad(arr, r, c, n / 2);
                    check_quad(arr, r + n / 2, c, n / 2);
                    check_quad(arr, r, c + n / 2, n / 2);
                    check_quad(arr, r + n / 2, c + n / 2, n / 2);
                    return ;
                }
            }
        }
    }
    if (tmp == 1) one++;
    else zero++;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    check_quad(arr, 0, 0, arr.size());
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}
