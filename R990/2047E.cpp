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
#define M 2010
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
struct node {
    int l,r;
    int num;
} tree[2][N<<2];
map<int,int> mp;
vector<pair<int,int>> ps;
int yc;
int ax, ay;
vector<pair<int, vector<int>>> v;
void query1(int id, int id2, int k, int& yy) {
    if (tree[id][id2].l == tree[id][id2].r) {
        if(0>=k) yy=min(yy, tree[id][id2].l);
        return;
    }
    int mid=(tree[id][id2].l+tree[id][id2].r)/2;
    if (tree[id][id2*2].num >= k) {
        yy = min(yy, mid+1);
        query1(id, id2*2, k, yy);
    } else {
        query1(id, id2*2+1, k-tree[id][id2*2].num, yy);
    }
}
void query2(int id, int id2, int k, int& yy) {
    if (tree[id][id2].l == tree[id][id2].r) {
        if(tree[id][id2].num >= k) yy=min(yy, tree[id][id2].l);
        return;
    } 
    int mid=(tree[id][id2].l+tree[id][id2].r)/2;
    if (tree[id][id2*2+1].num >= k) {
        yy = max(yy, mid+1);
        query2(id, id2*2+1, k, yy);
    } else {
        query2(id, id2*2, k-tree[id][id2*2+1].num, yy);
    }
}
void update(int id, int id2, int p, int v) {
    if (tree[id][id2].l==tree[id][id2].r) {
        tree[id][id2].num += v;
        return;
    }
    int mid=(tree[id][id2].l+tree[id][id2].r)/2;
    if (p <= mid) {
        update(id, id2*2, p, v);
    } else {
        update(id, id2*2+1, p, v);
    }
    tree[id][id2].num = tree[id][id2*2].num + tree[id][id2*2+1].num;
}
void build(int id, int id2, int l, int r) {
    tree[id][id2].l = l;
    tree[id][id2].r = r;
    if (l == r) {
        tree[id][id2].num=0;
        return ;
    }
    int mid=(l+r)/2;
    build(id, id2*2, l, mid);
    build(id, id2*2+1, mid+1, r);
    tree[id][id2].num = tree[id][id2*2].num + tree[id][id2*2+1].num;
}
pair<int,int> calc2(int id, int k) {
    int lb=yc+1, rb=0;
    query1(id, 1, k, lb);
    query2(id, 1, k, rb);
    if (lb <= rb && lb >= 1 && rb <= yc) {
        return make_pair(lb, rb);
    }
    return make_pair(yc+1, 0);
}
pair<int,int> calc(int k) {
    auto pr1 = calc2(0, k);
    auto pr2 = calc2(1, k);
    if (pr1.second >= pr2.first && pr1.first <= pr2.second) {
        return make_pair(max(pr1.first, pr2.first), min(pr1.second, pr2.second));
    }
    return make_pair(yc+1, 0);
}
bool check(int k) {
  //  cout<<"k="<<k<<endl;
    build(0, 1, 1, yc);
    build(1, 1, 1, yc);
  //  cout<<"v.size="<<v.size()<<endl;
    for (int i = 0; i < v.size(); ++i) {
        auto tmp = v[i].second;
        for (auto y : tmp) {
          //  cout<<"y="<<y<<endl;
            update(1, 1, y, 1);
        }
    }
  //  cout<<"v="<<tree[0][1].num<<" "<<tree[1][1].num<<endl;
    auto pr = calc(k);
 //   cout<<"xy="<<pr.first<<" "<<pr.second<<endl;
    if (pr.first <= pr.second && pr.first>=1 && pr.second <= yc) {
        ax = v[0].first;
        ay = pr.first;
        return true;
    }
    for (int i = 0; i < v.size(); ++i) {
        int x= v[i].first;
        
        for (auto y : v[i].second) {
            update(1, 1, y, -1);
            update(0, 1, y, 1);
        }
      //  cout<<"ii="<<i<<" "<<x<<" "<<tree[0][1].num<<" "<<tree[1][1].num<<endl;
        auto pr = calc(k);
      //  cout<<"i="<<i<<" "<<x<<" "<<pr.first<<" "<<pr.second<<endl;
        if (pr.first <= pr.second && pr.first>=1 && pr.second <= yc) {
            ax = (i+1<v.size() ? v[i+1].first : v[i].first+1);
            ay = pr.first;
            return true;
        }
    }
    return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      ps.clear();
      mp.clear();
      yc=0;
      for (int i = 1; i <= n; ++i) {
          int x,y;
          scanf("%d%d", &x, &y);
          ps.push_back(make_pair(x, y));
          if (mp.find(y) == mp.end()) {
              mp[y] = ++yc;
          }
      }
      yc = 0;
      for (auto& itr : mp) {
          
          itr.second = ++yc;
         // cout<<"mp1="<<itr.first<<" "<<itr.second<<" "<<yc<<endl;
      }
   //   cout<<"fff="<<mp[-2]<<endl;
      v.clear();
      vector<pair<int,int>> rk;
      rk.clear();
      for (int i = 0; i < n; ++i) {
        //  cout<<"i="<<i<<" "<<ps[i].first<<" "<<ps[i].second<<endl;
          rk.push_back(make_pair(ps[i].first, mp[ps[i].second]));
         // cout<<"fff="<<mp[-2]<<endl;
      }
    //   cout<<"fff="<<mp[-2]<<endl;
    //   for (auto itr : mp) {
          
    //      // itr.second = ++yc;
    //       cout<<"mp11="<<itr.first<<" "<<itr.second<<" "<<yc<<endl;
    //   }
      sort(rk.begin(), rk.end());
      for (int i = 0; i < rk.size(); ++i) {
          int x = rk[i].first;
          int y = rk[i].second;
          if (v.empty() || x != v.back().first) {
              v.push_back(make_pair(x, vector<int>()));
              v.back().second.push_back(y);
          } else {
              v.back().second.push_back(y);
          }
      }
    //   for (auto itr : mp) {
          
    //     //  itr.second = ++yc;
    //       cout<<"mp2="<<itr.first<<" "<<itr.second<<" "<<yc<<endl;
    //   }
      int l =0, r = n;
      while(l < r) {
          int mid=(l+r+1)/2;
          if (check(mid)) {
              l = mid;
             // cout<<"axy="<<mid<<" "<<ax<<" "<<ay<<endl;
          } else {
              r = mid-1;
          }
      }
      printf("%d\n", r);
    //   for (auto itr : mp) {
          
    //     //  itr.second = ++yc;
    //       cout<<"mp3="<<itr.first<<" "<<itr.second<<" "<<yc<<endl;
    //   }
      for (auto itr : mp) {
          if (itr.second == ay) {
              ay = itr.first;
              break;
          }
      }
      printf("%d %d\n", ax, ay);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
