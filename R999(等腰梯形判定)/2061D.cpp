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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    map<int,int> ca, cb;
    ca.clear();
    cb.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ca[a[i]]++;
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
      cb[b[i]]++;
    }
    bool ok = true;
    int tot=m;
    while(!cb.empty()) {
      auto x = (*cb.rbegin()).first;
      if (ca.empty()) {
        ok=false;
        break;
      }
      if (tot > n) {
        ok=false;
        break;
      }
      // cout<<"x="<<x<<endl;
      // if (x==1) {
      //   cout<<(int)ca.size()<<endl;
      //   if (ca.find(x) != ca.end()) cout<<"v="<<ca[x]<<endl;
      // }
      if (x < (*ca.rbegin()).first) {
        ok=false;
        break;
      }
      if (ca.find(x) != ca.end() && ca[x]) {
        cb[x]--;
        ca[x]--;
        if (ca[x] == 0) ca.erase(x);
        if (cb[x] == 0) cb.erase(x);
        tot--;
      } else {
        cb[x]--;
        if (cb[x] == 0) cb.erase(x);
        tot--;
        if (x%2) {
          cb[x/2]++;
          cb[x/2+1]++;
        } else {
          cb[x/2]+=2;
        }
        tot += 2;
      }
    }
    if (!ca.empty() || !ok) puts("No");
    else puts("Yes");
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
