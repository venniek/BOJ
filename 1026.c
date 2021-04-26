#include <stdio.h>
#include <stdlib.h>

int main()
{
    int answer = 0;
    int n;
	int A[50] = { 0 };
	int B[50] = { 0 };

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &B[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int k = i + 1; k < n; k++)
            if (A[min] > A[k]) min = k;
        if (min != i)
        {
            int tmp = A[min];
            A[min] = A[i];
            A[i] = tmp;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        for (int k = i + 1; k < n; k++)
            if (B[max] < B[k]) max = k;
        if (max != i)
        {
            int tmp = B[max];
            B[max] = B[i];
            B[i] = tmp;
        }
    }
    for (int i = 0; i < n; i++)
        answer += A[i] * B[i];
    printf("%d", answer);
	return 0;
}
