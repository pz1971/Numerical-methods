#ifndef _SECANT_HPP_
#define _SECANT_HPP_

#include "numerical.hpp"
#include "invalid_bracket_exception.hpp"

#include<bits/stdc++.h>
using namespace std ;

// secant method is almost same as false position method

double secant(const vector<double> &coeff, double a, double b, const double Er = DEFAULT_ER){
	// x_(n+1) = x_n - (f(x_n)(x_n-x_(n-1)))/(f(x_n)-f(x_(n-1)))
	
	if(func(coeff, a) * func(coeff, b) > ZERO){
		throw invalid_bracket_exception() ;
	}
	
	double x = a ;
	do{
		x = a - ( ( func(coeff, a) * (b-a) ) / ( func(coeff, b) - func(coeff, a) ) ) ;
		if(func(coeff, x) * func(coeff, a) < ZERO)
			b = x ;
		else 
			a = x ;
	} while(fabs((b-a) / b) > Er) ;
	return x ;
}

double secant(const vector<double> &coeff, const double Er = DEFAULT_ER){
	pair<double, double> BRACKET = search_bracket(coeff) ;	
	return false_position(coeff, BRACKET.first, BRACKET.second, Er) ;
}

#endif