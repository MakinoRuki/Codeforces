
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
#define M 10002
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
int c[N];
ll mx[2][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    vector<vector<int>> v;
    v.clear();
    map<int,int> cnt;
    cnt.clear();
    ll tot=0LL;
    int m=0;
    for (int i = 1; i <= n; ++i) {
      mx[0][i]=-1;
      mx[1][i]=-1;
      int l;
      scanf("%d", &l);
      m += l;
      tot += (ll)l * (ll)(n-2);
      vector<int> tmp;
      tmp.clear();
      for (int j = 1; j <= l; ++j) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
        tmp.push_back(x);
      }
      sort(tmp.begin(), tmp.end());
      v.push_back(tmp);
      int cur=0;
      for (auto x : tmp) {
        if (x == cur) {
          cur++;
        } else if (x > cur) {
          if (mx[0][i] < 0) {
            mx[0][i] = cur;
            cur++;
            if (cur < x) {
              mx[1][i] = cur;
              break;
            } else {
              cur++;
            }
          } else if (mx[1][i] < 0) {
            mx[1][i] = cur;
            break;
          }
        }
      }
      if (mx[0][i] < 0) {
        mx[0][i] = cur;
        mx[1][i] = cur+1;
      } else if (mx[1][i] < 0) {
        mx[1][i] = cur;
      }
    }
    ll ans=0LL;
    for (int i = 0; i < v.size(); ++i) {
      ll sz = (int)v[i].size();
      ll dt = tot - sz * (ll)(n-2);
      ans += mx[0][i+1] * dt;
      for (int j = 0; j < v[i].size(); ++j) {
        if (v[i][j] > mx[0][i+1]) {
          ans += mx[0][i+1] * (ll)(n-1);
        } else {
          if (j-1>=0 && (v[i][j] == v[i][j-1])) {
            ans += mx[0][i+1] * (ll)(n-1);
          } else if (j+1<v[i].size() && (v[i][j] == v[i][j+1])) {
            ans += mx[0][i+1] * (ll)(n-1);
          } else {
            ans += (ll)v[i][j] * (ll)(n-1);
          }
        }
      }
      ll num = 0LL;
      if (cnt.find(mx[0][i+1]) != cnt.end()) {
        num = cnt[mx[0][i+1]];
      }
      ll num2 = m-sz-num;
    //  cout<<"i="<<i<<" "<<num<<" "<<num2<<" "<<mx[0][i+1]<<" "<<mx[1][i+1]<<endl;
      ans += num*mx[1][i+1];
      ans += num2*mx[0][i+1];
    }
    printf("%lld\n", ans);
  }
  

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
