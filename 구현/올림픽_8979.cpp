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
#include<sstream>
using namespace std;
int n, p, k;
typedef struct {
	int nation;
	int g_cnt;
	int s_cnt;
	int b_cnt;
}node;
bool cmp(const node& a, const node& b) {
	if (a.g_cnt == b.g_cnt) {
		if (a.s_cnt == b.s_cnt) {
			if (a.b_cnt == b.b_cnt) {
				if (a.nation == k) {
					return true;
				}
				if (b.nation == k) {
					return false;
				}
			}
			return a.b_cnt > b.b_cnt;
		}
		return a.s_cnt > b.s_cnt;
	}
	return a.g_cnt > b.g_cnt;
}

int main() {
	cin >> n >> k;
	vector<node> olimpic;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		olimpic.push_back({ a,b,c,d });
	}
	sort(olimpic.begin(), olimpic.end(), cmp);

	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (olimpic[i].nation == k) {
			ans = i + 1;
		}
	}
	cout << ans;
}