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
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int q, n;
int cnt[N];
int cnt2[10];
int main() {
	cin>>n;
	memset(cnt, 0, sizeof(cnt));
	memset(cnt2, 0, sizeof(cnt2));
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	for (int i = 1; i <= 100000; ++i) {
		if (cnt[i] < 8) {
			cnt2[cnt[i]]++;
		} else {
			cnt2[8]++;
		}
	}
	cin>>q;
	for (int i = 1; i <= q; ++i) {
		string s;
		int x;
		cin>>s;
		scanf("%d", &x);
		if (s=="+") {
			if (cnt[x]<8) {
				if (cnt[x]>0) cnt2[cnt[x]]--;
				cnt[x]++;
				if (cnt[x]>=8) cnt2[8]++;
				else cnt2[cnt[x]]++;
			} else {
				cnt[x]++;
			}
		} else {
			if (cnt[x]<=8) {
				if (cnt[x]>0) cnt2[cnt[x]]--;
			} else {
				cnt2[8]--;
			}
			cnt[x]--;
			if (cnt[x]<=8) cnt2[cnt[x]]++;
			else cnt2[8]++;
		}
		bool found=false;
		int tot=0;
		for (int j = 2; j <= 8; ++j) {
		//	cout<<"j="<<j<<" "<<cnt2[j]<<endl;
			if (cnt2[j]==0) continue;
			if (j >= 4) {
				if (!found) {
					found=true;
					tot += (j-4)/2 + j/2*(cnt2[j]-1);
				} else {
					tot += j/2*cnt2[j];
				}
			} else {
				tot += j/2*cnt2[j];
			}
		}
		if (tot >= 2 && found) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
