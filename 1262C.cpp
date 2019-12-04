#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define N 1000005
using namespace std;
typedef long long ll;
int t, n, k;
string s;
void revs(int a, int b) {
	int i = a;
	int j = b;
	while(i < j) {
		swap(s[i], s[j]);
		i++;
		j--;
	}
}
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cin>>n>>k;
		cin>>s;
		// 一步并不能保证能变成一整个valid括号序列。
		// 比如)(())(。
		// int sum=0;
		// vector<int> ans;
		// int tot=0;
		// vector<int> stk;
		// for (int i = 0; i < n; ++i) {
		// 	if (s[i] == '(') stk.push_back(i);
		// 	else {
		// 		if (stk.size() && s[stk.back()] == '(') {
		// 			stk.pop_back();
		// 		} else {
		// 			stk.push_back(i);
		// 		}
		// 	}
		// }
		// if (stk.size()) {
		// 	int ls = 0;
		// 	int pos=-1;
		// 	int ms = 0;
		// 	for (int i = 0; i < stk[0]; ++i) {
		// 		if (s[i] == '(') ls++;
		// 		else ls--;
		// 		if (ls > ms) {
		// 			ms = ls;
		// 			pos = i;
		// 		}
		// 	}
		// 	revs(pos+1, stk.back());
		// 	ans.push_back(pos+2);
		// 	ans.push_back(stk.back()+1);
		// }
		// for (int i = 0; i < n; ++i) {
		// 	if (s[i] == '(') sum++;
		// 	else sum--;
		// 	if (sum == 0) tot++;
		// }
		// if (tot > k) {
		// 	sum=0;
		// 	for (int i = 0; i < n; ++i) {
		// 		if (tot == k) break;
		// 		if (s[i] == '(') sum++;
		// 		else sum--;
		// 		if (sum == 0) {
		// 			swap(s[i], s[i+1]);
		// 			ans.push_back(i+1);
		// 			ans.push_back(i+2);
		// 			tot--;
		// 		}
		// 	}
		// } else {
		// 	int i = 0;
		// 	while(i < n && tot < k) {
		// 		// cout<<"i="<<i<<endl;
		// 		// cout<<"s="<<s<<endl;
		// 		if (s[i] == '(') {
		// 			if (s[i+1] == ')') {
		// 				i+=2;
		// 				continue;
		// 			} else {
		// 				int j = i+1;
		// 				while(j < n && s[j] != ')') j++;
		// 				revs(i+1, j);
		// 				ans.push_back(i+2);
		// 				ans.push_back(j+1);
		// 				tot++;
		// 				i += 2;
		// 			}
		// 		} else {
		// 			i++;
		// 			continue;
		// 		}
		// 		//cout<<"tot="<<tot<<endl;
		// 	}
		// }
		vector<int> ans;
		ans.clear();
		string t="";
		// 先得到理想的string。然后每个位置对比修改。
		for (int i = 1; i < k; ++i) {
			t += "()";
		}
		for (int i = 1; i <= n/2-k+1; ++i) {
			t += "(";
		}
		for (int i =1; i <= n/2-k+1; ++i) {
			t += ")";
		}
		for (int i = 0; i < n; ++i) {
			if (s[i] == t[i]) continue;
			int j = i+1;
			for (; j < n; ++j) {
				if (s[j] == t[i]) break;
			}
			revs(i, j);
			ans.push_back(i+1);
			ans.push_back(j+1);
		}
		cout<<ans.size()/2<<endl;
		for (int i = 0; i < ans.size(); i+=2) {
			cout<<ans[i]<<" "<<ans[i+1]<<endl;
		}
	}
	return 0;
}
