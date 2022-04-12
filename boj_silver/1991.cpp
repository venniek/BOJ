#include <iostream>
using namespace std;

int alpha[26][2];

void preorder(int start) {
	if (start < 0)
		return;
	cout << (char)(start + 'A');
	preorder(alpha[start][0]);
	preorder(alpha[start][1]);
}

void inorder(int start) {
	if (start < 0)
		return;
	inorder(alpha[start][0]);
	cout << (char)(start + 'A');
	inorder(alpha[start][1]);
}

void postorder(int start) {
	if (start < 0)
		return;
	postorder(alpha[start][0]);
	postorder(alpha[start][1]);
	cout << (char)(start + 'A');
}

int main() {
	int n;
	char p, l, r;

	cin >> n;
	while (n-- > 0) {
		cin >> p >> l >> r;
		alpha[p - 'A'][0] = l - 'A';
		alpha[p - 'A'][1] = r - 'A';
	}
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	return 0;
}