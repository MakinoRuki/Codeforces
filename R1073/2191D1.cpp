

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
#define M 1500
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int c[N];
int nxt[N];
int sum[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    cnt[n+1]=0;
    for (int i = n; i >= 1; --i) {
      cnt[i] = cnt[i+1];
      if (s[i-1] == '(') cnt[i]++;
    }
    bool found=false;
    for (int i = 1; i +1 <= n; ++i) {
      if (s[i-1] == ')' && s[i] == '(') {
        if (i+2 <= n && cnt[i+2]) {
          found=true;
          break;
        }
      }
    }
    if (found) printf("%d\n", n-2);
    else puts("-1");
  }
  
  return 0;
}

