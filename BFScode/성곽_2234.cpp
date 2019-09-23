#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<ctime>
#include<set>
using namespace std;
int n, m;
struct node {
	bool east;
	bool south;
	bool north;
	bool west;
};
node map[50][50];		//���ִ� ���ڿ� 1
bool chk[50][50];
short map_cnt[50][50];
void cal(int x, int y, int n) {
	if (n - 8 >= 0) {
		map[x][y].south = 1;
		n -= 8;
	}

	if (n - 4 >= 0) {
		map[x][y].east = 1;
		n -= 4;
	}
	if (n - 2 >= 0) {
		map[x][y].north = 1;
		n -= 2;
	}
	if (n == 1) {
		map[x][y].west = 1;
	}
}
int max_r_size = 0;		//���� ū ��ũ�� ���� ����
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
vector<int> v;
int max_s_room = 0;
void is_attach() {
	memset(chk, 0, sizeof(chk));
	queue < pair<int, int> > q;
	q.push(make_pair(0, 0));
	chk[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < n && yy < m && !chk[xx][yy]) {
				if (map_cnt[x][y] != map_cnt[xx][yy]) {					//����ģ�� ����ū���� ������ �ʱ�ȭ
					int sum = v[map_cnt[x][y] - 1] + v[map_cnt[xx][yy] - 1];
					max_s_room = max(max_s_room, sum);
				}
				q.push(make_pair(xx, yy));
				chk[xx][yy] = 1;
			}
		}
	}
}
void BFS(int x, int y, int r_cnt) {
	int cnt = 1;	//�� ũ�� ���� ����
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	chk[x][y] = 1;
	map_cnt[x][y] = r_cnt;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < n && yy < m && !chk[xx][yy]) {
				if (i == 0 && map[x][y].east == 0) {			//�����⸶�� ��Ȯ���� push �� �� �� �� ��(dir[][])
					q.push(make_pair(xx, yy));
					chk[xx][yy] = 1;
					cnt++;
					map_cnt[xx][yy] = r_cnt;
				}
				else if (i == 1 && map[x][y].south == 0) {
					q.push(make_pair(xx, yy));
					chk[xx][yy] = 1;
					cnt++;
					map_cnt[xx][yy] = r_cnt;
				}
				else if (i == 2 && map[x][y].west == 0) {
					q.push(make_pair(xx, yy));
					chk[xx][yy] = 1;
					cnt++;
					map_cnt[xx][yy] = r_cnt;
				}
				else if (i == 3 && map[x][y].north == 0) {
					q.push(make_pair(xx, yy));
					chk[xx][yy] = 1;
					cnt++;
					map_cnt[xx][yy] = r_cnt;
				}

			}
		}
	}
	max_r_size = max(max_r_size, cnt);		//��ũ�� �ִ�� �ʱ�ȭ
	v.push_back(cnt);						//�� ũ�� ����
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int n;
			cin >> n;
			cal(j, i, n);
		}
	}
	int r_cnt = 0;	//�� ���� ���� cnt
	for (int i = 0; i < m; i++) {			//�ѹ� ���� �˻��ؼ� max�� ũ��� ������ ����
		for (int j = 0; j < n; j++) {
			if (chk[j][i] == 0) {
				r_cnt += 1;
				BFS(j, i, r_cnt);
			}

		}
	}
	cout << r_cnt << endl << max_r_size << endl;
	is_attach();
	cout << max_s_room;
}