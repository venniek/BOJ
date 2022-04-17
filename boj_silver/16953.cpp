#include <iostream>
using namespace std;

int done = 0;
int ans;

void multi_2(long long a, int b, int cnt);
void append_1(long long a, int b, int cnt);

void multi_2(long long a, int b, int cnt) {
	if (done == 1)
		return;
	a *= 2;
	cnt++;
	if (b == a) {
		ans = cnt;
		done = 1;
		return ;
	}
	if (b < a)
		return ;
	multi_2(a, b, cnt);
	append_1(a, b, cnt);
}

void append_1(long long a, int b, int cnt) {
	if (done == 1)
		return;
	a = a * 10 + 1;
	cnt++;
	if (b == a) {
		ans = cnt;
		done = 1;
		return ;
	}
	if (b < a)
		return ;
	multi_2(a, b, cnt);
	append_1(a, b, cnt);
}

int main() {
	int a, b;

	cin >> a >> b;
	multi_2(a, b, 0);
	append_1(a, b, 0);
	if (ans == 0)
		ans = -2;
	cout << ans + 1;
}