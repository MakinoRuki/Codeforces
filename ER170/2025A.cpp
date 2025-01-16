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
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
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
    string s1,s2;
    cin>>s1>>s2;
    int cnt=0;
    int n1=(int)s1.size();
    int n2=(int)s2.size();
    for (int i = 0; i < min(n1, n2); ++i) {
        if (s1[i] == s2[i]) cnt++;
        else break;
    }
    int ans=n1+n2;
    if (cnt>0) {
        ans = min(ans, n1+n2-cnt+1);
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
