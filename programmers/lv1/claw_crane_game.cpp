#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    
    for (int i = 0; i < moves.size(); i++)
    {
        for (int k = 0; k < board.size(); k++)
        {
            int tmp = board[k][moves[i] - 1];
            if (tmp != 0)
            {
                if (s.empty() == 0 && tmp == s.top())
                {
                    s.pop();
                    answer += 2;
                }
                else
                    s.push(tmp);
                board[k][moves[i] - 1] = 0;
                break;
            }
        }
    }
    return answer;
}
