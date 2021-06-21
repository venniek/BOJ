#include <iostream>
#include <vector>

using namespace std;


long long multi(long long a, long long b, long long c)
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
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld", multi(a, b, c));
	return 0;
}
