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
#define M 1005
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
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    vector<pair<int,int>> v;
    v.clear();
    int cur=0,cnt=0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i] == s[i-1]) {
            cnt++;
            cur = s[i]-'0';
        } else {
            if (cnt > 0) {
                v.push_back(make_pair(cur, cnt));
                cur = s[i]-'0';
                cnt = 1;
            }
        }
    }
    if (cnt > 0) v.push_back(make_pair(cur, cnt));
    int sz = (int)v.size();
    int ans=n;
    if (sz == 1) {
        if (v[0].first == 1) ans++;
    } else if (sz <= 3) {
        ans++; 
    } else {
        if (v[0].first == 1) ans += sz-2;
        else ans += sz-3;
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
