
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
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    if (k == n*n-1) {
      puts("No");
      continue;
    }
    int cnt=0;
    vector<string> ans;
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      string s="";
      for (int j = 1; j <= n; ++j) {
        cnt++;
        if (cnt <= k) {
          s += "U";
        } else {
          if (i == n) {
            if (j < n) s += "R";
            else s += "L";
          } else {
            s += "D";
          }
        }
      }
      ans.push_back(s);
    }
    puts("Yes");
    for (int i = 0; i < n; ++i) {
      cout<<ans[i]<<endl;
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
