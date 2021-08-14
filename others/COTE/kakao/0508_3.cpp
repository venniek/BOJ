#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    int *list;
    int *del;
    int rec_i = k;
    int del_i = 0;
    int size = cmd.size();
    int last_i = n - 1;
    
    list = (int *)malloc(sizeof(int) * n);
    del = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        list[i] = 1;
    for (int i = 0; i < size; i++)
    {
        if (cmd[i][0] == 'U')
        {
            int num = 0;
            int numi = 1;
            while (cmd[i][++numi] != '\0')
                num = num * 10 + cmd[i][numi] - '0';
            for (int t = 0; t < num; t++)
                while (list[--rec_i] == 0) ;
        }
        else if (cmd[i][0] == 'D')
        {
            int num = 0;
            int numi = 1;
            while (cmd[i][++numi] != '\0')
                num = num * 10 + cmd[i][numi] - '0';
            for (int t = 0; t < num; t++)
                while (list[++rec_i] == 0) ;
        }
        else if (cmd[i][0] == 'C')
        {
            list[rec_i] = 0;
            del[del_i++] = rec_i;
            if (rec_i == last_i)
            {
                while (list[--rec_i] == 0) ;
                last_i = rec_i;
            }
            else
                while (list[++rec_i] == 0) ;
        }
        else if (cmd[i][0] == 'Z')
        {
            list[del[--del_i]] = 1;
            if (del[del_i] > last_i)
                last_i = del[del_i];
        }
    }
    for (int i = 0; i < n; i++)
        answer += list[i] == 1 ? 'O' : 'X';

    return answer;
}
