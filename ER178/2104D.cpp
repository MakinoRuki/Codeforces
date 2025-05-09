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
#define N 1000005
#define M 6000000
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
vector<int> ps;
bool ip[M];
ll sum[N];
int main() {
    ps.clear();
  for (int i = 1; i < M; ++i) {
    ip[i]=true;
  }
  for (int i = 2; i < M; ++i) {
    if (ip[i]) {
        ps.push_back(i);
        for (int j = i*2; j < M; j += i) {
            ip[j]=false;
        }
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
       // tot += (ll)a[i]-2;
    }
    sort(a+1, a+n+1);
    sum[n+1]=0LL;
    for (int i = n; i >= 1; --i) {
        sum[i] = sum[i+1]+a[i];
    }
    int cur=0;
    int ans=0;
    for (int i = n; i >= 1; --i) {
        ll num = n-i+1;
        while(cur < ps.size()) {
            if (tot + ps[cur]-2 <= sum[i]-num*2LL) {
                tot += ps[cur]-2;
                cur++;
            } else {
                break;
            }
        }
        if (cur >= n-i+1) {
            ans = max(ans, n-i+1);
        }
    }
    printf("%d\n", n-ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
