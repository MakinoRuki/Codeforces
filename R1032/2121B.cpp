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
#define M 1002
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
    string s;
    cin>>s;
    bool found=false;
    set<int> ss;
    ss.clear();
    for (int i = 0; i < n; ++i) {
        if (i > 0 && i < n-1 && ss.find(s[i]-'a') != ss.end()) {
            found=true;
            break;
        }
        ss.insert(s[i]-'a');
    }
    ss.clear();
    for (int i = n-1; i >= 0; --i) {
        if (i > 0 && i < n-1 && ss.find(s[i]-'a') != ss.end()) {
            found=true;
            break;
        }
        ss.insert(s[i]-'a');
    }
    if (found) puts("Yes");
    else puts("No");
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
