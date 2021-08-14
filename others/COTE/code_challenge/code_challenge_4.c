
int diff(long long a, long long b)
{
    int bia[50] = { 0 };
    int bib[50] = { 0 };
    int dif = 0;

    for (int i = 49; i >= 0 && a > 0; i--)
    {
        bia[i] = a % 2;
        a /= 2;
    }
    for (int i = 49; i >= 0 && b > 0; i--)
    {
        bib[i] = b % 2;
        b /= 2;
    }
    for (int i = 49; i >= 0 && dif < 3; i--)
        dif += bia[i] == bib[i] ? 0 : 1;
    return (dif);
}


int main()
{
	long long numbers[100000];
	long long answer[100000];

	for (int i = 0; i < 100000; i++)
		numbers[i] = i;
    for (int i = 0; i < 100000; i++)
    {
        long long k = 1;
        while (diff(numbers[i], numbers[i] + k) > 2)
            k++;
        answer[i] = numbers[i] + k;
    }
	int t = 0;
	for (int i = 0; i < 100000; i++)
	{
		printf("%5lld ", answer[i] - numbers[i]);
		t++;
		if (t == 64)
		{
			printf("\n");
			t = 0;
		}
	
	}
	return 0;
}
