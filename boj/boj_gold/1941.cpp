#include <iostream>
#include <vector>
#include <queue>

using namespace std;
string board[5];
int connect[25][25];
int total, som, ans;
vector<int> in;

void make_connect()
{
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            if ((i - j == 1 && i % 5 != 0) || (j - i == 1 && j % 5 != 0))
                connect[i][j] = 1;
            if (i - j == 5 || j - i == 5)
                connect[i][j] = 1;
        }
    }
}

int is_connect()
{
    int cnt = 0;
    int done[7] = {0, };
    queue<int> q;

    q.push(in[0]);
    done[0] = 1;
    while (!q.empty())
    {
        int now = q.front(); q.pop();
        cnt++;
        for (int i = 1; i < in.size(); i++)
        {
            if (done[i] == 0 && connect[now][in[i]] == 1)
            {
                q.push(in[i]);
                done[i] = 1;
            }
        }
    }
    return cnt == 7 ? 1 : 0;
}

void dfs(int row, int col)
{
    if (total == 7)
    {
        if (som >= 4 && is_connect() == 1)
            ans++;
        return ;
    }
    for (int i = row; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            if (i == row && j <= col)
                continue;
            total++;
            if (board[i][j] == 'S')
                som++;
            in.push_back(i * 5 + j);
            dfs(i, j);
            total--;
            if (board[i][j] == 'S')
                som--;
            in.pop_back();
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    make_connect();
    for (int i = 0; i < 5; i++)
        cin >> board[i];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            total = 1;
            som = 0;
            if (board[i][j] == 'S')
                som++;
            in.push_back(i * 5 + j);
            dfs(i, j);
            in.pop_back();
        }
    cout << ans;
    return 0;
}