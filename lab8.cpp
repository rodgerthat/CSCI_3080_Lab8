/* Norris, Joel R. 
 * filename: lab8.cpp
 * Class: CSCI_3080
 * Description: Decode extended ASCII code, 
*/

#include <iostream>
#include <string>

using namespace std;

// function prototypes
char flipBit(char bit);
string graytoBinaryConverter(string encryptedMessage);
string removeExcess3(string num);

// main program logic
int main() {

	string encryptedMessage = "11100111";
	string modified1 = graytoBinaryConverter(encryptedMessage);
	cout << "Grey code: " << modified1 << endl;
	// now removing excess-3
	cout << "Final result: " << removeExcess3(modified1) << endl;
	return 0;
}

// flipping the bit provided
char flipBit(char bit) { return (bit == '0')? '1': '0'; }

// function to convert gray code string to res string
string graytoBinaryConverter(string encryptedMessage) {

	string res = "";
	// binary NSB code is same as gray code
	res += encryptedMessage[0];

	// calculating remaining bits
	for (int i = 1; i < encryptedMessage.length(); i++) {

		// concatenate previous bit, if bit is 0
		if (encryptedMessage[i] == '0')
		res += res[i - 1];

		// concatenate inverse of previous bit
		else
		res += flipBit(res[i - 1]);
	}

	return res;
}

string removeExcess3(string num) {

   string excess3 = "00000011";
   string res="00000000";
   bool _isCarry = false;
   for (int i = num.length() - 1; i >= 0; --i) {

       res[i] = num[i] - excess3[i] + int('0');

       if(_isCarry == true) {
           res[i]-1;
       }
       if (res[i]==-1) {

           res[i]+2;
           _isCarry = true;
       }
   }
   return res;
  
}
