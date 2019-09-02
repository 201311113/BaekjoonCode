#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int F, S, G, U, D;
int chk[1000002];
int main() {
	cin >> F >> S >> G >> U >> D;
	queue<int> q;
	q.push(S);
	chk[S] = 1;
	int ans = -1;
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		if (s == G) {
			ans = chk[s] - 1;
			break;
		}
		if (s + U <= F && (chk[s + U] == 0 || chk[s + U] > chk[s] + 1)) {
			int su = s + U;
			q.push(su);
			chk[su] = chk[s] + 1;
		}
		if (s - D >= 1 && (chk[s - D] == 0 || chk[s - D] > chk[s] + 1)) {
			int sd = s - D;
			q.push(sd);
			chk[sd] = chk[s] + 1;
		}
	}
	if (ans == -1) {
		cout << "use the stairs";
	}
	else {
		cout << ans;
	}
}