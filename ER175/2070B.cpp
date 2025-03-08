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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    ll k;
    scanf("%d%d%lld", &n, &x, &k);
  //  printf("%lld\n", (k-1)/2+1);
    string s;
    cin>>s;
    ll cur=x;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') cur--;
        else cur++;
        if (cur == 0) {
            k -= (i+1);
            break;
        }
    }
    ll ans=0LL;
    if (cur == 0) {
        ans++;
        int i;
        for (i = 0; i < n; ++i) {
            if (s[i] == 'L') cur--;
            else cur++;
            if (cur == 0) break;
        }
        if (i < n) {
            i++;
            ll q=k/i;
            ll r = k%i;
            ans += q;
        }
        printf("%lld\n", ans);
    } else {
        printf("%lld\n", ans);
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
