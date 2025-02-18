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
    scanf("%d", &n);
    map<int,int> cnt;
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    vector<int> ids;
    ids.clear();
    for (int i = 1; i <= n; ++i) {
      if (cnt[a[i]] == 1) {
        ids.push_back(i);
      }
    }
    int l=-1,r=-1;
    int b=-1,e=-1;
    for (int i = 0; i < ids.size(); ++i) {
      if (i == 0) {
        b = ids[i];
        e = ids[i];
      } else {
        if (ids[i] == ids[i-1]+1) {
          e = ids[i];
        } else {
          if (l<0 || e-b>r-l) {
            l=b,r=e;
          }
          b = ids[i];
          e=ids[i];
        }
      }
    }
    if (l<0 || e-b>r-l) {
      l=b,r=e;
    }
    if (l<0) puts("0");
    else printf("%d %d\n", l, r);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
