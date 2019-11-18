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
int n, m;
int main() {
	cin >> n >> m;
	vector<string> no_hear;
	vector<string> no_see;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		no_hear.push_back(s);
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		no_see.push_back(s);
	}
	sort(no_hear.begin(), no_hear.end());
	sort(no_see.begin(), no_see.end());
	vector<string> ans;
	for (int i = 0; i < n; i++) {
		string tmp = no_hear[i];
		int f = 0, l = m - 1;
		while (f <= l) {
			int mid = (f + l) / 2;
			if (no_see[mid] == tmp) {
				ans.push_back(tmp);
				break;
			}
			else if (no_see[mid] > tmp) {
				l = mid - 1;
			}
			else {
				f = mid + 1;
			}
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}