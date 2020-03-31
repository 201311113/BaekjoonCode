#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char arr[304][304];
int dir[8][2] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1} };
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		memset(arr, 0, sizeof(arr));
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[j][i];
				if (arr[j][i] == '*') {
					q.push({ j,i });
				}
			}
		}
		int ans = 0;
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int xx = x + dir[i][0], yy = y + dir[i][1];
				if (xx >= 0 && yy >= 0 && xx < n && yy < n && arr[xx][yy] == '.') {
					ans++;
					arr[xx][yy] = 'd';
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[j][i] == '.') {
					ans++;
					q.push({ j,i });
					while (!q.empty()) {
						int x = q.front().first, y = q.front().second;
						q.pop();
						for (int i = 0; i < 8; i++) {
							int xx = x + dir[i][0], yy = y + dir[i][1];
							if (xx >= 0 && yy >= 0 && xx < n && yy < n) {
								if (arr[xx][yy] == '.') {
									q.push({ xx,yy });
									arr[xx][yy] = 'c';
								}
								else if (arr[xx][yy] == 'd') {
									arr[xx][yy] = 'c';
									ans--;
								}
							}
						}
					}
				}
			}
		}
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}