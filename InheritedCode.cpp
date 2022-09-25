#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;
/*
I had never done anything with exceptions before so I found this one quite confusing,
especially since it doesn't specify that you are supposed to create a new class. For anyone else wondering,

BadLengthException(n) is a class constructor, not just an external function.

The variable "e" is an object of this class, and "what()" is a function inside the class.
For anyone else unfamiliar with exceptions, an exception consists of a "throw" and a "catch".
A "throw" is followed by an object or variable. When the "throw" is called,
the program will jump to the "catch" using said object/variable as an input to the catch.
In this case, the throw constructs a new object of class "BadLengthException",
which is then used as the input to the catch (this is labelled as "e").

The code that I used is as follows:
*/

/* Define the exception here */
class BadLengthException {
    private: 
        int n;
    public:
        BadLengthException(int num) {	//constructor declaration
            n = num;
        }
    
        int what() {
            return n;
        }
};



bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n); //class constructor
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}