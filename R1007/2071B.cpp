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
bool check(ll x) {
    ll qr = (ll)sqrt(x);
    if (qr * qr == x) return false;
    return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n==1) {
        puts("-1");
    } else {
        ll sum = (ll)n*(ll)(n+1)/2LL;
        if (!check(sum)) {
            puts("-1");
        } else {
            for (int i = 1; i <= n; ++i) {
                a[i] = i;
            }
            sum=0LL;
            for (int i = 1; i < n; ++i) {
                sum += a[i];
                if (!check(sum)) {
                    sum -= a[i];
                    swap(a[i], a[i+1]);
                    sum += a[i];
                }
            }
            for (int i = 1; i <= n; ++i) {
                printf("%d ", a[i]);
            }
            cout<<endl;
        }
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
