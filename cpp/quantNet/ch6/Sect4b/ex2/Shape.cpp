#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include "Shape.hpp"
/*
	Release Notes v3-4-2
	Shape class
	Documentation: Level 5 Homework - page 2
	Author: Rob Rivera
	
	Initial draft, no amendments to annotate. 

	private: double m_id;

*/

//distribution / generator are global variables

Shape::Shape() {
	// ======== code block - std::normal_distribution::(constructor)
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::default_random_engine generator (seed);
	
	std:: normal_distribution<double> distribution (1, 1.0);
	// =========
	m_id = distribution(generator);
	
}


Shape::~Shape() {
	std::cout << "shape destructor\n";
}


Shape::Shape(const Shape& source_) {

	m_id = source_.m_id;

}


Shape& Shape::operator= (const Shape& source_) {
	m_id = source_.m_id;
}


		// view methods
std::string Shape::ToString() const {
		return ("Shape ID: " + std::to_string(m_id));
}

bool Shape::operator== (const Shape& source_) const {
	if (source_.m_id == m_id) {
		return true;
	}
	return false;

}

		// modifiers
		// choosing a diameter vice rad method to take advantage of overloading. 
void Shape::ID(double target_) { 
	m_id = target_;
}

double Shape::ID() const{
	return m_id;
}

