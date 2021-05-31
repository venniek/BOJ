#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* number, int k) {
    int len = strlen(number);
    char* answer = (char*)malloc(len - k + 1);
    int max = 0;
    
    for (int j = 0; j < len - k; j++)
    {
        for (int i = max + 1; i < k + j + 1; i++)
        {
            if (number[max] < number[i])
                max = i;
        }
        answer[j] = number[max];
        max++;
    }
    answer[len - k] = '\0';
    return answer;
}
