#include <iostream>
#include <chrono>
#include <random>
#include "Point.hpp"
#include "Line.hpp"
#include "Array.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "OutOfBoundsException.hpp"
#include "PointArray.hpp"
#include "Stack.hpp"
#include </home/rob/Downloads/boost_1_63_0/boost/tuple/tuple.hpp>
#include </home/rob/Downloads/boost_1_63_0/boost/tuple/tuple_io.hpp>
#include <boost/shared_ptr.hpp>


using namespace std;

/* an attempt to use generics for any sized tuple, left as comments for consideration 
 *
template <class T, std::size_t N>
struct tuplePrinter {
	static void print(const T& item) {
		tuplePrinter<T, N-1>::print(item);
		cout << boost::get<N-1>(item) << ", " << endl;
	}
};

template<class T>
struct tuplePrinter<T, 1>{
	static void print(const T& item){

		cout << boost::get<0>(item);
	}
};

template<class... Args>
void print(const boost::tuple<Args>& t){

	cout << "(";
	tuplePrinter<decltype(t), sizeof...(Args)>::print(t);
	cout << ")" << endl;

}
*/
//typedef defining Person.
typedef boost::tuple<string, int, int> Person;

//specific print function for the Person typedef
static void print(Person& item) {
	cout << "name: " << boost::get<0>(item)<< endl;
	cout << "age: " << boost::get<1>(item)<< endl;
	cout << "height: " << boost::get<2>(item)<< endl;
}

int main() {

	Person rob{"Rob", 28, 67};
	Person johnny{"Johnny", 36, 77};
	Person pat{"Patrick", 33, 74};
	print(rob);
	print(johnny);
	print(pat);


	//Happy Birthday patrick!
	boost::get<1>(pat)+=1;
	print(pat);
	
	return 0 ;
}
