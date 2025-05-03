#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker)
{
    int n = sticker.size();

    if (n == 1)
        return sticker[0];

    vector<int> DP1(n, 0);
    DP1[0] = sticker[0];
    DP1[1] = sticker[0];
    for (int i = 2; i < n - 1; i++)
    {
        DP1[i] = max(DP1[i - 1], DP1[i - 2] + sticker[i]);
    }

    vector<int> DP2(n, 0);
    DP2[1] = sticker[1];
    for (int i = 2; i < n; i++)
    {
        DP2[i] = max(DP2[i - 1], DP2[i - 2] + sticker[i]);
    }

    return max(DP1[n - 2], DP2[n - 1]);
}