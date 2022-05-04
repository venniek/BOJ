#include <string>
#include <vector>
using namespace std;

int erase_square(int m, int n, vector<string>& board) {
    int erase[35][35] = {0, };
    int flag = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int k = 0; k < n - 1; k++) {
            if (board[i][k] != 'a' && board[i][k] == board[i][k + 1]) {
                if (board[i][k] == board[i + 1][k]) {
                    if (board[i][k] == board[i + 1][k + 1]) {
                        erase[i][k] = 1;
                        erase[i][k + 1] = 1;
                        erase[i + 1][k] = 1;
                        erase[i + 1][k + 1] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            if (erase[i][k] == 1) {
                flag = 1;
                board[i][k] = 'a';
            }
        }
    }
    return flag;
}

void fill_under(int m, int n, vector<string>& board) {
    for (int i = m - 1; i >= 0; i--) {
        for (int k = n - 1; k >= 0; k--) {
            if (board[i][k] == 'a') {
                for (int j = i - 1; j >= 0; j--) {
                    if (board[j][k] != 'a') {
                        board[i][k] = board[j][k];
                        board[j][k] = 'a';
                        break ;
                    }
                }
            }
        }
    }
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (erase_square(m, n, board)) {
        fill_under(m, n, board);
    }
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            if (board[i][k] == 'a')
                answer++;
        }
    }
    return answer;
}