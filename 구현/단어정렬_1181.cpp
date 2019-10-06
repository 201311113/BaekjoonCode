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
bool cmp(const string& a, const string& b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}
int main() {
	vector<string> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		if (i == 0) cout << v[i] << endl;
		else if (v[i] == v[i - 1]) {
			continue;
		}
		else cout << v[i] << endl;
	}


}