#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int DirectionX[] = { -1, 0 };
int DirectionY[] = { 0, -1 };
vector<vector<int>> Map;

int solution(int m, int n, vector<vector<int>> puddles)
{
    Map = vector<vector<int>>(101, vector<int>(101, 1));

    for (int count = 0; count < puddles.size(); count++)
    {
        Map[puddles[count][1]][puddles[count][0]] = -1;
    }

    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            if (x == 1 && y == 1 || Map[y][x] == -1)
                continue;

            int Sum = 0;
            for (int count = 0; count < 2; count++)
            {
                int PrevX = x + DirectionX[count];
                int PrevY = y + DirectionY[count];

                if (PrevX <= 0 || PrevY <= 0)
                    continue;

                if (Map[PrevY][PrevX] == -1)
                    continue;

                Sum += Map[PrevY][PrevX];
            }

            Map[y][x] = Sum % 1000000007;
        }
    }

    return Map[n][m];
}