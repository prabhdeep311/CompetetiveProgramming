//
//  Degree_Divider_Factorial.cpp
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

int degreeDiv(int n, int k)
{
    int res = 0;
	while(n)
    {
		n /= k;
		res += n;
	}
	return res;
}

int main(int argc, const char * argv[])
{
    int n, k;
    cin>>n>>k;
    cout<<degreeDiv(n, k)<<"\n";
    return 0;
}

