#ifndef _BISECTION_HPP_
#define _BISECTION_HPP_

#include "numerical.hpp"
#include "invalid_bracket_exception.hpp"

#include<bits/stdc++.h>
using namespace std ;

double bisection(const vector<double> &coeff, double a, double b, const double Er = DEFAULT_ER){
	if(func(coeff, a) * func(coeff, b) > ZERO){
		throw invalid_bracket_exception() ;
	}

	double hi = a, lo = b, mid ;
	do{
		mid = (lo + hi) / 2.0 ;

		if(func(coeff, mid) == ZERO)
			break ;
		else if(func(coeff, lo) * func(coeff, mid) < ZERO)
			hi = mid ;
		else	
			lo = mid ;
	} while(fabs((hi - lo)/hi) > Er) ;

	return mid ;
}

double bisection(const vector<double> &coeff, const double Er = DEFAULT_ER){
	pair<double, double> BRACKET = search_bracket(coeff) ;
	return bisection(coeff, BRACKET.first, BRACKET.second, Er) ;
}

// for all roots
vector<double> modified_bisection(const vector<double> &coeff, double lower, double upper, const double dell, const double Er = DEFAULT_ER){
	vector<double> ret ;
	for(double x = lower ; x < upper ; x += dell){
		if(func(coeff, x) * func(coeff, x + dell) > ZERO)
			continue ;
		ret.push_back(bisection(coeff, x, x + dell, Er)) ;
	}
	return ret ;
}

vector<double> modified_bisection(const vector<double> &coeff, const double dell = 0.1, const double Er = DEFAULT_ER){
	pair<double, double> BRACKET = search_bracket(coeff) ;
	return modified_bisection(coeff, BRACKET.first, BRACKET.second, dell, Er) ;
}

#endif