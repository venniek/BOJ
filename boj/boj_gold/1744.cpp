#include <iostream>
#include <algorithm>
using namespace std;
int N;
int ans;
int visited[55];
int num[55];

int main()
{
    cin>> N;
    
    for (int i = 0; i < N; i++)
        cin >> num[i];
    sort(num, num+N);
    for (int i = 0; i < N-1 && num[i] < 1 && num[i + 1] < 1; i += 2)
    {
        ans += num[i] * num[i + 1];
        visited[i] = 1;
        visited[i + 1] = 1;
    }
    for (int i = N - 1; i >= 1 && num[i] > 1 && num[i - 1] > 1; i -= 2)
    {
        ans += num[i] * num[i - 1];
        visited[i] = 1;
        visited[i - 1] = 1;
    }
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 0)
            ans += num[i];
    }
    cout << ans;
    return 0;
}
