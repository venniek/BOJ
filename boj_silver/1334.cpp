#include <iostream>
#include <cstring>

using namespace std;

char str[52];

void plus_one(int *len)
{
	int olim = 1;
	for (int i = *len - 1; i >= 1; i--)
	{
		if (str[i] + olim > '9')
		{
			str[i] = '0';
			olim = 1;
		}
		else
		{
			str[i] = str[i] + olim;
			olim = 0;
		}
	}
	if (str[0] + olim > '9')
	{
		str[0] = '0';
		for (int i = *len; i > 0; i--)
			str[i] = str[i - 1];
		str[0] = '1';
		(*len)++;
	}
	else
		str[0] = str[0] + olim;
}

int main()
{
	cin >> str;
	int len = strlen(str);

	plus_one(&len);
	int mid1 = (len - 1) / 2;
	int mid2 = len % 2 == 0 ? mid1 + 1: mid1;
	int i = 0;
	while (str[mid1 - i] == str[mid2 + i])
		i++;
	if (str[mid1 - i] < str[mid2 + i])
	{
		int tmp = mid1 + 1;
		plus_one(&tmp);
	}	
	for (int k = len - 1; k > mid1; k--)
		str[k] = str[len - k - 1];
	cout << str;
	return 0;
}
