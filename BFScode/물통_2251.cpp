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
int A, B, C;
bool chk[200][200][200];
vector<int> ans;
struct node {
	int a;
	int b;
	int c;
};
int main() {
	cin >> A >> B >> C;
	queue<node> q;
	q.push({ 0,0,C });
	chk[0][0][C] = 1;
	while (!q.empty()) {
		int ta = q.front().a, tb = q.front().b, tc = q.front().c;
		q.pop();
		if (ta == 0) {
			ans.push_back(tc);
		}
		if (ta != 0) {	//from a
			if (tb < B) {
				int tta = ta, ttb = tb, ttc = tc;
				if (tta + ttb > B) {	//to b ³ÑÄ¥¶§
					tta = tta + ttb - B;
					ttb = B;
				}
				else {					//to b ¾È³ÑÄ¥¶§
					ttb = tta + ttb;
					tta = 0;
				}
				if (!chk[tta][ttb][ttc]) {
					q.push({ tta,ttb,ttc });
					chk[tta][ttb][ttc] = 1;
				}
			}
			if (tc < C) {
				int tta = ta, ttb = tb, ttc = tc;
				if (tta + ttc > C) {
					tta = tta + ttc - C;
					ttc = C;
				}
				else {
					ttc = tta + ttc;
					tta = 0;
				}
				if (!chk[tta][ttb][ttc]) {
					q.push({ tta,ttb,ttc });
					chk[tta][ttb][ttc] = 1;
				}
			}
		}
		if (tb != 0) {	//from b
			if (ta < A) {
				int tta = ta, ttb = tb, ttc = tc;
				if (tta + ttb > A) {	//to b ³ÑÄ¥¶§
					ttb = tta + ttb - A;
					tta = A;
				}
				else {					//to b ¾È³ÑÄ¥¶§
					tta = tta + ttb;
					ttb = 0;
				}
				if (!chk[tta][ttb][ttc]) {
					q.push({ tta,ttb,ttc });
					chk[tta][ttb][ttc] = 1;
				}
			}
			if (tc < C) {
				int tta = ta, ttb = tb, ttc = tc;
				if (ttc + ttb > C) {
					ttb = ttc + ttb - C;
					ttc = C;
				}
				else {
					ttc = ttc + ttb;
					ttb = 0;
				}
				if (!chk[tta][ttb][ttc]) {
					q.push({ tta,ttb,ttc });
					chk[tta][ttb][ttc] = 1;
				}
			}
		}
		if (tc != 0) {	//from c
			if (ta < A) {
				int tta = ta, ttb = tb, ttc = tc;
				if (tta + ttc > A) {	//to b ³ÑÄ¥¶§
					ttc = tta + ttc - A;
					tta = A;
				}
				else {					//to b ¾È³ÑÄ¥¶§
					tta = tta + ttc;
					ttc = 0;
				}
				if (!chk[tta][ttb][ttc]) {
					q.push({ tta,ttb,ttc });
					chk[tta][ttb][ttc] = 1;
				}
			}
			if (tb < B) {
				int tta = ta, ttb = tb, ttc = tc;
				if (ttc + ttb > B) {
					ttc = ttc + ttb - B;
					ttb = B;
				}
				else {
					ttb = ttc + ttb;
					ttc = 0;
				}
				if (!chk[tta][ttb][ttc]) {
					q.push({ tta,ttb,ttc });
					chk[tta][ttb][ttc] = 1;
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[0] << " ";
	for (int i = 1; i < ans.size(); i++) {
		if (ans[i] == ans[i - 1]) continue;
		cout << ans[i] << " ";
	}

}