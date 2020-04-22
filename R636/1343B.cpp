#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define N 200005
using namespace std;
typedef long long ll;
int t, n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		n /= 2;
		if (n%2) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			//n /= 2;
			vector<int>ans;
			ans.clear();
			for (int i = 1; i <= n; ++i) {
				ans.push_back(i*2);
			}
			int tot = ans[0]+ans.back();
			n /= 2;
			vector<int> tmp;
			tmp.clear();
			for (int i = 1; i <= n; ++i) {
				ans.push_back(2*i-1);
				tmp.push_back(tot-(2*i-1));
			}
			reverse(tmp.begin(), tmp.end());
			for (int i =0;i < tmp.size(); ++i) {
				ans.push_back(tmp[i]);
			}
			for (int i = 0; i < ans.size(); ++i) {
				printf("%d", ans[i]);
				if (i < ans.size()-1) cout<<" ";
				else cout<<endl;
			}
		}
	}
	return 0;
}
