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
int main() {
	int n, s_size;
	string s;
	cin >> n >> s_size >> s;
	int ans = 0;
	vector<int> pattern;
	for (int i = 0; i < s_size; i++) {
		if (s[i] == 'I') {
			int next_idx = i;
			int cnt = 0;
			for (int j = i + 1; j < s_size; j++) {
				if (s[j] == s[j - 1]) {
					break;
				}
				if (s[j] == 'I') {
					next_idx = j;
					cnt++;
				}
			}

			pattern.push_back(cnt);
			i = next_idx;
		}
	}
	for (int i = 0; i < pattern.size(); i++) {
		if (pattern[i] < n)	continue;
		ans += pattern[i] - n + 1;
	}
	cout << ans;
}