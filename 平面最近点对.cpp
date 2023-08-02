#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll read()
{
    ll res = 0; char c = getchar(); bool flag = false;
    while(!isdigit(c))
        flag = (c == '-') , c = getchar();
    while(isdigit(c))
        res = res * 10 + (c ^ 48) , c = getchar();
    return !flag ? res : -res;
}

#define MP make_pair
#define fi first
#define se second
#define PII pair<int , int>

const int Max_n = 4e5 + 5;

int n;

struct node
{
    ll x , y;
    node(int a , int b):x(a) , y(b){}
    node(){}
}a[Max_n] , st[Max_n];

bool cmp(node a , node b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

ll dis = 1e18;

ll dist(node a , node b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int tp;

bool cmp2(node a , node b)
{
    return a.y < b.y;
}

ll divide(int l , int r)
{
    ll ret = 1e18;
    if(l == r) return ret;
    if(r == l + 1) return dist(a[l] , a[r]);
    int mid = (l + r) >> 1;
    ret = min(divide(l , mid) , divide(mid + 1 , r));
    tp = 0;
    for(int i = l ; i <= r ; ++ i)
        if((a[i].x - a[mid].x) * (a[i].x - a[mid].x) <= ret) st[ ++ tp] = a[i];

    sort(st + 1 , st + tp + 1 , cmp2);

    for(int i = 1 ; i <= tp ; ++ i)
        for(int j = i + 1 ; j <= tp && (st[j].y - st[i].y) * (st[j].y - st[i].y) <= ret ; ++ j)
            ret = min(ret , dist(st[i] , st[j]));
    return ret;
}

int main()
{
    n = read();
    for(int i = 1 ; i <= n ; ++ i)
    {
        int x = read() , y = read();
        a[i] = node(x , y);
    }
    sort(a + 1 , a + n + 1 , cmp);
    printf("%lld\n" , divide(1 , n));
}//
