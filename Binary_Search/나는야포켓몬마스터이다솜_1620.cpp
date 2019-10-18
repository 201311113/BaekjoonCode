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
int n, m;//°¢ 100000
int main() {
	cin >> n >> m;
	vector<string> arr_n;
	vector<pair<string, int>> arr_s;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr_n.push_back(s);
		arr_s.push_back({ s,i + 1 });
	}
	sort(arr_s.begin(), arr_s.end());
	for (int i = 0; i < m; i++) {
		string q;
		cin >> q;
		if (q[0] >= 'A' && q[0] <= 'Z') {
			int f = 0, l = n - 1;
			while (f <= l) {
				int mid = (f + l) / 2;
				if (q == arr_s[mid].first) {
					cout << arr_s[mid].second << endl;
					break;
				}
				if (q > arr_s[mid].first) {
					f = mid + 1;
				}
				else {
					l = mid - 1;
				}
			}
		}
		else {
			int num = atoi(q.c_str());
			cout << arr_n[num - 1] << endl;
		}
	}

}