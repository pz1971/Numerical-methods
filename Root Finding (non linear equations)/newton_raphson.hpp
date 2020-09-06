#ifndef _NEWTON_RAPHSON_HPP_
#define _NEWTON_RAPHSON_HPP_

#include "numerical.hpp"

#include<bits/stdc++.h>
using namespace std ;

double newton_raphson(const vector<double> &coeff, const double Er = DEFAULT_ER){
	// x_(n+1) = x_n - f(x_n)/f'(x_n)

	double x, x2 = largest_possible_root(coeff);
	do{
		x = x2 ;
		x2 = x - func(coeff, x) / func_prime(coeff, x) ;
	} while(fabs((x2-x)/x2) > Er) ;
	return x2 ;
}

// for all roots
vector<double> modified_newton_raphson(const vector<double> &coeff, const double Er = DEFAULT_ER){
	vector<double> ar = coeff ;
	vector<double> ret ;
	while(ar.size() > 1){
		double x = newton_raphson(ar, Er) ;
		ret.push_back(x) ;
		ar = synthetic_division(ar, x) ;
	}
	return ret ;
}

#endif