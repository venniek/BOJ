#include <string>
#include <vector>
#include <iostream>
using namespace std;

int tmp[11];
int ans[11];
int maxscore;

int cmp_score(vector<int> info)
{
    int ryan = 0;
    int apeach = 0;
    
    for (int i = 0; i < 10; i++)
    {
        if (info[i] != 0 && info[i] >= tmp[i])
            apeach += 10 - i;
        else if (tmp[i] != 0)
            ryan += 10 - i;
    }
    return (ryan - apeach);
}

void cmp_max()
{
	for (int i = 10; i >= 0; i--)
	{
		if (tmp[i] > ans[i])
		{
			for (int j = 0; j < 11; j++)
				ans[j] = tmp[j];
			break;
		}
	}
}

void make_score(int n, vector<int> info, int now)
{
    if (n == 0 || now == 11)
    {
        if (n != 0)
            tmp[now - 1] = n;
		int temp = cmp_score(info);
		if (temp != 0 && temp == maxscore)
			cmp_max();
		else if (temp > maxscore)
        {
            maxscore = temp;
            for (int i = 0; i < 11; i++)
                ans[i] = tmp[i];
        }
        return ;
    }
    if (info[now] + 1 <= n)
    {
        tmp[now] = info[now] + 1;
        make_score(n - tmp[now], info, now + 1);
    }
    tmp[now] = 0;
    make_score(n, info, now + 1);
	tmp[now] = 0;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    make_score(n, info, 0);
    if (maxscore == 0)
        answer.push_back(-1);
    else
    {
        for (int i = 0; i < 11; i++)
            answer.push_back(ans[i]);
    }
    return answer;
}


int main()
{
	int n = 2;
	vector<int> info;
	vector<int> answer;
	
	info.push_back(2);
	for (int i = 0; i < 10; i++)
		info.push_back(0);
	answer = solution(n, info);
	for (int i = 0; i < 11; i++)
		cout << answer[i] << " ";
	return 0;
}
