#include <iostream>
#include <string>
using namespace std;

int map[5][5];
bool visit[1000000] = { 0 };

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

void ss(int n,int k, int I, int J)
{
	if (n == 5)
	{
		visit[k] = true;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int x = I + dx[i];
		int y = J + dy[i];
		if (x < 0 || x >= 5 || y < 0 || y >= 5)continue;
		ss(n + 1, k * 10 + map[x][y], x, y);
	}

}

int main()
{
	for (int i = 0; i < 5; i++)for (int j = 0; j < 5; j++)cin >> map[i][j];
	for (int i = 0; i < 5; i++)for (int j = 0; j < 5; j++)ss(0, map[i][j], i, j);
	int cnt = 0;
	for (int i = 0; i < 1000000; i++)if (visit[i])cnt++;
	cout << cnt;
}
