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
int a[N];
int sum[N];
vector<int> check(int x) {
    sum[0]=0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= x) {
            sum[i] = sum[i-1]+1;
        } else {
            sum[i] = sum[i-1]-1;
        }
    }
    int mn = 0;
    int l = 0;
    int idx=0;
    vector<int> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
        while(l + 1 < i && i-l-1 >= k) {
            l++;
            if (sum[l]<mn) {
                mn=min(mn, sum[l]);
                idx=l;
            }
        }
        if (i-l>=k && sum[i]>=mn) {
            v.push_back(idx);
            v.push_back(i);
            return v;
        }
    }
    v.clear();
    return v;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int l = 1, r = n;
    int ll = -1, rr=-1;
    while(l < r) {
        int mid=(r+l+1)/2;
        auto v = check(mid);
        if (!v.empty()) {
            l = mid;
        } else {
            r = mid-1;
        }
    }
    auto v = check(r);
    ll = v[0];
    rr = v[1];
    printf("%d %d %d\n", r, ll+1, rr);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
