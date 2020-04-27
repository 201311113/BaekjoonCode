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
#include<map>
#include<sstream>
using namespace std;
bool cmp(pair<double,int> const &a,pair<double,int> const &b) {
	if (a.first == b.first) return a < b;
	return a.first > b.first;
}
vector<int> cal(int n, vector<int> stages) {
	vector<int> ans;
	sort(stages.begin(), stages.end());
	int idx = 0;
	int prev = 0;
	vector<pair<double,int>> fail_ratio;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = idx; j < stages.size(); j++) {
			if (stages[j] == i) {
				cnt++;
			}
			else if (stages[j] > i) {
				prev = idx;
				idx = j;
				break;
			}
		}
		double tmp = cnt*1000 / (stages.size() - prev);
		if (cnt == 0) tmp = 0;
		fail_ratio.push_back({ tmp,i });
	}
	sort(fail_ratio.begin(), fail_ratio.end(), cmp);
	
	for (int i = 0; i < fail_ratio.size(); i++) {
		ans.push_back(fail_ratio[i].second);
	}
	return ans;
}
int main() {
	int n;
	vector<int> stage;
	cin >> n;
	while (1) {
		int num;
		cin >> num;
		if (num == -1) break;
		stage.push_back(num);
	}
	vector<int> ans = cal(n, stage);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
}