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
bool com_marathon[100002];
int main() {
	int n;
	cin >> n;
	vector<string> candidates;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		candidates.push_back(s);
	}
	sort(candidates.begin(), candidates.end());
	for (int i = 0; i < n - 1; i++) {
		string s;
		cin >> s;
		int f = 0, l = n - 1;
		while (f <= l) {
			int mid = (f + l) / 2;
			if (candidates[mid] == s) {
				if (com_marathon[mid]) {
					bool flag = 0;
					for (int i = mid + 1; i < n; i++) {
						if (s != candidates[i]) break;
						if (!com_marathon[i] && candidates[i] == s) {
							com_marathon[i] = 1;
							flag = 1;
							break;
						}
					}
					if (flag) break;
					for (int i = mid - 1; i >= 0; i--) {
						if (s != candidates[i]) break;
						if (!com_marathon[i] && candidates[i] == s) {
							com_marathon[i] = 1;
							break;
						}
					}
				}
				else {
					com_marathon[mid] = 1;
				}
				break;
			}
			else if (candidates[mid] < s) {
				f = mid + 1;
			}
			else {
				l = mid - 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!com_marathon[i]) {
			cout << candidates[i];
			break;
		}
	}
}