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
int cal(string answer_sheet, vector<string> sheets) {
	int ans = 0;
	for (int i = 0; i < sheets.size(); i++) {	//sheets���� �� ex) 1 2 3 4 - > 1 2 / 1 3 / 1 4 / 2 3 / 2 4/ 3 4 ���ؼ� �� 6�� ��
		for (int j = i + 1; j < sheets.size(); j++) {
			int tmp = 0;
			int sum = 0;
			int max_long = 0;
			for (int k = 0; k < answer_sheet.size(); k++) {// �����ϳ��ϳ� ��
				if (sheets[i][k] != answer_sheet[k] && sheets[i][k] == sheets[j][k]) {//�Ѵ� ���� Ʋ������ 
					tmp++;
				}
				else {	//�ƴ� ���� ������ �������� �ǽɹ��� ������ ���� ����ϴ� tmp�ʱ�ȭ �� ���ǽɹ��� �����ֱ� �� ���� �ǽɹ��װ����� tmp���� ������ tmp�� �ʱ�ȭ ���ֱ�
					sum += tmp;
					if (max_long < tmp) max_long = tmp;
					tmp = 0;
				}
			}
			if (tmp) {//�������� ������ �ǽɹ����̸� ���� �ݺ��������� ����̾ȵǼ� tmp�� �������� �� �׸�ŭ ����������
				if (max_long < tmp)max_long = tmp;//
				sum += tmp;
			}
			
			int tmp_ans = sum + (max_long * max_long); //��üũ������ �ǽɰ�� ���
			if (ans < tmp_ans) {	//�ǽɰ�� �ʱ�ȭ
				ans = tmp_ans;
			}
		}
	}
	
	return ans;
}
int main() {	
	vector<string> arr;
	string answer_sheet;
	cin >> answer_sheet;	//���� answer_sheet �Է�
	while (1) {	//������ sheets�Է�
		string s;
		cin >> s;
		if (s == "end") break;	//sheets�� ���� testcase���� �޶� end�� �Է��ؾ� �������ǰԲ���
		arr.push_back(s);
	}
	cout << cal(answer_sheet, arr);//�Է³����� cal�Լ����� ����� �����
}