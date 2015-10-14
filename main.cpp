#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
	string ans;
	string q[20] = {"alive","big","cute","furry","flying","warm_blooded","reptile","swim","tail","hibernate","poisonous","extinct","pet","mammal","carnivor","legs","scales","food","fictional","4legs"};
	int i = 1;
	while (i <=20){
		cout << "question " << i << ": is it " << q[i-1] << "?" << endl;
		cin >> ans;
		if (ans == "y" || ans == "yes" || ans == "indubitably"){
			//add to animal traits
			i++;
		} else if (ans == "n" || ans == "no" || ans == "nay"){
			//add to animal traits
			i++;
		} else{
			cout << "invalid response" << endl;
		}
	}
	cout << "it's a..." << endl;
	//do some comparing
	cout << "thing" << endl;
}
