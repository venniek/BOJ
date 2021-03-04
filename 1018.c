#include <stdio.h>
#include <stdlib.h>

char **board;
int case1[8][8];
int case2[8][8];

int make_ans(int c[8][8], int i, int k)
{
    int ret = 0;

    for (int j = 0; j < 8; j++)
    {
        for (int t = 0; t < 8; t++)
        {
            if (c[j][t] + '0' != board[i + j][k + t])
                ret++;
        }
    }
    return (ret);
}

void make_min(int *min, int n, int m)
{
    int ans;

    for (int i = 0; i < n - 7; i++)
    {
        for (int k = 0; k < m - 7; k++)
        {
            if ((ans = make_ans(case1, i, k)) < *min)
                *min = ans;
            if ((ans = make_ans(case2, i, k)) < *min)
                *min = ans;
        }
    }
}

void make_case()
{
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			if ((i + k) % 2 == 0)
			{
				case1[i][k] = 1;
				case2[i][k] = 0;
			}
			else
			{
				case1[i][k] = 0;
				case2[i][k] = 1;
			}
		}
	}
}

void make_board(int n, int m)
{
    board = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
        board[i] = (char *)malloc(sizeof(char) * (m + 1));
    for (int i = 0; i < n; i++)
        scanf("%s", board[i]);
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            if (board[i][k] == 'W')
                board[i][k] = 1 + '0';
            else
                board[i][k] = 0 + '0';
        }
    }
}

int main()
{
	int n, m;
    int min = 64;

	make_case();
	scanf("%d %d", &n, &m);
	make_board(n, m);
    make_min(&min, n, m);
    printf("%d", min);
    for (int i = 0; i < 8; i++)
        free(board[i]);
   free(board);

	return 0;
}