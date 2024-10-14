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
#define N 500005
#define M 505
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
    int x,y;
    scanf("%d", &n);
    string ans="";
    bool fwd = true;
    while(ans.size() < n) {
      int res;
      if (fwd) {
        string tmp = ans + "0";
        cout<<"? "<<tmp<<endl;
        fflush(stdout);
        scanf("%d", &res);
        if (res) {
          ans += "0";
        } else {
          tmp = ans + "1";
          cout<<"? "<<tmp<<endl;
          fflush(stdout);
          scanf("%d", &res);
          if (res) {
            ans += "1";
          } else {
            fwd = !fwd;
          }
        }
      } else {
        string tmp = "0" + ans;
        cout<<"? "<<tmp<<endl;
        fflush(stdout);
        scanf("%d", &res);
        if (res) {
          ans = "0" + ans;
        } else {
          ans = "1" + ans;
        }
      }
    }
    cout<<"! "<<ans<<endl;
    fflush(stdout);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

