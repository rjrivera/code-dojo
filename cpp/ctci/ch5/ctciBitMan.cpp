#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * You are given two 32-bit numbers, N and M, and two bit positions, i and j. 
 * Write a method to set all bits between i and j in N equal to M.
 * input: N = 10000000000, M = 10101, i = 2, j = 6
 * Output: N = 10001010100
 *
 * Right off the bat, this presumes that j-i is a 32-bit address space.
 * simplfying to simply an 'i' input. During interview I would clarify wha
 * they want.
 *
 */

void addPowTwo(int& N, int M, int i) {
	M = M << i; //performs the cheap pow^i operation.
	cout << M << endl;
	N += M;
	cout << N << endl;	
}

/* Given a number that is passed in as a string, print the binary rep. if the number annot be represented accurately in binary, print "ERROR"
 * personally - I am skipping this problem because it just seems...redundent?
 * The main issue I have is once I have a representation in binary translated...
 * the compiler converts it to an int representation upon assignment.
 *
 * Silver lining - the set-up for parsing a string was relatively seamless for me. so huzzah there. 
 * [x] eh, I slept over it, concluded I was being a whiny bitch. 
 * finished the implementation. 
 */


void stringToBin(string num){
	bool neg = false;
	bool dot = false;
	int magnitude = 0;
	int decMag = 0; //used to track the magnitued POST decimal
	int decTemp = 0;
	int binTemp = 0;
	//read in sstring information for simple processing
	char ss[num.length()] = { };
	for (int i = 0; i < num.length(); i++) {
		ss[i] = num.at(i);
	}

	//begin processing. 
	for (int i = 0; i < num.length(); i++) {
		if (i >0 && ss[i] == '-')  {
			cout << "ERROR\n";
			return;
		}
		if (ss[i] == '.' && dot) {
			cout << "ERROR\n";
			return;
		}
		//proceed to process. 
		if (ss[i] == '-') {
			neg = true;
			continue;
		}
		if (ss[i] == '.') {
			dot = true;   
			continue;
		}
		if (ss[i] <'0' || ss[i] > '9') {
			cout << "ERROR\n" << endl;
			return;
		}
		if (dot)  {
			decMag *= 10;
			decTemp = (char)ss[i];	
			decMag += (int)(decTemp - '0');
		}
		else {
			magnitude *= 10;
			decTemp = (char)ss[i];
			magnitude += (int)(decTemp - '0');
		}
	}

	cout << "mag = " << magnitude << 
		"  -  decMag = " << decMag << endl;
	// convert from int magnitudes to binary. 
	int curBit = 0b01000000000000000000000000000000;
	if (neg) cout << '-'; 
	while (curBit > 0) {
		if (magnitude >= curBit) {
			cout << "1";
			magnitude -= curBit;
		}
		else cout << "0";
		curBit >>= 1;
	}
	 
	curBit =  0b01000000000000000000000000000000;
	if (dot)  {
		cout << '.';
		bool firstOneEnc = false;
		while (curBit > 0) {
			if (decMag >= curBit) {
				cout << "1";
				decMag -= curBit;
				firstOneEnc = true;
			}
			else if (firstOneEnc) cout << "0";
			curBit >>= 1;
		}
	

	}
	cout << endl;

}


/*
 * Given an integer, print the next smallest and next largest number that have
 * the same number of 1 bits in their binary representation.
 * [x] implemented nextSmallest
 * [ ] leaving nextBiggest for now.
 */
//so this sounds fun - more of a puzzle really. well the next smallest 
//is just another way of saying the biggest number below our cur.
//vice versa for next biggest. The other metric is the number of '1's
//
//I suppose for the next smallest, I find the lowest '1' bit, toggle to zero,
//then from that index down to zero (to the right that is), toggle the first '0' i encounter, then reverse the process. 

void printNextBigSmall(int num){

	int curBit = 0b00000000000000000000000000000001;
	int index = 1;
	int mostSigBit = 0;
	int zeroIndex = -1;
	//find greatest One index
	while (curBit <= num) {
 		if ((num&curBit) == curBit)  {
			mostSigBit = index;
		}
		curBit <<=1;
		index++;
	}
	cout << "mostSigBit => " << mostSigBit << endl;
	//find greatest zero index smaller than greatest one index
	curBit = 1;
	curBit <<= (mostSigBit - 1);
	
	index = mostSigBit;
	while(curBit >0) {
		//if a '0' is present at our focused bit. 
		if ((num&curBit) == 0) {
			zeroIndex = index;
			break;
		}
		curBit >>= 1;
		index--;
	}
		

	//apparenlty bitshifts are better than using the pow function lol. 
	int nSmall = num;
	int sub = 1;
	int add = 1;
	sub <<= mostSigBit - 1;
	add <<= zeroIndex-1;
	cout << mostSigBit << endl;
	cout << zeroIndex << endl;
	if (zeroIndex == -1) cout << "impossible, no zeros right of mostsig 1"<< endl; 
	nSmall = num - sub + add;
	cout << "num => " << num << endl;
	cout << "   next Smallest => " << nSmall << endl;
}

/* explain what the following code does:
 *
 * so firstly - the final operator is an equivalancy check.
 * The expected value is either a true or false, or in this case,
 * a 1 or 0 where 1 == true and 0 == false;
 *
 * Heuristically I wish to say that it seems relevant to a two-s 
 * compliment operation of some sort, but lets give it a look.
 *
 * given: 0100
 * you subtract 1 and are left with 0011
 *
 * now a logical AND operator will return a new int, which compares to zero
 *
 * 0100 & 0011 => 0 which in turn yields a true for our final output.
 *
 * given 0101, you get 0100
 *
 * 0101&0100 => 0100 => false (4 != 0)
 *
 * As to what it pragmatically provides for us, I think it tests if 
 * a value is a power of 2.
 *
 * [x] tested, and confirmed my observations and suspicions. SHAQ ATTACK
 */
bool isPowTwo(int n) {
	return ((n & (n-1)) == 0);
}

/*
 * Write a function to determine the number of bits required to convert
 * integer A to integer B.
 * I: 31, 14
 * O: 2
 *
 * ok lets take a look. 
 * it sounds rather easy honestly, do a XOR to determine the deltas 
 * on a bit level and the shift right counting the presence of a 
 * '1' on the least sig bit, tracking it.
 * 
 * [x] checked against init case, seems good enough for now.
 * hate my lack of thorough testing? don't worry, I'm giving more
 * thorough checks off the record. 
 */

int diffBits(int a, int b)  {
	int index = 0;
	int temp = (a^b);
	while (temp > 0) {
		if (temp%2 == 1) index++;
		temp >>= 1; 
	}
	return index;

}

/*
 * write a program to swap odd and even bits in an integer with 
 * as few OPS as possible
 *
 * let's look at some cases to soak it in:
 *
 * 0101 => 1010  ,  5 => 6
 * 1111 => 1111  ,  15 => 15
 * 1100 => 1100  ,  12 => 12
 *
 * so off the cuff, a change only occurs when a delta is present
 * in neighboring bits, and an ordering must be considered, easiest to iterate
 * right to left.
 *
 * initial thoughts indicate the use of a XOR operator and a bit-mask
 * scheme to track the 'active bits' for comparison.
 * if (activebit^activebit<<1) == 1, perform an operatioal swap,
 * else nop
 * active <<= 2 ; ///I think i just did it off the top of my head lol. 
 *
 *
 */

void swapBits(int& n) {
	int activeBit = 1;
	//signed 32-bit ints (YAY LACK OF PORTABILITY).
	while (activeBit > 0){
		if (((activeBit&n) ^ ((activeBit<<1)&n))) {
			if ((activeBit&n)) { 
				n += (activeBit<<1);
				n -= activeBit;
			}
			else {
				n += activeBit;
				n -= (activeBit<<1);
			}
				
		}
		activeBit <<= 2;
	}
	return;

}

int main( int argc, char** argv ) {
	// 5.1 simple test ========
	cout << " pingy ping again \n";
	int x = 0b10000000000;
	cout << x << endl;
	int y = 0b10101;
	addPowTwo(x, y, 2);
	// ==============
	
	stringToBin("3.14");
	
	// ==============
	printNextBigSmall(16);
	

	//=======5.4
	for (int i = 0; i < 128; i++) {
		if (isPowTwo(i)) cout << i << " is a power of two\n";
		else cout << i << " is NOT a power of two\n"; 
	}
	//=======
	//
	//======5.5
	cout << "expected bit diff in 31 & 14 => 2\n";
	cout << diffBits(31, 14) << endl;
	// 5.6 ==========
	int count = 0;
	for (int i = 0; i < 10; i++) {
		count = i;
		cout << "original num: " << count << endl;
		swapBits(count);		
		cout << "swaped bits => " << count << endl;
	}
	return 0;
}
