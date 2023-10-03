#include <bits/stdc++.h>
using namespace std;

const int Max_n = 1e6 + 5;

long long ans;

char s[Max_n];

int n , lst = 1 , tot = 1 , siz[Max_n << 1] , len[Max_n << 1] , link[Max_n << 1];
int ch[Max_n << 1][30] , buk[Max_n] , ord[Max_n << 1];

void insert(int x)
{
	int newpos = ++ tot , p = lst , q , clone;
	len[newpos] = len[lst] + 1 , siz[newpos] = 1 , lst = newpos;
	while(p && !ch[p][x])
		ch[p][x] = newpos , p = link[p];
	if(!p) return link[newpos] = 1 , void();
	q = ch[p][x];
	if(len[q] == len[p] + 1)
		return link[newpos] = q , void();
	clone = ++ tot;
	len[clone] = len[p] + 1 , link[clone] = link[q] , link[q] = link[newpos] = clone;
	for(int i = 0 ; i < 27 ; ++ i)
		ch[clone][i] = ch[q][i];
	while(p && ch[p][x] == q)
		ch[p][x] = clone , p = link[p];
}

int main()
{
	scanf("%s" , s + 1);
	n = strlen(s + 1);
	for(int i = 1 ; i <= n ; ++ i)
		insert(s[i] - 'a');
	for(int i = 1 ; i <= tot ; ++ i)
		buk[len[i]] ++ ;
	for(int i = 1 ; i <= n ; ++ i)
		buk[i] += buk[i - 1];
	for(int i = 1 ; i <= tot ; ++ i)
		ord[buk[len[i]] --] = i;
	for(int i = tot ; i ; -- i)
	{
		int nw = ord[i];
		if(siz[nw] != 1) ans = max(ans , 1ll * siz[nw] * len[nw]);
		siz[link[nw]] += siz[nw];
	}
	printf("%lld\n" , ans);
}
