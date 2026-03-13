
#include <iostream>
#include <sstream>
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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
ll b[N];
ll c[N];
int pw[N];
vector<pair<int,int>> ps[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
 // cin>>x;
 // cout<<lowbit(6)<<endl;
  for (int i = 2; i < N; ++i) {
    ps[i].clear();
    int x=i;
    for (int j = 2; j * j <= i; ++j) {
      if ((x%j) == 0) {
        int cnt=0;
        while((x%j) == 0) {
          cnt++;
          x/=j;
        }
        ps[i].push_back(make_pair(j, cnt));
      }
    }
    if (x>1) ps[i].push_back(make_pair(x,1));
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int c;
    scanf("%d%d", &n, &c);
    string s;
    cin>>s;
    ll res=2LL;
    bool ok=true;
    if ((2 % c)==0) ok=false;
    if (s[0] == '0' || s[n-1] == '0') {
      puts("-1");
      continue;
    }
    for (int i = 0; i <= n; ++i) {
      pw[i]=0;
    }
    pw[2]++;
    for (int i = 2; i < n; ++i) {
      if (s[i-1] == '1') {
        res = res*2LL%mod;
        pw[2]++;
      } else {
        for (auto pr : ps[i-1]) {
          pw[pr.first] += pr.second;
        }
        res = res*(ll)(i-1)%mod;
      }
    }
    if (!ok) puts("-1");
    else {
   //   cout<<pw[2]<<endl;
      bool found=false;
      for (ll j = 2; j * j <= c && j <= n; ++j) {
        int cnt=0;
        if ((c%j) == 0) {
          while((c%j)==0) {
            cnt++;
            c/=j;
          }
          if (j>n || pw[j] < cnt) found=true;
         // cout<<"j="<<j<<" "<<pw[j]<<" "<<cnt<<endl;
        }
      }
      if (c>1) {
        if (c > n || pw[c] < 1) found=true;
      }
      if (found) printf("%lld\n", res);
      else puts("-1");
    }
  }

  // cin>>n;
  // for (int i= 1; i <= n; ++i) {
  //   a[i]=i;
  // }
  // do {
  //   if (check2()) {
  //     for (int i = 1; i <= n; ++i) {
  //       printf("%d ", a[i]);
  //     }
  //     cout<<endl;
  //   }
  // } while(next_permutation(a+1, a+n+1));
  return 0;
}

