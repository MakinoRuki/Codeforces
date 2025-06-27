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
#define M 505
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    if (m < n || m > (n+1)*n/2LL) {
        puts("-1");
        continue;
    }
    if (m == n*(n+1)/2LL) {
        printf("%lld\n", n);
        for (int i = n; i > 1; --i) {
            printf("%d %d\n", i, i-1);
        }
        continue;
    }
    m -= n;
    vector<int> v;
    v.clear();
    for (int i = n-1; i >= 1; --i) {
        if (m >= i) {
            m -= i;
        } else {
            int cur = n-i;
            for (int j = cur+1; j <= n; ++j) {
                if (m == j-(cur+1)) {
                    v.push_back(cur);
                }
                v.push_back(j);
            }
            for (int j = cur-1; j >= 1; --j) {
                v.push_back(j);
            }
            break;
        }
    }
    printf("%d\n", v[0]);
    for (int i = 0; i < v.size()-1; ++i) {
        printf("%d %d\n", v[i], v[i+1]);
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
