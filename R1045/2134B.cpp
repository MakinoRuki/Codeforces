
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
ll a[N];
vector<int> ps;
bool pr[N];
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  memset(pr, false, sizeof(pr));
  ps.clear();
  for (int i = 2; i < N; ++i) {
    if (!pr[i]) {
      ps.push_back(i);
      for (int j = i*2; j < N; j += i) {
        pr[j] = true;
      }
    }
  }
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    int x,y;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    for (auto p : ps) {
      // a[i]+xk=0(% p) => xk=-a[i](%p) => x=(-a[i])(k^(-1))(% p) => gcd(k,p)=1.
      if (getgcd(p, k) == 1) {
        for (int i = 1; i <= n; ++i) {
          while(a[i]%p) {
            a[i] += k;
          }
        }
        break;
      }
    }
 //   cout<<"n="<<n<<endl;
    for (int i = 1; i <= n; ++i) {
      printf("%lld ", a[i]);
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
