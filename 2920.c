#include <stdio.h>


int is_ascen(int n[8])
{
	for (int i = 0; i < 8; i++)
		if (n[i] != i + 1) return (-1);
	return 0;
}

int is_descen(int n[8])
{
	for (int i = 0; i < 8; i++)
		if (n[i] != 8 - i) return (-1);
	return 0;
}

int main()
{
	int n[8];
	int ans = 3;
	char *s;

	for (int i = 0; i < 8; i++)
		scanf("%d", &n[i]);
	if (is_ascen(n) == 0)
		ans = 1;
	else if (is_descen(n) == 0)
		ans = 2;
	if (ans == 1)
		s = "ascending"; 
	else if (ans == 2)
		s = "descending";
	else if (ans == 3)
		s = "mixed";
	printf("%s", s);
	return 0;
}
