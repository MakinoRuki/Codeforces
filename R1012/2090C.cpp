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
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y,z;
    scanf("%d", &n);
    set<pair<int,int>> s1;
    set<pair<int,pair<int,int>>> s2;
    s1.clear();
    s2.clear();
    vector<pair<int,int>> ans;
    ans.clear();
    int cnt=0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            x=j,y=i-j;
            x=3*x+1,y=3*y+1;
            cnt++;
            s1.insert(make_pair(x+y, x));
            if (cnt == n) break;
        }
        if (cnt==n) break;
    }
    for (int i  = 1; i <= n; ++i) {
        int tt;
        scanf("%d", &tt);
        if (tt) {
            int x1=-1,y1=-1,x2=-1,y2=-1;
            int d1=-1,d2=-1;
            if (!s1.empty()) {
                auto pr = *s1.begin();
                x1=pr.second;
                y1=pr.first-x1;
                d1=pr.first;
            }
            if (!s2.empty()) {
                auto pr = *s2.begin();
                x2=pr.second.first;
                y2=pr.second.second;
                d2=pr.first;
            }
            if (x1>=0 && x2>=0) {
                if (d1<d2 || ((d1==d2) && x1<x2) || ((d1==d2)&&(x1==x2)&&y1<y2)) {
                    ans.push_back(make_pair(x1,y1));
                    s1.erase(*s1.begin());
                    s2.insert(make_pair(x1+y1+1,make_pair(x1,y1+1)));
                    s2.insert(make_pair(x1+y1+1,make_pair(x1+1,y1)));
                    s2.insert(make_pair(x1+y1+4, make_pair(x1+1,y1+1)));
                } else {
                    ans.push_back(make_pair(x2,y2));
                    s2.erase(*s2.begin());
                }
            } else if (x1>=0) {
                ans.push_back(make_pair(x1,y1));
                s1.erase(*s1.begin());
                s2.insert(make_pair(x1+y1+1,make_pair(x1,y1+1)));
                s2.insert(make_pair(x1+y1+1,make_pair(x1+1,y1)));
                s2.insert(make_pair(x1+y1+4, make_pair(x1+1,y1+1)));
            } else if (x2>=0) {
                ans.push_back(make_pair(x2,y2));
                s2.erase(*s2.begin());
            }
        } else {
            auto pr = *s1.begin();
            int x1,y1;
            x1=pr.second;
            y1=pr.first-x1;
            ans.push_back(make_pair(x1,y1));
            s1.erase(*s1.begin());
            s2.insert(make_pair(x1+y1+1,make_pair(x1,y1+1)));
            s2.insert(make_pair(x1+y1+1,make_pair(x1+1,y1)));
            s2.insert(make_pair(x1+y1+4, make_pair(x1+1,y1+1)));
        }
    }
    for (auto pr : ans) {
        printf("%d %d\n", pr.first, pr.second);
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
