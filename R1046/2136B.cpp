
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
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);
    string s;
    cin>>s;
    int cnt=0;
    int cur=0;
    bool ok=true;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        cnt++;
        cur++;
      } else {
        cur = 0;
      }
      if (cur >= k) {
        ok=false;
        break;
      }
    }
    if (!ok) {
      puts("No");
      continue;
    }
    int l=1,r=n;
    for (int i = 1; i <= n; ++i) {
      if (s[i-1] == '1') {
        a[i] = l++;
      } else {
        a[i] = r--;
      }
    }
    puts("Yes");
    for (int i = 1; i <= n; ++i) {
      printf("%d ", a[i]);
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
