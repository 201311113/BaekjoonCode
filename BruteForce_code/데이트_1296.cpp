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
typedef struct {
	int l;
	int o;
	int v;
	int e;
}love;
int main() {
	string sik_k;
	int n;
	int sik_l = 0, sik_o = 0, sik_v = 0, sik_e = 0;
	cin >> sik_k;
	for (int i = 0; i < sik_k.size(); i++) {
		if (sik_k[i] == 'L') {
			sik_l++;
		}
		else if (sik_k[i] == 'O') {
			sik_o++;
		}
		else if (sik_k[i] == 'V') {
			sik_v++;
		}
		else if (sik_k[i] == 'E') {
			sik_e++;
		}
	}
	cin >> n;
	vector<string> ans;
	int val = -1;
	for (int i = 0; i < n; i++) {
		string s;
		int l = 0, o = 0, v = 0, e = 0;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'L') {
				l++;
			}
			else if (s[i] == 'O') {
				o++;
			}
			else if (s[i] == 'V') {
				v++;
			}
			else if (s[i] == 'E') {
				e++;
			}
		}
		l += sik_l;
		o += sik_o;
		v += sik_v;
		e += sik_e;
		int tmp_val = ((l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e)) % 100;
		if (val == tmp_val) {
			ans.push_back(s);
		}
		else if (val < tmp_val) {
			ans.clear();
			ans.push_back(s);
			val = tmp_val;
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[0];
}