#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 2000005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int t;
unordered_set<int> cnt1, cnt2;
unordered_set<int> cnt;
int getst(int c) {
  int r1 = (cnt1.find(c) != cnt1.end());
  int r2 = (cnt2.find(c) != cnt2.end());
  if (r1 && r2) return 0;
  if (r1) return 2;
  return 1;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    cnt1.clear();
    cnt2.clear();
    cnt.clear();
    for (int i = 1; i <= m; ++i) {
      int r, c;
      scanf("%d%d", &r, &c);
      if (r == 1) cnt1.insert(c);
      else cnt2.insert(c);
      cnt.insert(c);
    }
    vector<int> cv(cnt.begin(), cnt.end());
    sort(cv.begin(), cv.end());
    int pre=0;
    bool ok = true;
    for (int i = 0; i <cv.size(); ++i) {
      if (pre==0) {
        pre = getst(cv[i]);
      } else {
        int det=cv[i]-cv[i-1]-1;
        if (getst(cv[i]) == 0) {
          ok=false;
          break;
        }
        if (det%2==0) {
          if (getst(cv[i]) != pre) {
            ok=false;
            break;
          } else {
            pre=0;
          }
        } else {
          if (getst(cv[i]) == pre) {
            ok=false;
            break;
          } else {
            pre = 0;
          }
        }
      }
    }
    if (pre) {
      ok=false;
    }
    if (ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
