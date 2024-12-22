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
#define N 200005
#define M 16
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
int a[N];
set<int> ss;
void check(string& s, int l, int r) {
    for (int i = l; i <= r; ++i) {
        if (i >= 0 && i + 3 < s.size()) {
            if (s.substr(i, 4) == "1100") {
                if (ss.find(i) == ss.end()) {
                    ss.insert(i);
                }
            } else {
                if (ss.find(i) != ss.end()) {
                    ss.erase(i);
                }
            }
        }
    }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    ss.clear();
    bool found=false;
    for (int i = 0; i + 3 < s.size(); ++i) {
        if (s.substr(i, 4) == "1100") {
            ss.insert(i);
        }
    }
    scanf("%d", &q);
    while(q-->0) {
        int x,v;
        scanf("%d%d", &x, &v);
        x--;
        s[x] = '0'+v;
        check(s, x-3, x);
        if ((int)ss.size()>0) puts("YES");
        else puts("NO");
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

