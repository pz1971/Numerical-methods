#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

double determinant(const vector<vector<double> > &mat){
	// returns the determinant of a 3x3 matrix
	double ret = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]) ;
	ret -= mat[0][1] * (mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2]) ;
	ret += mat[0][2] * (mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1]) ;
	return ret ;
}

vector<double> get_polynomial(const vector<double> &X, const vector<double> &Y){
	// y = a + bx + cx^2
	// returns coefficients of x^0, x^1 and x^2 as a vector. {a, b, c}
	double sum_x = 0.0, sum_y = 0.0 ;
	double sum_x_sqr = 0.0, sum_x_cube = 0.0 ;
	double sum_x_pow4 = 0.0 ;
	double sum_yx = 0.0, sum_y_xsqr = 0.0 ;

	for(int i = 0 ; i < X.size() ; i++){
		sum_x += X[i] ;
		sum_y += Y[i] ;
		sum_x_sqr += X[i] * X[i] ;
		sum_x_cube += X[i] * X[i] * X[i] ;
		sum_x_pow4 += X[i] * X[i] * X[i] * X[i] ;
		sum_yx += Y[i] * X[i] ;
		sum_y_xsqr += Y[i] * X[i] * X[i] ;
	}
	
	vector<vector<double> > mat {
		{(double)X.size(), sum_x, sum_x_sqr},
		{sum_x, sum_x_sqr, sum_x_cube},
		{sum_x_sqr, sum_x_cube, sum_x_pow4}
	} ;
	double D = determinant(mat) ;

	vector<vector<double> > mat2 = mat ;
	mat2[0][0] = sum_y ;
	mat2[1][0] = sum_yx ;
	mat2[2][0] = sum_y_xsqr ;
	double Da = determinant(mat2) ;

	mat2 = mat ;
	mat2[0][1] = sum_y ;
	mat2[1][1] = sum_yx ;
	mat2[2][1] = sum_y_xsqr ;
	double Db = determinant(mat2) ;

	mat2 = mat ;
	mat2[0][2] = sum_y ;
	mat2[1][2] = sum_yx ;
	mat2[2][2] = sum_y_xsqr ;
	double Dc = determinant(mat2) ;

	return vector<double> {(Da/D), (Db/D), (Dc/D)} ;
}

int main(){

	int n ;	// number of data points
	cin >> n ;
	vector<double> X(n), Y(n) ;
	for(int i = 0 ; i < n ; i++){
		cin >> X[i] >> Y[i];
	}

	auto p = get_polynomial(X, Y) ;
	cout << "The 2nd order regression polynomial is: " ;
	cout << "y = " << p[0] << " + " << p[1] << "x + " << p[2] << "x^2" << endl ;

	return 0;
}

/*
4
1 6
2 11
3 18
4 27
*/