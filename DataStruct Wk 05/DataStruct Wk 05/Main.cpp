#include <iostream>
#include "Stack.h"

using namespace std;

bool isValid(string);

int main(void) {
	
	cout << isValid(" (  (( ( ) ((( () ))) )) ) ") << endl;


	return 0;
}

bool isValid(string str) {
	Stack stack(str.size());
	for (string::size_type i = 0; i < str.size(); i++) {
		char chara = str[i];
		if (chara == '(')
			stack.push('(');
		else if (chara == ')')
			if (!stack.isEmpty())
				stack.pop();
			else
				return false;
	}
	if (stack.isEmpty())
		return true;
	return false;
}