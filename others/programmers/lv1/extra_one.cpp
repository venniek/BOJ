#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 1)
            return i;
    }
    return n - 1;
}
