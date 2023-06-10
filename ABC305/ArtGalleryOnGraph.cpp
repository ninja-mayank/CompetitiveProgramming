#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define input(x) for(auto &a:x)cin>>a
#define print(x) for(auto &a:x){cout<<a<<' ';}cout<<nline
#define ppcl(x) __builtin_popcountll(x)
#define ppc(x) __builtin_popcount(x)
#define all(x) x.begin(), x.end()
#define ll long long int
#define pb push_back
#define nline "\n"
#define INF LLONG_MAX
#define NINF LLONG_MIN
#define pii pair<int,int> 
#define fr first
#define sc second 
using namespace std;
using namespace __gnu_pbds;
#define precision(x) fixed << setprecision(x)
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9 + 7;
const int N = 200001;

vector<vector<ll>> graph(N);

void ninjamayank(){
    ll n,m,k;
    cin >> n >> m >> k;
    for(ll i = 0;i < m;i++){
        ll x,y;
        cin >> x >> y;
        --x;--y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    priority_queue<pair<ll, ll>,vector<pair<ll, ll>>,greater<pair<ll, ll>>> pq;
    vector<ll> dist(n);
    for(ll i = 0;i < k;i++){
        ll x,y;
        cin >> x >> y;
        --x;
        pq.push({-y - 1,x});
        dist[x] = -y - 1;
    }
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        ll d = curr.fr;ll u = curr.sc;
        for(auto &child : graph[u]){
            if(dist[child] > 1 + dist[u]){
                dist[child] = 1 + dist[u];;
                pq.push({dist[child],child});
            }
        }
    }
    // print(dist);
    vector<ll> res;
    for(ll i = 0;i < n;i++){
        if(dist[i] != 0){
            res.pb(i + 1);
        }
    }
    cout << res.size() << nline;
    print(res);
}
int main(){
    // #ifndef ONLINE_JUDGE
    //     //for getting input from input1.txt
    //     freopen("input1.txt", "r", stdin);
    //     //for getting output from output1.txt
    //     freopen("output1.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // remove in problems with online query
    int testcase = 1;
    // cin >> testcase;
    int gtc = 1;
    while(testcase--){
        //cout << "Case #" << gtc << ": ";
        ninjamayank();
        gtc++;
    }
