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
#define M 1002
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
int sx, sy, ex, ey;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d%d%d", &n, &sx, &sy, &ex, &ey);
    vector<double> v;
    v.clear();
    v.push_back((double)sqrt((ll)(sx-ex)*(ll)(sx-ex)+(ll)(sy-ey)*(ll)(sy-ey)));
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        v.push_back((double)a[i]);
    }
    double tot=0.0;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        tot += v[i];
    }
    if (2.0 * v.back() <= tot) {
        puts("Yes");
    } else {
        puts("No");
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
