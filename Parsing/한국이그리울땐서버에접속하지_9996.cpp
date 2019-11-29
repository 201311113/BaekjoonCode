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
	int n;
	cin >> n;
	string pattern;
	cin >> pattern;
	string front_pattern, back_pattern;
	bool star = 0;
	for (int i = 0; i < pattern.size(); i++) {
		if (pattern[i] == '*') {
			star = 1;
			continue;
		}
		else if (!star) {
			front_pattern += pattern[i];
		}
		else {
			back_pattern += pattern[i];
		}
	}
	bool visited[100];
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		bool flag = 1;
		for (int j = 0; j < front_pattern.size(); j++) {
			if (s[j] != front_pattern[j]) {
				flag = 0;
				break;
			}
		}
		if (!flag) {
			cout << "NE" << endl;
			continue;
		}

		int len = back_pattern.size() - 1;
		for (int j = s.size() - 1; j >= 0; j--) {
			if (len < 0)
				break;

			if (j < front_pattern.size() || s[j] != back_pattern[len]) {
				flag = 0;
				break;
			}
			len--;
		}
		if (!flag) {
			cout << "NE" << endl;
		}
		else cout << "DA" << endl;
	}

}