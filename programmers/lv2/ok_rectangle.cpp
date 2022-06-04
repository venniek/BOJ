using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) 
		return b; 
    return gcd(b, a % b);
}

long long solution(int w,int h) {
	return (long long)w * h - (w + h - gcd(w, h));
}

