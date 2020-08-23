#include <bits/stdc++.h>
#include "numerical.hpp"
#include "bisection.hpp"
#include "false_position.hpp"
#include "newton_raphson.hpp"
#include "secant.hpp"
using   namespace  std ;
using LL  =  long long ;

int main(){

	cout << fixed << showpoint << setprecision(6) ;
	
	vector<double> coeff = {3.0, 2.0} ;
	// coeff = vector<double> {1, 4, 3} ;
	cout << "Coeff: " ;
	for(auto i : coeff)
		cout << i << " " ;
	cout <<  endl ;
	

	cout << endl << "Bisection:" << endl << endl ;
	try{
		cout <<"root = " << bisection(coeff) << endl ;
		cout <<"f(root) = " << func(coeff, bisection(coeff)) << endl ;
	}catch(invalid_bracket_exception &e){
		cout << e.what() << endl;
	}

	cout << endl << "False Position:" << endl << endl ;
	try{
		cout <<"root = " << false_position(coeff) << endl ;
		cout <<"f(root) = " << func(coeff, false_position(coeff)) << endl ;
	}catch(invalid_bracket_exception &e){
		cout << e.what() << endl;
	}
	
	cout << endl << "Secant:" << endl << endl ;
	try{
		cout <<"root = " << secant(coeff) << endl ;
		cout <<"f(root) = " << func(coeff, secant(coeff)) << endl ;
	}catch(invalid_bracket_exception &e){
		cout << e.what() << endl;
	}
	
	cout << endl << "Newton Raphson:" << endl << endl ;
	cout <<"root = " << newton_raphson(coeff) << endl ;
	cout <<"f(root) = " << func(coeff, newton_raphson(coeff)) << endl ;

	coeff = vector<double> {1, 4, 3} ;
	cout << "Coeff: " ;
	for(auto i : coeff)
		cout << i << " " ;
	cout <<  endl ;
	
	cout << endl << "Modified Bisection:" << endl << endl ;
	vector<double> roots = modified_bisection(coeff) ;
	cout << "roots : " ;
	for(auto i : roots){
		cout << i << " " ;
	}	cout << endl ;
	cout << "values: " ;
	for(auto i : roots){
		cout << func(coeff, i) << " " ;
	}	cout << endl ;

	cout << endl << "Modified Newton Raphson:" << endl << endl ;
	roots = modified_newton_raphson(coeff) ;
	cout << "roots : " ;
	for(auto i : roots){
		cout << i << " " ;
	}
	cout << endl ;
	cout << "values: " ;
	for(auto i : roots){
		cout << func(coeff, i) << " " ;
	}
	cout << endl ;

	return 0;
}