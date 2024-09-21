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
	//允许浮点数运算，静态转换强制转换为浮点数
	//浮点数判断两个数相等时，直接比较会存在误差，应该比较两个数之差是否小于一个精度（1e-6）;
	vector<double>n;
	for (auto it : num) n.push_back(static_cast<double>(it));
	return backtark(n,static_cast<double>(target));
}

bool backtark(vector<double>num,double target) {
	int n = num.size();
	if (n == 0) return false;
	//表达式最后运行的结果
	if (n == 1) return fabs(num[0] - target) < 1e-6;
	//两层循环，表示两个数运行的所有可能性
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			double n1 = num[i];
			double n2 = num[j];
			vector<double>nextnum;
			//将其他未使用的数字加到组合中，逐渐减少数组中字符使用量
			for (int x = 0; x < n; x++) {
				if (x == i || x == j) continue;
				nextnum.push_back(num[x]);
			}
			//使用回溯算法，遍历所有可能的组合
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