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
#define N 500005
#define M 1002
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
ll k;
int t;
int a[N];
int bit[N];
int lowbit(int x) {
  return x&(-x);
}
ll query(int x) {
  ll res=0LL;
  if (x <= 0) return 0;
  while(x) {
    res += bit[x];
    x -= lowbit(x);
  }
  return res;
}
void update(int x) {
  while(x<=n) {
    bit[x] += 1;
    x += lowbit(x);
  }
}
ll calc() {
  for (int i = 0; i <= n; ++i) {
    bit[i]=0;
  }
  ll tot=0LL;
  for (int i = n; i >= 1; --i) {
   // cout<<"i="<<i<<endl;
    tot += query(a[i]-1);
   // cout<<"i2="<<i<<endl;
    update(a[i]);
   // cout<<"i3="<<i<<endl;
  }
  return tot;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll res1=calc();
  //  cout<<"ok"<<endl;
    vector<int> rk;
    rk.clear();
    for (int i = 1; i <= n; i += 2) {
      rk.push_back(a[i]);
    }
    sort(rk.begin(), rk.end());
    int id=0;
    for (int i = 1; i <= n; i += 2) {
      a[i] = rk[id++];
    }
   // cout<<"ok2"<<endl;
    rk.clear();
    for (int i = 2; i <= n; i += 2) {
      rk.push_back(a[i]);
    }
    sort(rk.begin(), rk.end());
    id=0;
    for (int i = 2; i <= n; i += 2) {
      a[i] = rk[id++];
    }
 //   cout<<"ok3"<<endl;
    ll res2=calc();
  //  cout<<"ok4"<<endl;
    
    // 可以观察有什么东西是不变的。
    if ((res1%2)!=(res2%2)) {
      swap(a[n], a[n-2]);
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", a[i]);
    }
    cout<<endl;
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
