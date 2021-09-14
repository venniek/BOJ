#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int is_prime(long long n)
{
    if (n == 2 || n == 3 || n == 5)
        return 0;
    if (n == 1 || n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
        return 1;
    for (int i = 7; i <= sqrt(n); i += 2)
        if (n % i == 0 && n != i) return 1;
    return 0;
}

int solution(int n, int k) {
    int answer = 0;
    string newnum;
    
    while (n > 0)
    {
        newnum += n % k + '0';
        n /= k;
    }
    if (newnum.size() > 1)
        reverse(newnum.begin(), newnum.end());
    int i = 0;
    while (1)
    {
        if (newnum[i] == '\0')
            break;
        string num;
        while (newnum[i] != '\0' && newnum[i] == '0')
            i++;
        while (newnum[i] != '\0' && newnum[i] != '0')
            num += newnum[i++];
        if (num.size() == 0)
            continue;
        if (is_prime(stoll(num)) == 0)
            answer++;
    }
    return answer;
}
