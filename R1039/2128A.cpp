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
#define M 5002
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int c;
    scanf("%d%d", &n, &c);
    vector<int> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        ll x = a[i];
        int cnt=0;
        while(x <= c) {
            cnt++;
            x *= 2LL;
        }
        rk.push_back(cnt);
    }
    sort(rk.begin(), rk.end());
    int cur=0;
    int ans=0;
    for (int i = 0; i < rk.size(); ++i) {
        if (rk[i]>cur) {
            cur++;
        } else {
            ans++;
        }
    }
    printf("%d\n", ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
