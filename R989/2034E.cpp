#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 200005
#define M 16
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int fac[11];
bool check2(vector<int>& v1, vector<int>& v2) {
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}
bool check(vector<int>& v, vector<int>& v0, vector<int>& v1, vector<int>& v2) {
    bool res=check2(v,v0)||check2(v,v1) || check2(v,v2);
    return res;
}
int main() {
  fac[0]=1;
  for (int i = 1; i <= 10; ++i) {
    fac[i]=fac[i-1]*i;
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    if (n == 1) {
        if (k > 1) puts("NO");
        else {
            puts("YES");
            puts("1");
        }
        continue;
    }
    if (k == 1 || (n <= 10 && (k==fac[n]-1))) {
        puts("NO");
        continue;
    }
    if (n <= 10 && k>fac[n]) {
        puts("NO");
        continue;
    }
    vector<vector<int>> ans;
    ans.clear();
    if (k%2) {
        if ((n%2)==0) {
            puts("NO");
            continue;
        } else {
            vector<int> v0;
            vector<int> v1(n, 0);
            vector<int> v2(n,0);
            int cur=0;
            int x1=n,x2=(n+1)/2;
            for (int i = 0; i < n; ++i) {
                v1[cur] = x1;
                x1--;
                v2[cur] = x2;
                x2--;
                cur += 2;
                if (cur >= n) {
                    cur = 1;
                    x1 = n/2;
                    x2 = n;
                }
            }
            vector<int> v;
            v.clear();
            v0.clear();
            for (int i = 1; i <= n; ++i) {
                v.push_back(i);
                v0.push_back(i);
            }
            ans.push_back(v0);
            ans.push_back(v1);
            ans.push_back(v2);
            vector<int> vv;
            vv.clear();
            do {
                // if ((int)ans.size() == (k-3)) {
                //     ans.push_back(v);
                //     ans.push_back(vector<int>(n,0));
                //     for (int i = 0; i < v.size(); ++i) {
                //         ans.back()[i] = v1[v[i]-1];
                //     }
                //     ans.push_back(vector<int>(n,0));
                //     for (int i = 0; i < v.size(); ++i) {
                //         ans.back()[i] = v2[v[i]-1];
                //     }
                //     break;
                // }
                if ((int)ans.size() == k) break;
                if (check(v, v0,v1,v2)) continue;
                vv.clear();
                for (int i = 0; i < n; ++i) {
                    vv.push_back(n+1-v[i]);
                }
                if (check(vv, v0, v1, v2)) continue;
                ans.push_back(v);
                ans.push_back(vv);
            } while(next_permutation(v.begin(), v.end()));
        }
    } else {
        vector<int> v;
        v.clear();
        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
        }
        vector<int> vv;
        vv.clear();
        do {
            ans.push_back(v);
            vv.clear();
            for (int i = 0; i < n; ++i) {
                vv.push_back(n+1-v[i]);
            }
            ans.push_back(vv);
            if ((int)ans.size() == k) break;
        } while(next_permutation(v.begin(), v.end()));
    }
    puts("YES");
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", ans[i][j]);
        }
        cout<<endl;
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

