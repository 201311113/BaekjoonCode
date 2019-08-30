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
int N;
string ans;
int aidx = 0, bidx = 0, cidx = 0;
int ascore = 0, bscore = 0, cscore = 0;
string apatt = "ABC", bpatt = "BABC", cpatt = "CCAABB";
int main() {
	cin >> N;
	cin >> ans;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == apatt[aidx]) ascore++;
		if (ans[i] == bpatt[bidx]) bscore++;
		if (ans[i] == cpatt[cidx]) cscore++;
		++aidx;
		++bidx;
		++cidx;
		if (aidx >= 3) aidx = 0;
		if (bidx >= 4) bidx = 0;
		if (cidx >= 6) cidx = 0;
	}
	for (int i = 101; i >= 0; i--) {
		if (ascore == i || bscore == i || cscore == i) {
			cout << i << endl;
			if (ascore == i) cout << "Adrian" << endl;
			if (bscore == i)cout << "Bruno" << endl;
			if (cscore == i)cout << "Goran" << endl;
			break;
		}
	}

}