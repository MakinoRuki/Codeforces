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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m;
int k;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    set<int> id0,id1,id2;
    id0.clear();
    id1.clear();
    id2.clear();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        if (a[i] == 0) id0.insert(i);
        if (a[i] == 1) id1.insert(i);
        if (a[i] == 2) id2.insert(i);
    }
    sort(b+1, b+n+1);
    vector<pair<int,int>> ans;
    ans.clear();
    for (int i = n; i >= 1; --i) {
        if (b[i] == 2) {
            if (a[i] == 2) {
                id2.erase(i);
            } else if (a[i] == 1) {
                auto x2 = *id2.begin();
                id2.erase(x2);
                int x1 = i;
                swap(a[x2], a[x1]);
                ans.push_back(make_pair(x2, x1));
                id1.erase(i);
                id1.insert(x2);
            } else {
                auto x2 = *id2.begin();
                id2.erase(x2);
                auto x1 = *id1.begin();
                id1.erase(x1);
                int x0=i;
                id0.erase(i);
                swap(a[x0], a[x1]);
                ans.push_back(make_pair(x0, x1));
                swap(a[i], a[x2]);
                ans.push_back(make_pair(x2, i));
                id0.insert(x1);
                id1.insert(x2);
            }
        } else if (b[i] == 1) {
            if (a[i] == 1) id1.erase(i);
            else {
                auto x1=*id1.begin();
                id1.erase(x1);
                swap(a[i], a[x1]);
                ans.push_back(make_pair(i, x1));
                id0.insert(x1);
            }
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
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

