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
	//Ȧ������ ¦������������ �縰��� ��������1. 2. ������ ���
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
	for (int i = 0; i < 26; i++) {	//�ʹ� ��
		if (alpha[i]) {
			for (int j = 0; j < alpha[i] / 2; j++) {
				ans += i + 'A';
			}
		}
	}
	if (s_size % 2) {
		ans += hol_idx + 'A';
	}
	for (int i = 25; i >= 0; i--) { //�Ĺ� ��
		if (alpha[i]) {
			for (int j = 0; j < alpha[i] / 2; j++) {
				ans += i + 'A';
			}
		}
	}
	cout << ans << endl;
}