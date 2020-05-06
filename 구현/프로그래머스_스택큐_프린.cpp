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
bool is_sup[10];
bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
	return a.second < b.second;
}
int cal(vector<int> food_times,int k) {
	int ans = 0;
	vector<pair<int, int>> val;//°ª,ÀÎµ¦½º
	for (int i = 0; i < food_times.size(); i++) {
		val.push_back({ food_times[i],i });
	}
	sort(val.begin(), val.end());
	int t_idx = 0;
	while (t_idx!=val.size()) {
		bool flag = 1;
		if (val[t_idx].first == 0) {
			t_idx++;
			continue;
		}
		if (val[t_idx].first * (val.size() - t_idx) < k) {
			k -= val[t_idx].first * (val.size() - t_idx);
		}
		else {
			while (k != 0) {
				if (k - val.size() + t_idx > 0) {
					k -= val.size() - t_idx;
				}
				else {
					flag = 0;
					break;
				}
			}
		}
		if (!flag) break;
		t_idx++;
		
	}
	sort(val.begin(), val.end(), cmp);
	int i;
	for (i = t_idx; i < t_idx + k; i++) {
		
	}
	ans = i + 1;
	return ans;
}
int main() {
	vector<int> food_time = { 3,1,2 };
	int ans=cal(food_time, 5);
	cout << ans;
}