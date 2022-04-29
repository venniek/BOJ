#include <stdio.h>
#include <stdlib.h>

long long make_pow(int i)
{
	long long ret = 1;

	for (int k = 0; k < i; k++)
		ret = (ret % 1234567891 * 31) % 1234567891;
	return (ret);
}

int main()
{	
	int len;
	char *s;
	long long sum = 0;

	scanf("%d", &len);
	s = (char *)malloc(sizeof(char) * (len + 1));
	scanf("%s", s);
	for (int i = 0; i < len; i++)
		sum += (s[i] - 'a' + 1) * make_pow(i);
	printf("%lld", sum % 1234567891);
	return 0;

}
