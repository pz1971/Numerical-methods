#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

vector<vector<double> > get_divided_difference_table(const vector<double> X_ar, const vector<double> &Y_ar){
	// X_ar = list of x	; 	Y_ar = list of corresponding y
	// returns a 2d vector representing Newton's divided difference table
	vector<vector<double> > ret{X_ar, Y_ar} ;
	int iteration = 0 ;

	while(ret.back().size() > 1){
		iteration++ ;

		const auto &y = ret.back() ;
		vector<double> vec ;
		int x_pos = 0 ;

		for(int i = 1 ; i < y.size() ; i++){
			vec.push_back((y[i-1] - y[i]) / (X_ar[x_pos] - X_ar[x_pos + iteration])) ;
			x_pos++ ;
		}
		ret.push_back(vec) ;
	}

	return ret ;
}

void print_divided_difference_table(const vector<double> X_ar, const vector<double> &Y_ar){
	// X_ar = list of x	; 	Y_ar = list of corresponding y
	vector<vector<double> > table = get_divided_difference_table(X_ar, Y_ar) ;
	
	cout << "x\t" ;
	for(int i = 0 ; i < X_ar.size() ; i++)
		cout << "d"<< i << "fx\t" ;
	cout << endl ;
	
	for(int i = 0 ; i < X_ar.size() ; i++){
		for(const auto &col: table){
			if(i < col.size())
				cout << col[i] << "\t" ;
		}
		cout << endl ;
	}
}

double Px(const vector<vector<double> > &table, const double x){
	// X_ar = list of x	; 	Y_ar = list of corresponding y
	// return f(x)

	const vector<double> &X_ar = table.front() ;
	vector<double> ar{1.0} ;	// 1, (x-x0), (x-x0)(x-x1), (x-x0)(x-x1)(x-x2), ... ...
	for(int i = 0 ; i + 1 < X_ar.size() ; i++){
		ar.push_back(ar.back() * (x - X_ar[i])) ;
	}

	double ans = 0.0 ;
	for(int i = 0 ; i < ar.size() ; i++){
		ans += table[i+1].front() * ar[i] ;
	}
	return ans ;
}

int main(){

	cout << fixed << showpoint << setprecision(2) ;
	
	int n ;	// no. of data points
	cin >> n ;
	vector<double> X(n), Y(n) ;
	for(int i = 0 ; i < n ; i++){
		cin >> X[i] >> Y[i] ;
	}

	print_divided_difference_table(X, Y) ;
	auto table = get_divided_difference_table(X, Y) ;
	
	cout << endl << Px(table, 6.0) << endl ; // 252

	return 0;
}

/*
5
5 150
7 392
11 1452
13 2366
21 9702
*/