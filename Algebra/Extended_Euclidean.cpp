//
//  Extended_Euclidean.cpp
//  O(log(min(a,b))
//
//  Created by Prabhdeep Singh Walia on 15/03/15.
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

//Using: b%a = b - floor(b/a)*a;
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

int main(int argc, const char * argv[])
{
    int a, b;
    cin>>a>>b;
    int x, y;
    cout<<gcd(a, b, x, y)<<"\n";
    cout<<x<<" "<<y<<"\n";
    return 0;
}


