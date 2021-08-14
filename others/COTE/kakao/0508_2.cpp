#include <string>
#include <vector>
#include <iostream>

using namespace std;

int check_horizontal(int map[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (map[i][k] != 2)
                continue;
            else
            {
                if (k == 4)
                    break;
                if (map[i][k + 1] == 2)
                    return (0);
                if (k != 3 && map[i][k + 2] == 2 && map[i][k + 1] != 1)
                    return (0);
            }   
        }
    }
    return (1);
}

int check_vertical(int map[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (map[k][i] != 2)
                continue;
            else
            {
                if (k == 4)
                    break;
                if (map[k + 1][i] == 2)
                    return (0);
                if (k != 3 && map[k + 2][i] == 2 && map[k + 1][i] != 1)
                    return (0);
            }
        }
    }
    return (1);
}

int check_diagonal(int map[5][5])
{
    int check[3];
    
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            check[0] = 0;
            check[1] = 0;
            check[2] = 0;
            
            check[map[i][k]]++;
            check[map[i][k + 1]]++;
            check[map[i + 1][k]]++;
            check[map[i + 1][k + 1]]++;
            if (check[2] == 2 && check[1] != 2)
                return (0);
        }
    }
    return (1);
}

int is_safe(vector<string> places)
{
    int map[5][5];
    
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            char c = places[i][k];
            if (c == 'P')
                map[i][k] = 2;
            else if (c == 'O')
                map[i][k] = 0;
            else if (c == 'X')
                map[i][k] = 1;
        }
    }
    if (check_horizontal(map) == 0)
        return (0);
    if (check_vertical(map) == 0)
        return (0);
    if (check_diagonal(map) == 0)
        return (0);
    return (1);
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5);
    
    for (int i = 0; i < 5; i++)
        answer[i] = is_safe(places[i]);
    return answer;
}
