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
    //scanf("%d", &n);
    string s;
    cin>>s;
    int id = -1;
    for (int i = 0; i < s.size()-1; ++i) {
      if (s[i] == s[i+1]) {
        id=i;
        break;
      }
    }
    string ans="";
    if (id >= 0) {
      ans = s.substr(0, id+1);
      if (s[id] == 'z') {
        ans += "y";
      } else {
        ans += "z";
      }
      ans += s.substr(id+1);
    } else {
      if (s.back() == 'z') {
        ans = s + "y";
      } else {
        ans = s + "z";
      }
    }
    cout<<ans<<endl;
  } 
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

