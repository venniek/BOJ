#include <iostream>

using namespace std;

void hanoi(int start, int end, int num)
{
	if (num == 0)
		return ;
	hanoi(start, 6 - start - end, num - 1);
	cout << start << " " << end << '\n';
	hanoi(6 - start - end, end, num - 1);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	int n;
    cin >> n;
	cout << (1<<n) - 1 << '\n';
	hanoi(1, 3, n);
	return 0;
}

