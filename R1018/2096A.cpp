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
#define M 750
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
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
        ss.insert(i);
    }
    vector<int> ans;
    ans.clear();
    for (int i = s.size()-1; i >= 0; --i) {
        if (s[i] == '<') {
            ans.push_back(*ss.begin());
            ss.erase(*ss.begin());
        } else {
            ans.push_back(*ss.rbegin());
            ss.erase(*ss.rbegin());
        }
    }
    ans.push_back(*ss.begin());
    for (int i = ans.size()-1; i >= 0; --i) {
        printf("%d ", ans[i]);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
