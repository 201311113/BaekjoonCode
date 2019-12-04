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
int t;
int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> candidates;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			candidates.push_back({ a,b });
		}
		sort(candidates.begin(), candidates.end());
		int ans = 1;
		int min_second = candidates[0].second;
		for (int i = 1; i < n; i++) {
			if (candidates[i].second < min_second) {
				ans++;
				min_second = min(min_second, candidates[i].second);
			}
		}
		cout << ans << endl;
	}
}