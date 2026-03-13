
#include <iostream>
#include <sstream>
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
#define N 2000005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
    scanf("%d", &n);
    string s;
    cin>>s;
    int mn=0,mx=0;
    for (int i = 1; i < n-1; ++i) {
      if (s[i] == '0' && s[i-1] == '1' && s[i+1] == '1') s[i]='1'; 
    }
    int ans=0;
    int cnt=0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') cnt++;
      else {
        if (cnt) {
          mn += cnt/2+1;
          mx += cnt;
        }
        cnt=0;
      }
    }
 //   cout<<"cnt="<<cnt<<endl;
    if (cnt){
      mn += cnt/2+1;
      mx += cnt;
    }
    printf("%d %d\n", mn, mx);
  }
  return 0;
}

