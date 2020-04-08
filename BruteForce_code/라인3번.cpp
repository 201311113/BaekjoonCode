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
#include<map>
#include<sstream>
using namespace std;
int cal(string s,int n) {//string�˻��ؼ� 1���ӵȸ�ŭ ����� 0���ӵȸ�ŭ ������ vector�� �����ؼ� Ǯ�����
	int continuous_1 = 0 , continuous_2 = 0;
	vector<int> arr;
	for (int i = 0; i < s.size(); i++) {	//1���ӵȸ�ŭ vector�� �ְ� 0�� ���ö����� -1�� ����
		if (s[i] == '1') {
			continuous_1++;
		}
		else if (s[i] == '0') {
			if (continuous_1) {
				arr.push_back(continuous_1);
				continuous_1 = 0;
			}
			arr.push_back(-1);
		}
	}
	if (continuous_1) {
		arr.push_back(continuous_1);
	}
	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {//vector�� ó������ �˻��ؼ� ���ӵǴ� �� �˻�
		int tmpn = n;
		int sum = 0;
		if (arr[i] == -1) {//0������ n--�� sum++�ϴ� ������ �����������ֱ�
			tmpn--;
			sum++;
		}
		else {	//1������ �׳� �����ֱ�
			sum += arr[i];
		}
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j] < 0 && tmpn == 0) break;//n�� �پ��� 0�� ���� ���ö����� ���
			if (arr[j] == -1) {
				tmpn--;
				sum++;
			}
			else {
				sum += arr[j];
			}
		}
		if (ans < sum) ans = sum;//���� ū�� �Է�
	}
	return ans;
}
int main() {
	string s;
	int n;
	cin >> s>>n;
	cout << cal(s,n);
}