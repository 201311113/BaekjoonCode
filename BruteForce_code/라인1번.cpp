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
int cal(string s) {//
	int answer = 0;
	stack<int> stk1, stk2, stk3, stk4;//��ȣ ( = 1 { = 2 [ = 3 < = 4 ���õ��� ����� ������ [(])�� �ȴٰ��߱⶧��
	for (int i = 0; i < s.size(); i++) {//���ڿ��ϳ��ϳ��˻�
		if ((stk1.empty()&&s[i]==')')|| (stk2.empty() && s[i] == '}')|| (stk3.empty() && s[i] == ']')|| (stk4.empty() && s[i] == '>')) { //���°�ȣ���� �� �ݴ°�ȣ ���°��
			answer = -1;
			break;
		}
		if (s[i] == '(') {//���� ���� ��ȣ ���ö����� �־��� �ݴ� ��ȣ�� ����
			stk1.push(1);
			answer++;	//�� ���°�ȣ ���������� answer�������� �ϳ��� ������
		}
		else if (s[i] == ')') stk1.pop();
		else if (s[i] == '{') {
			stk2.push(1);
			answer++;
		}
		else if (s[i] == '}') stk2.pop();
		else if (s[i] == '[') {
			stk3.push(1);
			answer++;
		}
		else if (s[i] == ']') stk3.pop();
		else if (s[i] == '<') {
			stk4.push(1);
			answer++;
		}
		else if (s[i] == '>') stk4.pop();
	}
	if (!stk1.empty() || !stk2.empty() || !stk3.empty() || !stk4.empty()) {//������� ���� ���� �ϳ��� ������ ��ȣ �ҿ��� �̹Ƿ� answer=-1
		answer = -1;
	}
	return answer;
}
int main() {
	string s[4] = {"Hello world!","line [plus]","if(Count of eggs is 4.){Buy milk}",">_<" };
	for (int i = 0; i < 4; i++) {//�Է¹��������� ���⿡�� �����Է�ó�������� �Է¹����鼭 �Ҷ�� getline���� �ؾ���
		//string s;
		//cin >>s; ���� getline
		cout << cal(s[i])<<endl;//endl�� ����
	}
	

}