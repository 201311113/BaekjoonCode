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
using namespace std;			//�� ������ �迭�� ��簪�� �˻��ϰ� 1���� ������ bfs�� ���� ���� ������� ǥ�ø�  
int N;							//�������ν�  �ذᰡ���ϴ� ������ ���� �� ������ ũ�⸦ �����Ͽ� ������������ ǥ��
int map[26][26];				//���־�� �ϴ� ���ε� �̴� vector�� ���� �����Ͽ� sort���ִ� ������ ���� �ذ��ߴ�
int chk[26][26];
int vil_num = 0;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
vector<int> cnt_file;
void bfs(int x, int y) {
	int cnt = 1;
	vil_num += 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	chk[x][y] = vil_num;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < N && yy < N && !chk[xx][yy] && map[xx][yy] == 1) {
				chk[xx][yy] = vil_num;
				cnt++;
				q.push(make_pair(xx, yy));
			}
		}
	}
	cnt_file.push_back(cnt);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[j][i]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] == 1 && !chk[j][i]) {
				bfs(j, i);
			}
		}
	}

	cout << vil_num << endl;
	sort(cnt_file.begin(), cnt_file.end());
	for (int i = 0; i < cnt_file.size(); i++) {
		cout << cnt_file[i] << endl;
	}
}