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
	int n = 5;
	string s;
	bool flag = 0;
	vector<int> ans;
	while (n--) {
		cin >> s;
		for (int i = 0; i < s.size() - 2; i++) {
			string tmp = s.substr(i, 3);
			if (tmp == "FBI") {
				flag = 1;
				ans.push_back(5 - n);
				break;
			}
		}
	}
	if (!flag) cout << "HE GOT AWAY!";
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
	}
}