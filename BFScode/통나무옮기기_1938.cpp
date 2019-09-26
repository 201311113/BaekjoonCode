#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int N;
char map[51][51];
int chk[2][51][51];
pair<int, int> init_B[3], init_E[3];	//ó���� B,E���� ��� ��
struct node {
	int x;
	int y;
	bool status;		//�����ִ��� ���ִ���		���ִ°� true
	int cnt;			//BFS ��� �ܰ� ī����
};
node tmpB;	//�볪�� ����	
node tmpE;	//������ ����
int main() {
	cin >> N;
	int bidx = 0, eidx = 0;
	for (int i = 0; i < N; i++) {	//�Է� �����鼭 B,E���� ����
		for (int j = 0; j < N; j++) {
			cin >> map[j][i];
			if (map[j][i] == 'B') {
				init_B[bidx] = { j,i };
				map[j][i] = '0';
				bidx++;
			}
			else if (map[j][i] == 'E') {
				init_E[eidx] = { j,i };
				map[j][i] = '0';
				eidx++;
			}
		}
	}
	//���� B,E������ ���⼭ �����ؼ� �������� node�ڷ����� ����
	if (init_B[1].first == init_B[0].first) tmpB = { init_B[1].first,init_B[1].second,1,0 };
	else tmpB = { init_B[1].first,init_B[1].second,0 ,0 };
	if (init_E[1].first == init_E[0].first) tmpE = { init_E[1].first,init_E[1].second,1,0 };
	else tmpE = { init_E[1].first,init_E[1].second,0 ,0 };
	queue<node> q;
	q.push(tmpB);
	int ans = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		bool status = q.front().status;
		int tcnt = q.front().cnt;
		q.pop();

		if (x == tmpE.x && y == tmpE.y && status == tmpE.status) {	//������ ���µ� ���ƾ�
			ans = tcnt;
			break;
		}
		if (status) {//�������� status=1
			if (y - 2 >= 0 && !chk[1][x][y - 1] && map[x][y - 2] != '1') {//U
				q.push({ x,y - 1,1,tcnt + 1 });
				chk[1][x][y - 1] = tcnt + 1;
			}
			if (y + 2 < N && !chk[1][x][y + 1] && map[x][y + 2] != '1') {//D
				q.push({ x,y + 1,1,tcnt + 1 });
				chk[1][x][y + 1] = tcnt + 1;
			}
			if (x + 1 < N && !chk[1][x + 1][y] && map[x + 1][y] != '1' && map[x + 1][y - 1] != '1' && map[x + 1][y + 1] != '1') {//R
				q.push({ x + 1,y,1,tcnt + 1 });
				chk[1][x + 1][y] = tcnt + 1;
			}
			if (x - 1 >= 0 && !chk[1][x - 1][y] && map[x - 1][y] != '1' && map[x - 1][y - 1] != '1' && map[x - 1][y + 1] != '1') {//L
				q.push({ x - 1,y,1,tcnt + 1 });
				chk[1][x - 1][y] = tcnt + 1;
			}
			if (x - 1 >= 0 && x + 1 < N && !chk[0][x][y] && map[x - 1][y] != '1' && map[x - 1][y - 1] != '1' && map[x - 1][y + 1] != '1' && map[x + 1][y] != '1' && map[x + 1][y - 1] != '1' && map[x + 1][y + 1] != '1') {
				q.push({ x,y,0,tcnt + 1 });
				chk[0][x][y] = tcnt + 1;
			}
		}
		else {
			if (y - 1 >= 0 && !chk[0][x][y - 1] && map[x][y - 1] != '1' && map[x - 1][y - 1] != '1' && map[x + 1][y - 1] != '1') {//U
				q.push({ x,y - 1,0 ,tcnt + 1 });
				chk[0][x][y - 1] = tcnt + 1;
			}
			if (y + 1 < N && !chk[0][x][y + 1] && map[x][y + 1] != '1' && map[x - 1][y + 1] != '1' && map[x + 1][y + 1] != '1') {//D
				q.push({ x,y + 1,0 ,tcnt + 1 });
				chk[0][x][y + 1] = tcnt + 1;
			}
			if (x + 2 < N && !chk[0][x + 1][y] && map[x + 2][y] != '1') {//R
				q.push({ x + 1,y,0,tcnt + 1 });
				chk[0][x + 1][y] = tcnt + 1;
			}
			if (x - 2 >= 0 && !chk[0][x - 1][y] && map[x - 2][y] != '1') {//L
				q.push({ x - 1,y,0 ,tcnt + 1 });
				chk[0][x - 1][y] = tcnt + 1;
			}
			if (y - 1 >= 0 && y + 1 < N && !chk[1][x][y] && map[x][y - 1] != '1' && map[x - 1][y - 1] != '1' && map[x + 1][y - 1] != '1' && map[x][y + 1] != '1' && map[x - 1][y + 1] != '1' && map[x + 1][y + 1] != '1') {
				q.push({ x,y,1 ,tcnt + 1 });
				chk[1][x][y] = tcnt + 1;
			}
		}
	}
	cout << ans;
	return 0;
}