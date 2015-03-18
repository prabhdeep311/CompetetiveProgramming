//
//  Linear_Diophantine.cpp
//  O(log(min(a,b)))
//
//  Created by Prabhdeep Singh Walia on 18/03/15.
//  Copyright (c) 2015 Prabhdeep Singh Walia. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <list>
#include <fstream>
#include <set>
using namespace std;

#define REP(i,n) for (int i = 1; i <= n; i++)
#define in(i) scanf("%d",&i)
#define out(i) printf("%d\n",i)
#define pii pair<int, int>

typedef long long ll;
const ll MOD = 1000000007;
const int maxn=1e+5;
typedef vector<vector<ll> > matrix;

//Extended Euclidean
int gcd(int a, int b, int &x, int &y)
{
    if(a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int t = gcd(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1 ;
	return t ;
}

bool find_solution(int a, int b, int c, int &x, int &y)
{
    int g = gcd(abs(a), abs(b), x, y);
    if(c%g != 0)
        return false;
    x *= c/g;
    y *= c/g;
    if(a < 0) x *= -1;
    if(b < 0) y *= -1;
    return true;
}

int main(int argc, const char * argv[])
{
    int a, b, c;    //exclude case for a = b = 0 (infinite solutions for c = 0 or no solutions for c != 0)
    cin>>a>>b>>c;
    int x, y;
    bool ans = find_solution(a, b, c, x, y);
    if(ans) cout<<x<<" "<<y<<"\n";
    else    cout<<"No Answer\n";
    return 0;
}


