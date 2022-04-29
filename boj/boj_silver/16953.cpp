#include <iostream>
using namespace std;

int done = 0;
int ans;

void recur(long long a, int b, int cnt) {
	if (done == 1)
		return ;
	if (b == a) {
		ans = cnt;
		done = 1;
		return ;
	}
	if (a > b)
		return ;
	recur(a * 2, b, cnt + 1);
	recur(10 * a + 1, b, cnt + 1);
}

int main() {
	int a, b;

	cin >> a >> b;
	recur(2 * a, b, 1);
	recur(a * 10 + 1, b, 1);
	if (ans == 0)
		ans = -2;
	cout << ans + 1;
}