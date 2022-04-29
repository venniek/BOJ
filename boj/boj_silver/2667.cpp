#include <iostream>
#include <utility>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define X second
#define Y first
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int N, tmp;
string map[26];
int    done[26][26];
vector<int> ans;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> map[i];
    stack<pair<int, int> > S;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (done[i][j] != 1 && map[i][j] != '0')
			{
				S.push(make_pair(i, j));
				done[i][j] = 1;
				tmp = 0;
				while (!S.empty())
				{
					pair<int, int> cur = S.top();
					S.pop();
					tmp++;
					for (int i = 0; i < 4; i++)
					{
						int nowy = cur.Y + dy[i];
						int nowx = cur.X + dx[i];
						if (nowx < 0 || nowx >= N || nowy < 0 || nowy >= N)
							continue;
						if (done[nowy][nowx] || map[nowy][nowx] == '0')
							continue;
						done[nowy][nowx] = 1;
						S.push(make_pair(nowy, nowx));
					}
				}
				ans.push_back(tmp);
			}
		}

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
