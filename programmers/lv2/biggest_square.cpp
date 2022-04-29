#include <iostream>
#include <vector>
using namespace std;
int d[1005][1005];

int solution(vector<vector<int> > board)
{
    int mx = 0;

	for (int i = 0; i < board.size(); i++)
    {
		d[i][0] = board[i][0];
        mx = max(mx, d[i][0]);
    }
	for (int i = 0; i < board[0].size(); i++)
	{
		d[0][i] = board[0][i];
		mx = max(mx, d[0][i]);
	}
    for (int i = 1; i < board.size(); i++)
		for (int j = 1; j < board[i].size(); j++)
		{
			if(board[i][j] == 1)
            {
                d[i][j] = min(d[i - 1][j - 1], min(d[i - 1][j], d[i][j - 1])) + 1;
                mx = max(mx, d[i][j]);
            }	
		}
    return mx * mx;
}
