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
int alpha[26];
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		++alpha[s[i] - 'A'];
	}
	//홀수인지 짝수인지에따라서 펠린드롬 가능한지1. 2. 사전순 출력
	int s_size = s.size();
	int hol_idx, cnt = 0;

	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 == 1) {
			hol_idx = i;
			cnt++;
		}
	}
	if ((s_size % 2 == 0 && cnt) || s_size % 2 == 1 && cnt != 1) {
		cout << "I'm Sorry Hansoo" << endl;
		return 0;
	}
	string ans;
	for (int i = 0; i < 26; i++) {	//초반 앞
		if (alpha[i]) {
			for (int j = 0; j < alpha[i] / 2; j++) {
				ans += i + 'A';
			}
		}
	}
	if (s_size % 2) {
		ans += hol_idx + 'A';
	}
	for (int i = 25; i >= 0; i--) { //후반 뒤
		if (alpha[i]) {
			for (int j = 0; j < alpha[i] / 2; j++) {
				ans += i + 'A';
			}
		}
	}
	cout << ans << endl;
}