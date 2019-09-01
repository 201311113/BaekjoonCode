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
int player[11][11];	//�ʱ�ȭ x
bool played[11];	//�ʱ�ȭ o �����Ǵ���
int t;
vector<pair<int, int>> ability[11];//��ġ-1 ����idx-2 /�ʱ�ȭ o
int ans = -1;	//�ʱ�ȭ o
void dfs(int p_idx, int abil_sum) {
	if (p_idx == 11) {
		ans = max(ans, abil_sum);
		return;
	}
	for (int i = 0; i < 11; i++) {
		if (player[p_idx][i] != 0 && !played[i]) {
			played[i] = 1;
			dfs(p_idx + 1, abil_sum + player[p_idx][i]);
			played[i] = 0;
		}
	}

}
int main() {
	cin >> t;
	while (t--) {
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> player[j][i];
			}
		}

		for (int i = 0; i < 11; i++) {
			if (player[0][i] != 0) {
				played[i] = 1;
				dfs(1, player[0][i]);
				played[i] = 0;
			}
		}
		cout << ans << endl;
		for (int i = 0; i < 11; i++) {
			played[i] = 0;
		}
		ans = -1;
	}
}