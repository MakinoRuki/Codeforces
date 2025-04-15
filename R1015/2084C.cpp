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
map<int, pair<int,int>> mp;
map<pair<int,int>, set<int>> ids;
void myswap(int i, int j) {
    auto pi = mp[i];
    auto pj = mp[j];
    ids[pi].erase(i);
    ids[pj].erase(j);
    swap(mp[i], mp[j]);
    ids[pi].insert(j);
    ids[pj].insert(i);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    mp.clear();
    ids.clear();
    for (int i = 1; i <= n; ++i) {
        mp[i] = make_pair(a[i], b[i]);
        ids[make_pair(a[i], b[i])].insert(i);
    }
    vector<pair<int,int>> ans;
    ans.clear();
    if (n&1) {
        bool found=false;
        for (auto& itr : ids) {
            auto pr = itr.first;
            if (pr.first == pr.second) {
                auto id = *itr.second.begin();
                int sz = (int)(itr.second).size();
                if ((sz%2)==0) continue;
                found=true;
                if (id == (n+1)/2) {
                    itr.second.erase(id);
                    break;
                } else {
                    myswap(id, (n+1)/2);
                    ans.push_back(make_pair(id, (n+1)/2));
                    ids[pr].erase((n+1)/2);
                }
                break;
            }
        }
        if (!found) {
            ans.push_back(make_pair(-1,-1));
        }
    }
    if (!ans.empty() && ans[0].first==-1) {
        puts("-1");
        continue;
    }
    for (int i = 1; i <= n/2; ++i) {
        auto pr = mp[i];
        if (pr.first != pr.second) {
            auto pr2 = make_pair(pr.second, pr.first);
            if (ids.find(pr2)==ids.end()) {
                ans.clear();
                ans.push_back(make_pair(-1,-1));
                break;
            }
            auto j = *ids[pr2].begin();
            if (j != n+1-i) {
                myswap(j, n+1-i);
                ans.push_back(make_pair(j, n+1-i));
            }
            ids[pr].erase(i);
            ids[pr2].erase(n+1-i);
        } else {
            int sz = (ids[pr].size());
            if (sz % 2) {
                ans.clear();
                ans.push_back(make_pair(-1,-1));
                break;
            }
            auto j = *ids[pr].rbegin();
            if (j != n+1-i) {
                myswap(j, n+1-i);
                ans.push_back(make_pair(j, n+1-i));
            }
            ids[pr].erase(i);
            ids[pr].erase(n+1-i);
        }
    }
    if (!ans.empty() && ans[0].first == -1) {
        puts("-1");
    } else {
        printf("%d\n", (int)ans.size());
        for (auto pr : ans) {
            printf("%d %d\n", pr.first, pr.second);
        }
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
