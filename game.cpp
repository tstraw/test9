#include "battleship.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main (){
	char answer;	
	fleet compFleet;
	compFleet.deployFleet();
	cout << "Do ships' positions and status need to be printed? (y or n): " << endl;
	cin >> answer;
	if (answer == 'y'){
		myFleet.printFleet();
	  }
	while (myFleet.operational() == true){
		cout << "there are still ships up";
		location userShot;
		userShot.location();
		cout << "Input shot location: ";
		userShot.fire();
		if (compFleet.isHitNSink(userShot) == true){
			cout << "hit";
			}
		else{
			cout << "miss";
			}
		cout << "Do ships' positions and status need to be printed? (y or n): ";
		cin >> answer;
		if (answer== 'y'){
			myFleet.printFleet();
			}
		else if (answer=='n'){
			cout << "Thank you for playing.\n";
			break;
			}
	}
}
