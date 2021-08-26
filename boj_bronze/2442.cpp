#include <iostream>

using namespace std;

void print_star(int i, int n, int nl)
{
    if (i <= 2 * n - nl - 1)
        cout << ' ';
    else
        cout << '*';
    if (i == 2 * n - 1)
        return ;
    if (i == nl)
    {
        i = 0;
        nl++;
        cout << endl;
    }
    print_star(i + 1, n, nl);
}

int main()
{
    int n;

    cin >> n;
    print_star(1, n, n);
    return 0;
}
