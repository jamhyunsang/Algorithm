#include <vector>
#include <queue>

using namespace std;

int BFS(int start, const int n, const vector<vector<int>>& map)
{
    vector<bool> Visited(n + 1);
	queue<int> Q;
	Visited[start] = true;
	Q.push(start);

	int Count = 0;
    while (!Q.empty())
    {
		int Front = Q.front();
        Q.pop();

        for (int i = 0; i < map[Front].size(); i++)
        {
			int Visit = map[Front][i];
            if(Visited[Visit])
				continue;
			
			Visited[Visit] = true;
			Q.push(Visit);
			Count++;
        }
    }

	return Count;
}

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;

	vector<vector<int>> WinMap(n + 1);
	vector<vector<int>> LoseMap(n + 1);

    for (int count = 0; count < results.size(); count++)
    {
		int Win = results[count][0];
		int Lose = results[count][1];
        WinMap[Win].push_back(Lose);
        LoseMap[Lose].push_back(Win);
    }

    for (int count = 1; count <= n; count++)
    {
        int WinCount = BFS(count, n, WinMap);
		int LoseCount = BFS(count, n, LoseMap);

        if (WinCount + LoseCount == n - 1)
			answer++;
    }

    return answer;
}