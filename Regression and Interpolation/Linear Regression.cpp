#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

pair<double, double> least_sqr_regression(const vector<pair<double, double> > &ar){
	// ar = list of {x, y}
	// returns a and b for fitting equation: y = a + bx

	// b = (n*sum(xy)-sum(x)sum(y))/(n*sum(x^2)-sum(x)^2)
	// a = avg(y)-b*(avg(x))

	double sum_of_x = 0.0 ;
	double sum_of_y = 0.0 ;
	double sum_of_x_sqr = 0.0 ;
	double sum_of_xy = 0.0 ;

	for(auto i : ar){
		sum_of_x += i.first ;
		sum_of_y += i.second ;
		sum_of_x_sqr += i.first * i.first ;
		sum_of_xy += i.first * i.second ;
	}

	double n = (double)ar.size() ;
	double b = (n * sum_of_xy - sum_of_x * sum_of_y) / (n * sum_of_x_sqr - sum_of_x * sum_of_x) ;
	double a = (sum_of_y - b * sum_of_x) / n ;

	return make_pair(a, b) ;
}

int main(){

	vector<pair<double, double> > ar ;
	ar.push_back(make_pair(0.0, -1.0)) ;
	ar.push_back(make_pair(2.0, 5.0)) ;
	ar.push_back(make_pair(5.0, 12.0)) ;
	ar.push_back(make_pair(7.0, 20.0)) ;

	pair<double, double> res = least_sqr_regression(ar) ;
	double a = res.first, b = res.second ;
	cout << "y = " << a << " + " << b << "x" ;	//y = -1.13793 + 2.89655x

	return 0;
}