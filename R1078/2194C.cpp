
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
int vis[N];
string getres(int len) {
  string res="";
  for (int i = 1; i <= len; ++i) {
    int cur=0;
    for (int j = i; j <= n; j += len) {
      cur = (j == i ? vis[j] : cur &= vis[j]);
    }
    for (int c = 0; c < 26; ++c) {
      if ((1<<c) & cur) {
        res.push_back('a'+c);
        break;
      }
    }
  }
  string res2="";
  while(res2.size() < n) res2 += res;
  return res2;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);string s;
    for (int i = 1; i <= n; ++i) {
      vis[i]=0;
    }
    for (int i = 1; i <= k; ++i) {
      cin>>s;
      for (int c = 0; c < 26; ++c) {
        for (int j = 1; j <= n; ++j) {
          if (s[j-1] - 'a' == c) {
            vis[j] |= (1<<c);
          }
        }
      }
    }
    int ans=-1;
    for (int len = 1; len <= n; ++len) {
      if (n%len) continue;
      bool ok=true;
    //  cout<<"len="<<len<<endl;
      for (int j = 1; j <= len; ++j) {
    //    cout<<"j="<<j<<endl;
        int cur=0;
        for (int j2 = j; j2 <= n; j2 += len) {
          cur = (j == j2 ? vis[j2] : cur &= vis[j2]);
        //  cout<<"j2="<<j2<<" "<<vis[j2]<<endl;
        }
        if (cur <= 0) {
          ok=false;
          break;
        }
      }
      if (ok) {
        ans = len;
        break;
      }
    }
    string res=getres(ans);
    cout<<res<<endl;
    //printf("%d\n", ans);
  }
  return 0;
}

