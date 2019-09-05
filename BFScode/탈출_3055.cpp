#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int R, C;
char map[51][51];
int chk[51][51];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
vector<pair<int, int>> Water;
int main() {
	cin >> R >> C;
	queue<pair<int, int>> q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[j][i];
			if (map[j][i] == 'S') {
				q.push({ j,i });
				chk[j][i] = 1;
				map[j][i] = '.';
			}
			else if (map[j][i] == '*') {
				Water.push_back({ j,i });
			}
		}
	}
	int ans = -1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second, cnt = chk[x][y];
		q.pop();
		if (map[x][y] == 'D') {	//도착
			ans = cnt - 1;
			break;
		}
		char tmp[51][51]; //복사할 친구
		memcpy(tmp, map, sizeof(tmp));
		vector<pair<int, int>> wtmp = Water;
		for (int i = 0; i < cnt; i++) {	//tmp에 물채우기
			vector<pair<int, int>> wwtmp;
			for (int j = 0; j < wtmp.size(); j++) {
				int wx = wtmp[j].first, wy = wtmp[j].second;
				for (int k = 0; k < 4; k++) {
					int wwx = wx + dir[k][0], wwy = wy + dir[k][1];
					if (wwx >= 0 && wwy >= 0 && wwx < C && wwy < R && tmp[wwx][wwy] == '.') {
						tmp[wwx][wwy] = '*';
						wwtmp.push_back({ wwx,wwy });
					}
				}
			}
			wtmp.clear();
			wtmp = wwtmp;
		}

		for (int i = 0; i < 4; i++) {	// 고슴도치움직임
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < C && yy < R && chk[xx][yy] == 0 && (tmp[xx][yy] == '.' || tmp[xx][yy] == 'D')) {
				q.push({ xx,yy });
				chk[xx][yy] = chk[x][y] + 1;
			}
		}
		//물빼기는 자동으로
	}
	if (ans == -1) {
		cout << "KAKTUS";
	}
	else {
		cout << ans;
	}
}