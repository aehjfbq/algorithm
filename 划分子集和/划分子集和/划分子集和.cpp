#include<bits/stdc++.h>
using namespace std;
int n;
int fl = 0;
void check(vector<int>a, int str, int num, int sum) {
    if (num == sum / 2) {
        fl = 1;
        return;
    }
    if (str == a.size()) return;
    check(a, str + 1, num, sum);
    check(a, str + 1, num + a[str], sum);
}
int main() {
    cin >> n;
    vector<int>a;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        sum += tmp;
    }

    if (sum%2 == 1) cout << 0;
    else {    
        int tar = sum / 2;
        //dp��tar+1ΪĿ����
        vector<int>dp(tar + 1, 0);
        //Ĭ��Ŀ����Ϊ0ʱ����ѡȡ0����ʱΪ��
        dp[0] = 1;
        //��ÿ�������б�������ʾ��ǰ״̬�±�ѡȡ
        for (int i = 0; i < n; i++) {
            //��ǰ����������״̬ȡ��������״̬��ѡȡ�������״̬
            for (int j = tar; j >= a[i]; j--) {//���򣬱���ʹ���ظ�Ԫ�أ�Ӧ��ʹ����һ��״̬���¹���dp[j-a[i]],˳��������ܻ����dp[j-a[i]]״̬
                dp[j] = dp[j] | dp[j - a[i]];
            }
        }
        //���Ŀ����Ϊ�棬��������ͨ��ѡȡ�ﵽ��
        if (dp[tar] == 1) cout << 1;
        else cout << 0;
    }
}
