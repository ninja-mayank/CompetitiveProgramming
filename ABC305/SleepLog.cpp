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

void ninjamayank(){
    ll n;cin >> n;
    vector<ll> v(n);input(v);
    vector<pair<ll, ll>> res;
    vector<ll> suff(n - 1);
    suff[n - 2] = v[n - 1] - v[n - 2];
    for(ll i = n - 3;i >= 0;i--){
        if(i%2 == 0){
            suff[i] = suff[i + 1];
        }else{
            suff[i] = suff[i + 1] + v[i + 1] - v[i];
        }
    }
    vector<ll> starting;
    for(ll i = 0;i < n - 1;i++){
        starting.pb(v[i]);
        res.pb({v[i],v[i + 1]});
    }
    ll q;cin >> q;
    while(q--){
        ll l,r;
        cin >> l >> r;
        ll ans = 0;
        auto it = upper_bound(all(starting),l);
        it--;
        ll i1 = it - starting.begin();
        it = upper_bound(all(starting),r);
        it--;
        ll i2 = it - starting.begin();
        if(i1 == i2){
            if(i1%2 == 1){
                cout << r - l << nline;
            }else{
                cout << 0 << nline;
            }
            continue;
        }
        // cout << l << " " << r << " " << res[i1].sc << " " << res[i2].fr << " " << nline;
        if(i1%2 == 1){
            ans += res[i1].sc - l;
        }
        if(i2%2 == 1){
            ans += r - res[i2].fr;
        }
        ans += suff[i1 + 1] - suff[i2];
        cout << ans << nline;
    }
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
