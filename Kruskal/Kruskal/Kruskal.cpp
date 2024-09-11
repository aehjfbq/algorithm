#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, value;
    edge(int a, int b, int c) :u(a), v(b), value(c) {};
};
vector<edge>a;
vector<int>node(15, 0);
vector<int>rank1(15, 0);
int kruskal(int n);
int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        a.push_back(edge(t1, t2, t3));
    }
    cout << kruskal(n);

}
//查找节点
int find(int x) {
    if (node[x] != x) {
        node[x] = find(node[x]);
    }
    return node[x];
}
//合并节点
void unionset(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
        if (rank1[rootx] > rank1[rooty]) {
            node[rooty] = rootx;
        }
        else if (rank1[rootx] < rank1[rooty]) {
            node[rootx] = rooty;
        }
        else {
            node[rooty] = rootx;
            rank1[rootx]++;
        }
    }
}
int kruskal(int n) {
    sort(a.begin(), a.end(), [](edge a, edge b) {
        return a.value < b.value;
        });
    for (int i = 1; i <= n; i++) {
        node[i] = i;
        rank1[i] = 0;
    }
    int mstweight = 0, edgcount = 0;
    for (edge it : a) {
        int u = it.u;
        int v = it.v;
        int value = it.value;
        if (find(u) != find(v)) {
            unionset(u, v);
            mstweight += value;
            edgcount++;
            if (edgcount == n - 1) break;
        }
    }
    return mstweight;
}
// 64 位输出请用 printf("%lld")