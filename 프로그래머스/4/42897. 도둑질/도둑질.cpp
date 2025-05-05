#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money)
{
    int n = money.size();
    
    vector<int> DP1(n,0);
    DP1[0] = money[0];
    DP1[1] = money[0];
    for(int i = 2; i < n - 1; i++)
    {
        DP1[i] = max(DP1[i - 1], DP1[i - 2] + money[i]);
    }
    
    vector<int> DP2(n,0);
    DP2[1] = money[1];
    for(int i = 2; i < n; i++)
    {
        DP2[i] = max(DP2[i - 1], DP2[i - 2] + money[i]);
    }
    
    return max(DP1[n-2], DP2[n-1]);
}