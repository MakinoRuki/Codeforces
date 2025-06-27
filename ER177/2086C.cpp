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
int k;
ll x;
int t;
int a[N];
int p[N];
int d[N];
bool vis[N];
int idx[N];
int len[N];
int id[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      idx[p[i]]=i;
      vis[i]=false;
      id[i] = 0;
    }
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      if (id[i] == 0) {
        cnt++;
        len[cnt] = 0;
        int cur=i;
        while(true) {
          len[cnt]++;
          id[cur]=cnt;
          cur = p[cur];
          if (cur == i) break;
        }
      }
    }
    // for (int i = 1; i <= n; ++i) {
    //   cout<<"i="<<i<<" "<<id[i]<<" "<<len[id[i]]<<endl;
    // }
    int ans=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &d[i]);
      //cout<<"i="<<i<<" "<<
      if (!vis[id[d[i]]]) {
        vis[id[d[i]]] = true;
        ans += len[id[d[i]]];
      }
      printf("%d ", ans);
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
