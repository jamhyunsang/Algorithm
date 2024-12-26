#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    int size = A.size();

    for (int count = 0; count < size; count++)
        answer += A[count] * B[count];

    return answer;
}