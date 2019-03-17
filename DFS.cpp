#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define all(v)          ((v).begin()), ((v).end())
#define pb push_back
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define clr(v,d)		memset(v, d, sizeof(v))
const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = ll(1e9 + 7);
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
#define endl '\n'
void stop(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
void run(){
#ifndef ONLINE_JUDGE
	freopen("intput.txt", "r", stdin);
#endif

}
const double PI = acos(-1.0);
vector<vector<int>>adj;
bool vis[500000];
void dfs(int node){
	vis[node] = 1;
	for (auto ch : adj[node]){
		if (!vis[ch])dfs(ch);
	}

int main(){
	fast
		ll n,m;
	cin >> n >> m;
	while (m--){
		int from, to, w;
		cin >> from >> to;
		from--; to--;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	
	stop();
	return 0;
}