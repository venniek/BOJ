#include <iostream>
#define LL long long
using namespace std;

LL multi(LL a, LL b, LL c)
{
	if (b == 1)
		return (a % c);
	if (b % 2 == 0)
		return ((multi(a, b / 2, c) % c * multi(a, b / 2, c) % c) % c);
	else
		return ((multi(a, 1, c) % c * multi(a, b - 1, c) % c) % c);
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
	LL a, b, c;
	cin >> a >> b >> c;
	cout << multi(a, b, c);
	return 0;
}
