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
        //dp，tar+1为目标数
        vector<int>dp(tar + 1, 0);
        //默认目标数为0时，即选取0个数时为真
        dp[0] = 1;
        //对每个数进行遍历，表示当前状态下被选取
        for (int i = 0; i < n; i++) {
            //当前集合总数的状态取决与自身状态与选取这个数的状态
            for (int j = tar; j >= a[i]; j--) {//逆序，避免使用重复元素，应该使用上一轮状态更新过的dp[j-a[i]],顺序排序可能会更新dp[j-a[i]]状态
                dp[j] = dp[j] | dp[j - a[i]];
            }
        }
        //如果目标数为真，则代表可以通过选取达到，
        if (dp[tar] == 1) cout << 1;
        else cout << 0;
    }
}
