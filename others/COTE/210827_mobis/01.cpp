#include <string>
#include <vector>

using namespace std;
vector<int> numbers;
int done[10000];
int tmp;
int n;

void make_tmp()
{
    for (int i = 0; i < n; i++)
    {
        int tmp = numbers[i];
        done[tmp] = 1;
        if (n > 1)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                tmp = tmp * 10 + numbers[j];
                done[tmp] = 1;
                if (n > 2)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (i == k || j == k) continue;
                        tmp = tmp * 10 + numbers[k];
                        done[tmp] = 1;
                        if (n > 3)
                            done[tmp * 10 + numbers[6 - (i + j + k)]] = 1;
                        tmp = (tmp - numbers[k]) / 10;
                    }
                }
                tmp = (tmp - numbers[j]) / 10;   
            }
        }
    }
}

void make_numbers(vector<vector<int> > dice, int row)
{
    if (row == n)
    {
        make_tmp();
        return ;
    }
    for (int i = 0; i < 6; i++)
    {
        numbers.push_back(dice[row][i]);
        make_numbers(dice, row + 1);
        numbers.pop_back();
    }
}

int solution(vector<vector<int>> dice) {
    int answer = 0;
    
    n = dice.size();
    make_numbers(dice, 0);
    for (int i = 1; i < 10000; i++)
    {
        if (done[i] == 0)
        {
            answer = i;
            break;
        }   
    }
    return answer;
}

