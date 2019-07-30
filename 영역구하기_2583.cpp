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
using namespace std;									//https://www.acmicpc.net/problem/2583
int N, M, K;											//이 문제는 1.꼭지점 두개의 정보를 통해 맵을 색칠하는 로직과
struct node {											//2. 영역의 개수를 알기위해 맵전체를 검사하면서 bfs를 사용하는 
	int l_x;											//로직을 이용하면 간단히 풀 수 있다
	int l_y;
	int r_x;
	int r_y;
};
int map[100][100];		// 0이면 남은 부분 1이면 잘린 부분
queue<node> v;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
vector<int> area_size;
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	int cnt = 1;
	map[x][y] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < N && yy < M && map[xx][yy] == 0) {
				q.push(make_pair(xx, yy));
				map[xx][yy] = 1;
				cnt++;
			}
		}
	}
	area_size.push_back(cnt);
}
int main() {
	cin >> M >> N >> K;
	while (K--) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		v.push({ lx,ly,rx,ry });
	}
	while (!v.empty()) {		//직사각형 개수 만큼 표시
		int lx = v.front().l_x, ly = v.front().l_y, rx = v.front().r_x, ry = v.front().r_y;
		v.pop();
		for (int i = ly; i < ry; i++) {
			for (int j = lx; j < rx; j++) {
				map[j][i] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] == 0) {
				bfs(j, i);
				cnt++;
			}
		}
	}
	sort(area_size.begin(), area_size.end());
	cout << cnt << endl;
	for (int i = 0; i < area_size.size(); i++) {
		cout << area_size[i] << " ";
	}
}