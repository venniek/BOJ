#include <iostream>

using namespace std;


int count(int n) 
{
    int i;
    for(i=0;n!=0;i++) {
        n&=(n-1);
    }
    return i;
}

int main()
{
	int n, k;
	int ncpy;

	cin >> n >> k;
	ncpy = n;
	while (count(n) > k)
		n++;
	cout << n - ncpy;
	return 0;
}
