#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 150
#define eps 1e-6
using namespace std;
int n, x;
int m;
double pr[N];
void multi(double mat1[][N], double mat2[][N]) {
    double res[N][N];
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            res[i][j] = 0.0;
            for (int k = 0; k <= m; ++k) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            mat2[i][j] = res[i][j];
        }
    }
}
double solve() {
    double res[N][N];
    for (int i = 0; i <= m; ++i) {
        res[i][i] = 1.0;
    }
    double trans[N][N];
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            trans[i][j] = pr[i ^ j];
        }
    }
    int b = n - 1;
    while(b) {
        if (b & 1) multi(trans, res);
        multi(trans, trans);
        b /= 2;
    }
    double ans = 0.0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            ans += res[i][j] * pr[j];
        }
    }
    return ans;
}
int main() {
    cin>>n>>x;
    int bits = 0;
    int tmp = x;
    while(tmp) {
        bits++;
        tmp /= 2;
    }
    m = (1<<bits) - 1;
    for (int i = 0; i <= m; ++i) {
        if (i <= x) cin>>pr[i];
        else pr[i] = 0.0;
    }
    printf("%.7lf\n", solve());
    return 0;
}
