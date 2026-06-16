
#include <iostream>
#include <sstream>
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
#define N 2000005
#define M 5002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
vector<pair<int,int>>ps;
int lmx[N], lmn[N];
int rmx[N], rmn[N];
int main() {
    // 1. 关同步流，因为你用了 cin >> t; 后面又混用 scanf/printf，极其危险
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> t)) return 0;
    
    for (int cas = 1; cas <= t; ++cas) {
        cin >> n;
        
        // 2. 将 ps 改为局部变量，每组数据自动销毁/动态分配，绝无残留
        vector<pair<int,int>> ps(n);
        for (int i = 0; i < n; ++i) {
            cin >> ps[i].first >> ps[i].second;
        }

        // 3. X 轴离散化 (用现代 C++ 优雅的一行流，防越界且快)
        vector<int> rkX(n);
        for (int i = 0; i < n; ++i) rkX[i] = ps[i].first;
        sort(rkX.begin(), rkX.end());
        rkX.erase(unique(rkX.begin(), rkX.end()), rkX.end());
        int xn = rkX.size();
        for (int i = 0; i < n; ++i) {
            ps[i].first = lower_bound(rkX.begin(), rkX.end(), ps[i].first) - rkX.begin() + 1;
        }

        // 4. Y 轴离散化
        vector<int> rkY(n);
        for (int i = 0; i < n; ++i) rkY[i] = ps[i].second;
        sort(rkY.begin(), rkY.end());
        rkY.erase(unique(rkY.begin(), rkY.end()), rkY.end());
        int yn = rkY.size();
        for (int i = 0; i < n; ++i) {
            ps[i].second = lower_bound(rkY.begin(), rkY.end(), ps[i].second) - rkY.begin() + 1;
        }

        // 5. 【核心修复】在使用全局大数组前，根据本次的真实边界 xn 进行精准初始化！
        // 只需要初始化到 xn + 1 即可，千万别全阵列 memset
        for (int i = 0; i <= xn + 1; ++i) {
            lmx[i] = -inf; lmn[i] = inf;
            rmx[i] = -inf; rmn[i] = inf;
        }

        sort(ps.begin(), ps.end());
        for (int i = 1; i <= n; ++i) {
            int xid = ps[i-1].first;
            int yid = ps[i-1].second;
            if (i == 1) {
                lmx[xid] = yid;
                lmn[xid] = yid;
            } else {
                if (ps[i-1].first != ps[i-2].first) {
                    lmx[xid] = lmx[xid-1];
                    lmn[xid] = lmn[xid-1];
                }
                lmx[xid] = max(lmx[xid], yid);
                lmn[xid] = min(lmn[xid], yid);
            }
        }

        // 这里的边界处理：确保从 xn 开始往回倒时，出界的 xn+1 拥有安全的初始值
        rmx[xn + 1] = -inf;
        rmn[xn + 1] = inf;

        for (int i = n; i >= 1; --i) {
            int xid = ps[i-1].first;
            int yid = ps[i-1].second;
            if (i == n) {
                rmx[xid] = yid;
                rmn[xid] = yid;
            } else {
                if (ps[i-1].first != ps[i].first) {
                    rmx[xid] = rmx[xid+1];
                    rmn[xid] = rmn[xid+1];
                }
                rmx[xid] = max(rmx[xid], yid);
                rmn[xid] = min(rmn[xid], yid);
            }
        }

        ll ans = 0LL;
        int cur = 1;
        while (cur <= n) {
            int i = cur;
            while (i <= n && ps[i-1].first == ps[cur-1].first) i++;
            if (i > n) break;
            int xid = ps[cur-1].first;
            int l1 = lmn[xid];
            int r1 = lmx[xid];
            int l2 = rmn[xid+1];
            int r2 = rmx[xid+1];
            
            int lb = max(l1, l2);
            int rb = min(r1, r2);
            if (lb < rb) {
                ans += (rb - lb);
            }
            cur = i;
        }
        cout << ans << "\n";
    }
    return 0;
}
