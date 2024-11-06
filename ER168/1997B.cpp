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
#define N 500005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s1,s2;
    cin>>s1>>s2;
    int ans=0;
    for (int i =1; i < n-1; ++i) {
      if (s1[i] == '.' && s2[i] == '.') {
        if (s1[i-1] == 'x' && s2[i-1] == '.' && s1[i+1] == 'x' && s2[i+1] == '.') {
          ans++;
        } else if (s1[i-1] == '.' && s2[i-1] == 'x' && s1[i+1] == '.' && s2[i+1] == 'x') {
          ans++;
        }
      }
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

