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
bool chk[100020];
map<string, int> m;
bool cmp(const vector<string>& a, const vector<string>& b) {//������ sort�Լ��� ���� ���ĺ� ������ �����ϱ� ���� bool�Լ�
	return a < b;
}
int calint(string s) {//string -> int ��ȯ ���� �̰žȾ��� atoi()�ᵵ ��
	int sum = 0;
	int tmp = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		int num = s[i] - '0';
		sum += num * tmp;
		tmp *= 10;
	}
	return sum;
}
string calstr(int num) {//int -> string ��ȯ �̰ŵ� �� �Լ� ���� ��ü��
	string s="";
	while (num) {
		char c;
		c = num % 10 + '0';
		s += c;
		num /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}
vector<vector<string>> cal(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
	for (int i = 0; i < snapshots.size(); i++) {//map�̶�� �ڷᱸ���� ���� �������� account�̸����� ã�� �� �ִ�.
		int num = calint(snapshots[i][1]);
		m.insert({ snapshots[i][0] ,num});
	}
	for (int i = 0; i < transactions.size(); i++) {//Ʈ������ �м�
		int id = calint(transactions[i][0]);//id int ������ ��ȯ
		if (chk[id]) continue;	// id ��ġ�� �Ѿ�Բ� chk�� ǥ��
		int num = calint(transactions[i][3]);	//����� ���� int������ ��ȯ
		string tmpaccount = transactions[i][2]; //��ī��Ʈ �̸� ����
		if (transactions[i][1] == "SAVE") {//���� �ÿ� ��ī��Ʈ�̸����� �ʿ��� ã�� ������ insert����
			if (m.find(tmpaccount) == m.end()) {
				m.insert({ tmpaccount, num });
			}
			else m[tmpaccount] += num; //
		}
		else {//��ݽÿ� ��ī��Ʈ�̸��� ���� �� �����Ƿ� ���� ����
			m[tmpaccount] -= num;
		}
	}
	
	map<string, int> ::iterator iter;//������ �ݺ����Ҷ��iterator���
	vector<vector<string>> ans;
	for (iter = m.begin(); iter != m.end(); iter++) {//����ü ������ ���ο� return�� vector�� �־���
		vector<string> tmp;
		tmp.push_back(iter->first);
		tmp.push_back(calstr(iter->second));
		ans.push_back(tmp);
	}
	sort(ans.begin(), ans.end(), cmp);//��ī��Ʈ �̸������� ����
	return ans;
}
int main() {//����� ���� ����ƴ� �����Ͻñ�
	vector<vector<string>> snapshots;
	vector<vector<string>> transactions;
	while (1) {//snapshot �Է�
		string s1,s2;
		vector<string> snapshot;
		cin >> s1>>s2;
		if (s1 == "end") {// end ġ�� �ϳ� ���ľߴ� s2���� �־
			break;
		}
		snapshot.push_back(s1);
		snapshot.push_back(s2);
		snapshots.push_back(snapshot);
	}
	
	while (1) {//transaction�Է�
		string s1,s2,s3,s4;
		vector<string> transaction;
		cin >> s1>>s2>>s3>>s4;
		if (s1 == "end") {//end ġ�� �̰� 3�� ���ľ߰� s4������ ex) end 0 0 0 
			break;
		}
		transaction.push_back(s1);
		transaction.push_back(s2);
		transaction.push_back(s3);
		transaction.push_back(s4);
		transactions.push_back(transaction);
	}
	
	vector<vector<string>> ans=cal(snapshots,transactions);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i][0] << " " << ans[i][1]<<endl;
	}
}
//��ȿ��� �����ϸ��
//account1 100	
//account2 150
//end 0
//1 SAVE account2 100
//2 WITHDRAW account1 50
//1 SAVE account2 100
//4 SAVE account3 500
//3 WITHDRAW account2 30
//end 0 0 0