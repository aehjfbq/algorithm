#include<iostream>
#include<vector>
using namespace std;
bool is_target(vector<int>num, int target);
bool backtark(vector<double>num, double target);
int main() {
	vector<int>num = {1,2,3,8};
	int target=24;
	if (is_target(num, target)) cout << 1;
	else cout << 0;
}
bool is_target(vector<int>num,int target) {
	//�����������㣬��̬ת��ǿ��ת��Ϊ������
	//�������ж����������ʱ��ֱ�ӱȽϻ������Ӧ�ñȽ�������֮���Ƿ�С��һ�����ȣ�1e-6��;
	vector<double>n;
	for (auto it : num) n.push_back(static_cast<double>(it));
	return backtark(n,static_cast<double>(target));
}

bool backtark(vector<double>num,double target) {
	int n = num.size();
	if (n == 0) return false;
	//���ʽ������еĽ��
	if (n == 1) return fabs(num[0] - target) < 1e-6;
	//����ѭ������ʾ���������е����п�����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			double n1 = num[i];
			double n2 = num[j];
			vector<double>nextnum;
			//������δʹ�õ����ּӵ�����У��𽥼����������ַ�ʹ����
			for (int x = 0; x < n; x++) {
				if (x == i || x == j) continue;
				nextnum.push_back(num[x]);
			}
			//ʹ�û����㷨���������п��ܵ����
			//+
			nextnum.push_back(n1 + n2);
			if (backtark(nextnum, target)) return true;
			nextnum.pop_back();

			//-
			nextnum.push_back(n1 - n2);
			if (backtark(nextnum, target)) return true;
			nextnum.pop_back();

			//*
			nextnum.push_back(n1 * n2);
			if (backtark(nextnum, target)) return true;
			nextnum.pop_back();

			// /
			if(n2>1e-6){
				nextnum.push_back(n1 /n2);
				if (backtark(nextnum, target)) return true;
				nextnum.pop_back();
			}
		}
	}
	return false;
}