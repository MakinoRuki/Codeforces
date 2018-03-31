#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define eps 1e-9
using namespace std;
int n;
int L[6], R[6];
int main() {
    cin>>n;
    int maxp = 0;
    for (int i = 0; i < n; ++i) {
        cin>>L[i]>>R[i];
        maxp = max(maxp, R[i]);
    }
    double ans = 0.0;
    for (int sp = 1; sp <= maxp; ++sp) {
        double pr = 0.0;
        for (int i = 0; i < n; ++i) {
            double tpr1 = max(0.0, (double)(min(R[i] - sp, R[i] - L[i] + 1))) / (double)(R[i] - L[i] + 1);
            vector<int> tmp;
            tmp.clear();
            for (int j = 0; j < n; ++j) {
                if (i != j) tmp.push_back(j);
            }
            for (int j = 1; j < (1<<tmp.size()); ++j) {
                double tpr2 = 1.0;
                for (int k = 0; k < tmp.size(); ++k) {
                    if ((1<<k) & j) {
                        if (sp >= L[tmp[k]] && sp <= R[tmp[k]]) {
                            tpr2 /= (double)(R[tmp[k]] - L[tmp[k]] + 1);
                        } else {
                            tpr2 *= 0.0;
                        }
                    } else {
                        tpr2 *= max(0.0, (double)(min(R[tmp[k]] - L[tmp[k]] + 1, sp - L[tmp[k]]))) / (double)(R[tmp[k]] - L[tmp[k]] + 1);
                    }
                }
                ans += (double)sp * tpr1 * tpr2;
                if (sp == 5) cout<<"x"<<i<<" "<<j<<" "<<ans<<endl;
            }
        }
        if (sp == 5) cout<<ans<<endl;
        for (int j = 0; j < n; ++j) {
            double tpr = 1.0;
            if (__builtin_popcount(j) < 2) continue;
            for (int k = 0; k < n; ++k) {
                if ((1<<k) & j) {
                    if (sp >= L[k] && sp <= R[k]) {
                        tpr /= (double)(R[k] - L[k] + 1);
                    } else {
                        tpr *= 0.0;
                    }
                } else {
                    tpr *= max(0.0, (double)(min(R[k] - L[k] + 1, sp - L[k]))) / (double)(R[k] - L[k] + 1);
                }
            }
            ans += (double)sp * tpr;
        }
        if (sp == 5) cout<<ans<<endl;
       // cout<<sp<<" "<<ans<<endl;
    }
    printf("%.9lf\n", ans);
    return 0;
}
