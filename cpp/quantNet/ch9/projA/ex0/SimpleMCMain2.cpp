/*
requires PayOff1.cpp, Random1.cpp, SimpleMC.cpp,
*/

#include"SimpleMC.h"
#include<iostream>
#include </home/rob/Downloads/boost_1_63_0/boost/tuple/tuple.hpp>
#include </home/rob/Downloads/boost_1_63_0/boost/tuple/tuple_io.hpp>
#include <vector>

using namespace std;

int main()
{
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;
	//provide batch cases here for testing.
	typedef boost::tuple<double, double, double, double, double, unsigned long> batch;
	batch one {0.25, 65, 60, 0.30, 0.08, 2};
	batch two {1, 100, 100, 0.2, 0.00, 2};
	batch three {1, 10, 5, 0.50, 0.12, 2};
	batch four {30, 100, 100, 0.30, 0.08, 2};

	vector<batch> batches;
	batches.push_back(one);
	batches.push_back(two);
	batches.push_back(three);
	batches.push_back(four);

	vector<pair<double, double>> testPrices;
	testPrices.push_back(make_pair(2.13293, 5.84584));
	testPrices.push_back(make_pair(7.96632, 7.96632));
	testPrices.push_back(make_pair(0.204121, 4.0733));
	testPrices.push_back(make_pair(92.1749, 1.24651));

	for (int i = 0; i < batches.size(); i++) 	{
		PayOff callPayOff( boost::get<1>(batches[i]), PayOff::call);
		PayOff putPayOff(boost::get<1>(batches[i]), PayOff::put);

		double resultCall = SimpleMonteCarlo2(callPayOff,
				 boost::get<0>(batches[i]),
				 boost::get<2>(batches[i]),
				 boost::get<3>(batches[i]),
				 boost::get<4>(batches[i]),
				 boost::get<5>(batches[i]));

		double resultPut = SimpleMonteCarlo2(putPayOff,
				 boost::get<0>(batches[i]),
				 boost::get<2>(batches[i]),
				 boost::get<3>(batches[i]),
				 boost::get<4>(batches[i]),
				 boost::get<5>(batches[i]));

		cout << "BATCH " << i << endl 
				<<  "the calculated prices are " << resultCall
			<< " for the call and"
				<< resultPut
				<< " for the put\n";


		cout <<  "the test prices are " << testPrices[i].first
			<< " for the call and"
				<< testPrices[i].second
				<< " for the put\n";

	}

	return 0;
}
