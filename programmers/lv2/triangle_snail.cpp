#include <string>
#include <vector>
using namespace std;

int map[1001][1001];
int dx[3] = {0, 1, -1};
int dy[3] = {1, 0, -1};

vector<int> solution(int n) {
    vector<int> answer;
    int num = 1;
    int x = 1, y = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            x += dx[i % 3];
            y += dy[i % 3];
            map[y][x] = num;
            num++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= i; k++)
            answer.push_back(map[i][k]);
    }
    return answer;
}
