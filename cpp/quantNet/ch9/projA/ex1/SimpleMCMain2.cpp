/*
requires PayOff1.cpp, Random1.cpp, SimpleMC.cpp,
*/

#include"SimpleMC.h"
#include<iostream>
#include </home/rob/Downloads/boost_1_63_0/boost/tuple/tuple.hpp>
#include </home/rob/Downloads/boost_1_63_0/boost/tuple/tuple_io.hpp>
#include <vector>
#include <math.h>
#include <boost/math/distributions/normal.hpp>

/*
 *After getting my feet wet with some prior work, simplifying this
 *iteration of the project and using the boost::normal in lieu of the other class I used in ex0. 
 */

using namespace std;


double SimpleMCCall(	double b,
			double Expiry,
			double Strike,
			double Spot,
			double Vol,
			double r,
			unsigned long NumberOfPaths)
{
	// C = Se^(b-r)^T*(N(d1))-(Ke^-rT)*N(d2)
	//Ke^-rT
	double kurt = Strike * exp(-1*r*Expiry);
	//Se^((b-r)*T)
	double sert = Spot*(exp((b-r)*Expiry));
	//d2
	double d2 =( (log(Spot/Strike)) + (b-(pow(Vol,2)/2))*Expiry)/(Vol*sqrt(Expiry));
	double myScalar = Vol;
	boost::math::normal_distribution<> myNormal(myScalar); //default type double
	double Nd2 = cdf(myNormal, d2);

	double d1 =( (log(Spot/Strike)) + (b+(pow(Vol,2)/2))*Expiry)/(Vol*sqrt(Expiry));
	double Nd1 = cdf(myNormal, d1);

	return sert*Nd1 - kurt*Nd2;
}


double SimpleMCPut(	double b,
			double Expiry,
			double Strike,
			double Spot,
			double Vol,
			double r,
			unsigned long NumberOfPaths)
{
	// P = (Ke^-rT)*N(-d2)-Se^((b-r)*T)*N(-d1)
	//Ke^-rT
	double kurt = Strike * exp(-1*r*Expiry);
	//Se^((b-r)*T)
	double sert = Spot*(exp((b-r)*Expiry));
	//d2
	double d2 =( (log(Spot/Strike)) + (b-(pow(Vol,2)/2))*Expiry)/(Vol*sqrt(Expiry));
	double myScalar = Vol;
	boost::math::normal_distribution<> myNormal(myScalar); //default type double
	double Nd2 = cdf(myNormal, -d2);

	double d1 =( (log(Spot/Strike)) + (b+(pow(Vol,2)/2))*Expiry)/(Vol*sqrt(Expiry));
	double Nd1 = cdf(myNormal, -d1);

	return kurt*Nd2 - sert*Nd1;
}



double putParity(double C, double Strike, 
			double r, double Expiry, double Spot){
	double kurt = Strike * exp(-1*r*Expiry);
	return C + kurt - Spot;


}

// Encapsulate all data in one place
struct OptionData{
	double Expiry;
	double Strike;
	double Vol;
	double r;
	OptionData(double T, double k, double vol_, double r_):Strike(k), 
		Expiry(T), r(r_), Vol(vol_){}
};

double SimpleMCCall(OptionData data, double Spot) 
{
	double b = data.r;
	// C = Se^(b-r)^T*(N(d1))-(Ke^-rT)*N(d2)
	//Ke^-rT
	double kurt = data.Strike * exp(-1*data.r*data.Expiry);
	//Se^((b-r)*T)
	double sert = Spot*(exp((b-data.r)*data.Expiry));
	//d2
	double d2 =( (log(Spot/data.Strike)) + (b-(pow(data.Vol,2)/2))*data.Expiry)/(data.Vol*sqrt(data.Expiry));
	double myScalar = data.Vol;
	boost::math::normal_distribution<> myNormal(myScalar); //default type double
	double Nd2 = cdf(myNormal, d2);

	double d1 =( (log(Spot/data.Strike)) + (b+(pow(data.Vol,2)/2))*data.Expiry)/(data.Vol*sqrt(data.Expiry));
	double Nd1 = cdf(myNormal, d1);

	return sert*Nd1 - kurt*Nd2;
}

double SimpleMCPut(OptionData data, double Spot) 
{
	double b = data.r;
	// P = (Ke^-rT)*N(-d2)-Se^((b-r)*T)*N(-d1)
	//Ke^-rT
	double kurt = data.Strike * exp(-1*data.r*data.Expiry);
	//Se^((b-r)*T)
	double sert = Spot*(exp((b-data.r)*data.Expiry));
	//d2
	double d2 =( (log(Spot/data.Strike)) + (b-(pow(data.Vol,2)/2))*data.Expiry)/(data.Vol*sqrt(data.Expiry));
	double myScalar = data.Vol;
	boost::math::normal_distribution<> myNormal(myScalar); //default type double
	double Nd2 = cdf(myNormal, -d2);

	double d1 =( (log(Spot/data.Strike)) + (b+(pow(data.Vol,2)/2))*data.Expiry)/(data.Vol*sqrt(data.Expiry));
	double Nd1 = cdf(myNormal, -d1);

	return kurt*Nd2-sert*Nd1;
}

double putParity(double C, OptionData d, double Spot){
	double kurt = d.Strike * exp(-1*d.r*d.Expiry);
	return C + kurt - Spot;


}

//formula for Black-Scholes PDES
//-dC/dt + rSpotC/dSpot + 0.5VarianceSpot^2*d^2C/dSpot^2 = rC = 0
double finiteCall(double Spot, double t) {
	double ans = 0;
	double dt = 0.1;

	


	return ans;
}

int main()
{
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;
	//provide batch cases here for testing.
	/*retaining for posterity's sake (used tuples for part a/b
	typedef boost::tuple<double, double, double, double, double, unsigned long> batch;
	batch one {0.25, 65, 60, 0.30, 0.08, 2};
	batch two {1, 100, 100, 0.2, 0.00, 2};
	batch three {1, 10, 5, 0.50, 0.12, 2};
	batch four {30, 100, 100, 0.30, 0.08, 2};
	//if you wish to use tuples (as I did for parts a/b)
	vector<batch> batches;
	batches.push_back(one);
	batches.push_back(two);
	batches.push_back(three);
	batches.push_back(four);
	*/
	OptionData one(0.25, 65.0, 0.30, 0.08);
	OptionData two(1.0, 100.0, 0.2, 0.00);
	OptionData three(1.0, 100.0, 0.2, 0.00);
	/*double Expiry;
	double Strike;
	double Vol;
	double r;*/
	OptionData four(1.5, 120.0, 0.4, 0.04);
	vector<OptionData> batches;
	batches.push_back(one);
	batches.push_back(two);
	batches.push_back(three);
	batches.push_back(four);

	vector<double> spots;
	spots.push_back(60);
	spots.push_back(100);
	spots.push_back(5);
	spots.push_back(100);

	vector<pair<double, double>> testPrices;
	testPrices.push_back(make_pair(2.13293, 5.84584));
	testPrices.push_back(make_pair(7.96632, 7.96632));
	testPrices.push_back(make_pair(0.204121, 4.0733));
	testPrices.push_back(make_pair(92.1749, 1.24651));

	//for part d, only using batch two;
	pair<double, double> range(make_pair(10,50));
	vector<double> outputCall;
	vector<double> outputPut;
	for (int i = 0; i < batches.size(); i++) 	{
/* retained for posterity's sake. 
		double resultCall = SimpleMCCall(boost::get<4>(batches[i]),
				 boost::get<0>(batches[i]),
				 boost::get<1>(batches[i]),
				 boost::get<2>(batches[i]),
				 boost::get<3>(batches[i]),
				 boost::get<4>(batches[i]),
				 boost::get<5>(batches[i]));

		double resultPut = SimpleMCPut(boost::get<4>(batches[i]),
				 boost::get<0>(batches[i]),
				 boost::get<1>(batches[i]),
				 boost::get<2>(batches[i]),
				 boost::get<3>(batches[i]),
				 boost::get<4>(batches[i]),
				 boost::get<5>(batches[i]));
*/
		double resultCall = SimpleMCCall(batches[i], spots[i]);
		double resultPut = SimpleMCPut(batches[i], spots[i]);
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

	cout << "Rerunning tests using put-call parity relationship" << endl;
/*
	for (int i = 0; i < batches.size(); i++) 	{

		double resultCall = SimpleMCCall(boost::get<4>(batches[i]),
				 boost::get<0>(batches[i]),
				 boost::get<1>(batches[i]),
				 boost::get<2>(batches[i]),
				 boost::get<3>(batches[i]),
				 boost::get<4>(batches[i]),
				 boost::get<5>(batches[i]));



		double resultCall = SimpleMCCall(batches[i], spots[i]);
		double resultPut = putParity(resultCall,
					batches[i], spots[i]);

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

	for (int i = range.first; i < range.second; i++) {
		double resultCall = SimpleMCCall(batches[1], (double)i);
		double resultPut = SimpleMCPut(batches[1], (double)i);
		outputCall.push_back(resultCall);
		outputPut.push_back(resultPut);
		cout << "BATCH 1 @ Spot - " << i <<  endl 
		<<  "the calculated prices are " << resultCall
			<< " for the call and"	<< resultPut
				<< " for the put\n";
	}
	
	//varying for expiry.
	//redefine range
	range = make_pair(0.25, 3.0);
	vector<double> outputCallExp;
	vector<double> outputPutExp;
	for (double i = range.first; i < range.second; i+=0.25) {
		batches[1].Expiry = i;
		double resultCall = SimpleMCCall(batches[1], 100);
		double resultPut = SimpleMCPut(batches[1], 100);
		outputCallExp.push_back(resultCall);
		outputPutExp.push_back(resultPut);
		cout << "BATCH 1 @ Expiry - " << i <<  endl 
		<<  "the calculated prices are " << resultCall
			<< " for the call and"	<< resultPut
				<< " for the put\n";
	}
	 
	//varying for volitility.
	//redefine range
	range = make_pair(0.1, 0.9);
	vector<double> outputCallVol;
	vector<double> outputPutVol;
	for (double i = range.first; i < range.second; i+=0.05) {
		batches[1].Vol = i;
		double resultCall = SimpleMCCall(batches[1], 100);
		double resultPut = SimpleMCPut(batches[1], 100);
		outputCallVol.push_back(resultCall);
		outputPutVol.push_back(resultPut);
		cout << "BATCH 1 @ Vol - " << i <<  endl 
		<<  "the calculated prices are " << resultCall
			<< " for the call and"	<< resultPut
				<< " for the put\n";
	}
	
*/
	return 0;
}
