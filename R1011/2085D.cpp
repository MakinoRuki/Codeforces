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
#define N 600005
#define M 750
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
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int x = (n-k+k)/(k+1);
    int i = n-k+1;
    ll tot=0LL;
    set<pair<int,int>> ss;
    ss.clear();
    int cnt=0;
    while(i > 1) {
        int j = max(1, i-(k+1));
        cnt++;
        for (int p = j; p < i; ++p) {
            ss.insert(make_pair(a[p], p));
            tot += a[p];
        }
        while(ss.size() > cnt) {
            tot -= (*ss.begin()).first;
            ss.erase(ss.begin());
        }
        i = j;
    }
    printf("%lld\n", tot);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
