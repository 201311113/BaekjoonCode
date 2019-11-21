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
string s;
string part;
int main() {
	getline(cin, s);
	getline(cin, part);
	int ans = 0;
	if (part.size() > s.size()) {
		cout << 0 << endl;
		return 0;
	}
	int p_size = part.size();
	for (int i = 0; i < s.size() - part.size() + 1; i++) {
		bool is_same = true;
		for (int j = 0; j < part.size(); j++) {
			if (s[i + j] != part[j]) {
				is_same = false;
				break;
			}
		}
		if (is_same) {
			ans++;
			i += p_size - 1;
		}
	}
	cout << ans;
}