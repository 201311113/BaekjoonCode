#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int check[100002] = { 0, };
int dis[100002] = { 0, };
int main() {			//1�������� �ذ��ϴ� bfs�����̴�
	int N, K;
	cin >> N >> K;
	queue<int> q;
	q.push(N);
	check[N] = 1;
	while (!q.empty()) {		//��帶�� 3���� branch�� ��� �����ϰ� chk�� �湮������ �����ϸ� ���� �ذᰡ���ϴ�
		int now = q.front();
		q.pop();
		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				q.push(now - 1);
				check[now - 1] = true;
				dis[now - 1] = dis[now] + 1;
			}
		}
		if (now + 1 < 100001) {
			if (check[now + 1] == false) {
				q.push(now + 1);
				check[now + 1] = true;
				dis[now + 1] = dis[now] + 1;
			}
		}
		if (now * 2 < 100001) {
			if (check[now * 2] == false) {
				q.push(now * 2);
				check[now * 2] = true;
				dis[now * 2] = dis[now] + 1;
			}
		}
	}
	printf("%d", dis[K]);
}