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
using namespace std;
int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int min_ans = 123456789;
	for (int i = 0; i <= s2.size() - s1.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < s1.size(); j++) {
			if (s1[j] != s2[i + j]) ++cnt;
		}
		min_ans = min(min_ans, cnt);
	}
	cout << min_ans;
}