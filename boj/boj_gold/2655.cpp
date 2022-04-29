#include <iostream>
#include <algorithm>
using namespace std;

struct Brick
{
	int index;
	int area;
	int height;
	int weight;
};

bool cmp(Brick a, Brick b)
{
	if (a.weight < b.weight)
		return true;
	return false;
}

Brick br[101] = {};
int h[101];
int A[101];
int Count[101];

void print_br(int n)
{
	if (n != 0)
	{
		print_br(A[n]);
		cout << br[n].index << '\n';
	}
}

int main()
{
	int n;
	int max_height = 0;
	int max_index = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		br[i].index = i;
		cin >> br[i].area >> br[i].height >> br[i].weight;
	}
	sort(br + 1, br + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (br[i].area > br[j].area)
			{
				if (h[i] < h[j] + br[i].height)
				{
					h[i] = h[j] + br[i].height;
					A[i] = j;
					Count[i] = Count[j] + 1;
				}
			}
		}
		if (h[i] > max_height)
		{
			max_height = h[i];
			max_index = i;
		}
	}
	cout << Count[max_index] << '\n';
	print_br(max_index);
	return 0;
}