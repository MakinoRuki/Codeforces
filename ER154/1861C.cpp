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
#define N 3002
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    int tot=0;
    int id0=n+1;
    int id1=-1;
    int st=0;
    int cnt=0;
    int f1=0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        if (st<0) {
          ok=false;
          break;
        }
        id1 = tot;
        id0=n+1;
        st=1;
        cnt=0;
      } else if (s[i] == '0') {
        if (tot < 2) {
          ok=false;
          break;
        }
        if (st==1) {
          ok=false;
          break;
        }
        if (st >= 0) {
          id0 = tot;
        }
        st=-1;
      } else if (s[i] == '+') {
        tot++;
        if (st>0) {
          st=0;
        }
      } else {
        tot--;
        if (tot ==0){
          st=0;
          id0=n+1;
          id1=-1;
          continue;
        }
        if (tot < id0) {
          st=0;
        }
        if (tot >0 && tot <= id1) {
          st=1;
          id1=  tot;
        }
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
