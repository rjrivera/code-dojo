#include <iostream>
#include <limits.h>
#include "fib.h"
#include <array>

using namespace std;

void getFib(int N, array<int> * fibArr) {

	//check if the memoized array is in fact large enough for requested fib
	if (N < fibArr.size()) {
		cout << fibArr[N] << endl;
		return;
	}
	cout << "fib Array is too small, resize required" << endl;
	

}
