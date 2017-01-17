#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp>
#include <vector>
#include <iostream>

//using namespace std;


int main() {

	using namespace boost::math;
	double myScalar = 0.5;
	exponential_distribution<> myNormal(myScalar); //default type double
	
	std::cout << "Mean: " << mean(myNormal) << ", standard deviation: " << standard_deviation(myNormal) << std::endl;

	// distributional properties
	double x = 10.25;

	std::cout << "pdf: " << pdf(myNormal, x) << std::endl;
	std::cout << "cdf: " << cdf(myNormal, x) << std::endl;
	
	// Choose another data type and N(0,1) variate
	exponential_distribution<float> myNormal2;
	std::cout << "pdf: " << pdf(myNormal2, x) << std::endl;
	std::cout << "cdf: " << cdf(myNormal2, x) << std::endl;

	// Choose precision
	std::cout.precision(10); //Numbr of values behind the comma
	
	// Other properties
	std::cout << "\n***	exponential disribution: \n";
	std::cout << "\nmean: " << mean(myNormal) << std::endl;
	std::cout << "variance: " << variance(myNormal) << std::endl;
	std::cout << "median: " << median(myNormal) << std::endl;
	std::cout << "mode: " << mode(myNormal) << std::endl;
	std::cout << "kurtosis excess: " << kurtosis_excess(myNormal) << std::endl;
	std::cout << "kurtosis:  " << kurtosis(myNormal) << std::endl;
	std::cout << "characteristic function:  " << chf(myNormal, x) << std::endl;
	std::cout << "hazard:  " << hazard(myNormal, x) << std::endl;


	// poisson distribution
	std::cout << "***POISSON DISTRIBUTION***\n";
	double myMean = 3.0;
	std::cout << "mean: " << myMean << std::endl;

	poisson_distribution<double> myGamma(myMean);

	double val = 13.0;
	std::cout << std::endl << "pdf: " << pdf(myGamma, val) << std::endl;
	std::cout << "cdf: " << cdf(myGamma, val) << std::endl;

	std::vector<double> pdfList;
	std::vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30; //number of subdivisions.

	val = 0.0; 
	double h = (end - start) / double(N);
	
	for (long j = 1; j <= N; j++) {

		pdfList.push_back(pdf(myGamma,val));
		cdfList.push_back(pdf(myGamma,val));

		val += h;
	}
	
	for (long j = 0; j < pdfList.size(); j++) std::cout << pdfList[j] << ", " ;

	std::cout << "***" << std::endl;

	for (long j =0 ; j < cdfList.size(); j++) std::cout << cdfList[j] << ", ";

	

	return 0 ;
}
