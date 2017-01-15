#include <string>
#include <iostream>
#include <cctype>

using namespace std;

int atoi(string target){
	int numChars = target.length();
	bool neg = false;
	int index = 0;
	int ans = 0;
	if (target.at(0) == '-') {
		neg =true;
		index++;
	}
	while (index < numChars) {
		//sanitation
		if (!isdigit(target.at(index)))  {
			cout << "invalid char found at index: " << index << endl;
			return -1;
		}
		ans *= 10;
		ans += (int)(target.at(index)) - 48; // the ascii offset
		index++;
	}


	if (neg) return ans*-1;
	return ans; 
}

int main( int argc, char** argv ) {
	string one = "1";
	string swiftyfive = "55";
	
	int ans = atoi(one);
	cout << "\"1\" yields " << ans << endl; 
	ans = atoi(swiftyfive);
	cout << "\"55\" yields " << ans << endl; 

	return 0;
}
