#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int done[1001];
int dismap[1001][1001];
int milemap[1001][1001];
int dismin = 2147483647, milemax = 0;
int distmp, miletmp;
int g_k, g_n;

void find_path(int n)
{
    if (n == g_k)
    {
        if (dismin > distmp)
        {
            dismin = distmp;
            milemax = miletmp;
        }
        else if (dismin == distmp)
            milemax = max(milemax, miletmp);
        return ;
    }
    done[n] = 1;
    for (int i = 1; i <= g_n; i++)
    {
        if (dismap[n][i] != 0 && done[i] == 0)
        {
            distmp += dismap[n][i];
            if (distmp > dismin)
            {
                distmp -= dismap[n][i];
                continue;
            }
            miletmp += milemap[n][i];
            find_path(i);
            done[i] = 0;
            distmp -= dismap[n][i];
            miletmp -= milemap[n][i];
        }
    }
}

vector<int> solution(int n, int k, vector<vector<int>> paths) {
    vector<int> answer;
    
    g_k = k; g_n = n;
    for (int i = 0; i < paths.size(); i++)
    {
        dismap[paths[i][0]][paths[i][1]] = paths[i][2];
        milemap[paths[i][0]][paths[i][1]] = paths[i][3];
        dismap[paths[i][1]][paths[i][0]] = paths[i][2];
        milemap[paths[i][1]][paths[i][0]] = paths[i][3];
    }
    find_path(1);
    answer.push_back(dismin);
    answer.push_back(milemax);
    return answer;
}
