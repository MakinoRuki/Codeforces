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
    scanf("%d", &n);
    int idn=-1,id1=-1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] == n) idn=i;
        if (a[i] == 1) id1=i;
    }
    string s;
    cin>>s;
    if (s[0] == '1' || s[n-1] == '1' || s[idn-1]=='1' || s[id1-1] == '1') {
        puts("-1");
        continue;
    }
    puts("5");
    printf("%d %d\n", 1, min(id1, idn));
    printf("%d %d\n", 1, max(id1, idn));
    printf("%d %d\n", min(id1,idn), max(id1,idn));
    printf("%d %d\n", id1, n);
    printf("%d %d\n", idn, n);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
