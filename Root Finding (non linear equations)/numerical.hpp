#ifndef _NUMERICAL_HPP_
#define _NUMERICAL_HPP_

#include<bits/stdc++.h>
using namespace std ;

const double ZERO = 1e-9 ;
const double DEFAULT_ER = 1e-4;

double func(const vector<double> &coeff, const double x){ // f(x) using horner's method
	// coeff = coefficients of X^n, X^(n-1), X^(n-2) .....x^2, x^1, X^0
	double ret = 0.0 ;
	
	for(auto i : coeff){
		ret = (ret * x) + i ;
	}
	return ret ;
}

double func_prime(const vector<double> &coeff, const double x){	// f'(x)	using horner's method
	// coeff = coefficients of X^n, X^(n-1), X^(n-2) .....x^2, x^1, X^0
	double ret = 0.0 ;
	int mult = coeff.size() - 1 ;

	for(int i = 0 ; i + 1 < (int) coeff.size() ; i++){
		ret = (ret * x) + (coeff[i] * mult--) ;
	}
	return ret ;
}

double largest_possible_root(const vector<double> &coeff){
	// coeff = coefficients of X^n, X^(n-1), X^(n-2) .....x^2, x^1, X^0
	// largest possible root = - a_(n-1) / a_n
	return (int)coeff.size() <= 1 ? 0.0 : -(coeff[1] / coeff[0]) ;
}

pair<double, double> search_bracket(const vector<double> &coeff){
	// coeff = coefficients of X^n, X^(n-1), X^(n-2) .....x^2, x^1, X^0
	// search bracket: |x_max| <= sqrt( (a_(n-1)/a_n)^2 - 2(a_(n-2)/a_n) )
	double ret = 0.0 ;
	
	if((int)coeff.size() == 2)
		ret = (coeff[1] / coeff[0]) ;
	else if((int)coeff.size() > 2)
		ret = sqrt( (coeff[1] / coeff[0])*(coeff[1] / coeff[0]) - 2.0 * (coeff[2] / coeff[0]) ) ;

	if(ret < 0.0)
		ret = -ret ;
	return make_pair(-ret, ret) ;
}

vector<double> synthetic_division(const vector<double> &coeff, const double x){
	// coeff = coefficients of X^n, X^(n-1), X^(n-2) .....x^2, x^1, X^0
	vector<double> ret ;
	double cur = 0.0 ;
	for(int i = 0 ; i + 1 < (int)coeff.size() ; i++){
		cur = cur * x + coeff[i] ;
		ret.push_back(cur) ;
	}
	return ret ;
}

#endif