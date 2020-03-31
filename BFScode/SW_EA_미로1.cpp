#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
char arr[17][17];
bool chk[17][17];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int num;
		cin >> num;
		memset(arr, 0, sizeof(arr));
		memset(chk, 0, sizeof(chk));
		pair<int, int> start, arrival;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				cin >> arr[j][i];
				if (arr[j][i] == '2') {
					start = { j,i };
				}
				else if (arr[j][i] == '3') arrival = { j,i };
			}
		}
		queue<pair<int, int>> q;
		q.push(start);
		bool flag = 0;
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			if (arrival == q.front()) {
				flag = 1;
				break;
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dir[i][0], yy = y + dir[i][1];
				if (xx >= 0 && yy >= 0 && xx < 16 && yy < 16 && !chk[xx][yy] && (arr[xx][yy] == '0' || arr[xx][yy] == '3')) {
					chk[xx][yy] = 1;
					q.push({ xx,yy });
				}
			}
		}
		if (flag) cout << "#" << test_case << " " << flag << endl;
		else cout << "#" << test_case << " " << flag << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}