#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int ai = 0;
    int bi = 0;
    
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    while (ai < A.size()) {
        if (A[ai] < B[bi])
            bi++;
        ai++;
    }
    return bi;
}
