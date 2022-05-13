#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int a[4] = {1, 1, -1, -1};
int b[4] = {-1, 1, 1, -1};

int check_distance(vector<string> map, int i, int k) {
    for (int j = 0; j < 4; j++) {
        int nx = k + dx[j];
        int ny = i + dy[j];
        if (nx < 0 || ny < 0 || nx > 4 || ny > 4 || map[ny][nx] == 'X')
            continue;
        if (map[ny][nx] == 'P')
            return 1;
        if (nx + dx[j] < 0 || ny + dy[j] < 0 || nx + dx[j] > 4 || ny + dy[j] > 4)
            continue;
        if (map[ny + dy[j]][nx + dx[j]] == 'P')
            return 1;
    }
    for (int j = 0; j < 4; j++) {
        if (i + a[j] < 0 || i + a[j] > 4 || k + b[j] < 0 || k + b[j] > 4)
            continue;
        if (map[i + a[j]][k + b[j]] == 'P') {
            if (!(map[i][k + b[j]] == 'X' && map[i + a[j]][k] == 'X'))
                return 1;
        }
    }
    return 0;
}

int check(vector<string> map) {
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            if (map[i][k] == 'P' && check_distance(map, i, k))
                    return 0;
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (vector<string> map: places)
        answer.push_back(check(map));
    return answer;
}
