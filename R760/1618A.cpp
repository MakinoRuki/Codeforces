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
#define N 500005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k;
int t;
string s;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    vector<int> bs;
    bs.clear();
    for (int i = 1; i <= 7; ++i) {
      int b;
      scanf("%d", &b);
      bs.push_back(b);
    }
    vector<int> ans;
    ans.clear();
    for (int i = 0; i < 7; ++i) {
      for (int j = 0; j < 7; ++j) {
        if (i == j) continue;
        for (int k = 0; k < 7; ++k) {
          if (k == i || k == j) continue;
          vector<int> as;
          as.clear();
          as.push_back(bs[i]);
          as.push_back(bs[j]);
          as.push_back(bs[k]);
          as.push_back(bs[i] + bs[j]);
          as.push_back(bs[k] + bs[j]);
          as.push_back(bs[i] + bs[k]);
          as.push_back(bs[i]+bs[j]+bs[k]);
          sort(as.begin(), as.end());
          int k2;
          for (k2 = 0; k2 < 7; ++k2) {
            if (as[k2] != bs[k2]) {
              break;
            }
          }
          if (k2 >= 7) {
            ans.push_back(bs[i]);
            ans.push_back(bs[j]);
            ans.push_back(bs[k]);
            break;
          }
        }
        if (!ans.empty()) break;
      }
      if (!ans.empty()) break;
    }
    printf("%d %d %d\n", ans[0], ans[1], ans[2]);
  }
  return 0;
}
