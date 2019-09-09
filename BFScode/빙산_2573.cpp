#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int N, M;
int map[301][301];
bool chk[301][301];
vector<pair<int, int>> iceberg;
bool flag_zero_iceberg;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool chk_separate() {
	bool flag_separate = 0;
	if (iceberg.size() == 0) {
		flag_zero_iceberg = 1;
		return false;
	}
	for (int i = 0; i < iceberg.size(); i++) {
		if (!chk[iceberg[i].first][iceberg[i].second]) {
			if (flag_separate) return false;
			flag_separate = 1;
			queue<pair<int, int>> q;
			q.push({ iceberg[i].first,iceberg[i].second });
			chk[iceberg[i].first][iceberg[i].second] = 1;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int xx = x + dir[i][0], yy = y + dir[i][1];
					if (xx >= 0 && yy >= 0 && xx < M && yy < N && !chk[xx][yy] && map[xx][yy] != 0) {
						q.push({ xx,yy });
						chk[xx][yy] = 1;
					}
				}
			}
		}
	}
	memset(chk, 0, sizeof(chk));
	return true;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[j][i];
			if (map[j][i] != 0) {
				iceberg.push_back({ j,i });
			}
		}
	}
	int day = 0;
	while (chk_separate()) {
		day++;
		vector<pair<int, int>> tmp;
		int tmp_map[301][301] = { 0, };
		for (int i = 0; i < iceberg.size(); i++) {	//ºù»ê Ä­¸¶´Ù ³ìÀÌ°í °Ë»ç
			int x = iceberg[i].first, y = iceberg[i].second;
			int ocean = 0;
			for (int i = 0; i < 4; i++) {
				int xx = x + dir[i][0], yy = y + dir[i][1];
				if (xx >= 0 && yy >= 0 && xx < M && yy < N && map[xx][yy] == 0) {
					ocean++;
				}
			}
			tmp_map[x][y] = map[x][y] - ocean;
			if (tmp_map[x][y] <= 0) {// ±×Ä­¿¡ ºù»ê »ç¶óÁú¶§
				tmp_map[x][y] = 0;
			}
			else {		//³ìÀÌ°íµµ ºù»êÀÖÀ»¶§ 
				tmp.push_back({ x,y });
			}
		}
		iceberg.clear();
		iceberg = tmp;
		memcpy(map, tmp_map, sizeof(map));
	}
	if (flag_zero_iceberg) {
		cout << "0";
	}
	else {
		cout << day;
	}
}