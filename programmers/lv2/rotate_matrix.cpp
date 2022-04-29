#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int map[105][105];
vector<int> solution(int rows, int columns, vector<vector<int> > queries) {
    vector<int> answer;

	int num = 1;
    for(int i = 1; i <= rows; i++)
        for(int j = 1; j <= columns; j++)
            map[i][j] = num++;
    for(int i = 0; i < queries.size(); i++)
    {
        int x1 = queries[i][0];
        int y1 = queries[i][1];
		int x2 = queries[i][2];
		int y2 = queries[i][3];
        int tmp = map[x1][y1];
		int mn = tmp;

		for (int j = x1; j < x2; j++)
        {
			map[j][y1] = map[j + 1][y1];
            mn = min(mn, map[j][y1]);
        }
		for (int j = y1; j < y2; j++)
        {
			map[x2][j] = map[x2][j + 1];
            mn = min(mn, map[x2][j]);
        }
		for (int j = x2; j > x1; j--)
		{
			map[j][y2] = map[j - 1][y2];
			mn = min(mn, map[j][y2]);
		}
		for (int j = y2; j > y1; j--)
		{
			map[x1][j] = map[x1][j - 1];
			mn = min(mn, map[x1][j]);
		}
		map[x1][y1 + 1] = tmp;
		answer.push_back(mn);
	}
    return answer;
}
