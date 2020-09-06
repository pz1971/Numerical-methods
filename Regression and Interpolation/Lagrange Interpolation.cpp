#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

double lagrange(const vector<pair<double, double> > &ar, const double x){
	// ar = list of {x, f}
	// P_n = sum(f_i * I_i for i in [0 - n])
	// I_i = product((x-x_j)/(x_i-x_j) for j in [0 - n] and j != i)

	double ret = 0.0 ;

	for(int i = 0 ; i < ar.size() ; i++){
		double prod = ar[i].second ;
		for(int j = 0 ; j < ar.size() ; j++){
			if(i != j){
				prod *= (x - ar[j].first)/(ar[i].first-ar[j].first) ;
			}
		}
		ret += prod ;
	}
	return ret ;
}

int main(){

	int n ;
	cin >> n ;	// total data points
	vector<pair<double, double> > ar(n) ;
	for(auto &i : ar)
		cin >> i.first >> i.second ;	// x, y ;
	
	cout << endl ;
	// let's print all the x, y for x in range(25, 100, 5)
	
	for(double x = 25; x <= 100.0 ; x += 5.0){
		cout << x << " " << lagrange(ar, x) << endl ;	
	}

	return 0;
}

/*
9
10 5
15 20
20 18
25 40
40 33
50 54
55 79
60 60
75 78
*/