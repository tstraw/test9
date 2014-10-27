#include "battleship.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout; using std::cin; using std::endl;

//location class function code

location::location(){
	x = -1;
	y = '*';
}

void location::pick(){
	//srand(1); //debugging
	srand(time(nullptr)); //real game
	x = rand() % fieldSize + 1;
	y = rand() % fieldSize;
	switch (y){
		case 0:
			y = 'a';
			break;
		case 1:
			y = 'b';
			break;
		case 2:
			y = 'c';
			break;
		case 3:
			y = 'd';
			break;
		case 4:
			y = 'e';
			break;
	}
}

void location::fire(){
	cin >> y >> x;
}

void location::print() const {
	cout << y << x;
}

bool compare(location loc1, location loc2){
	if (loc1.x == loc2.x && loc1.y == loc2.y){
		return true;
	} 
	else{
		return false;
	}
}

//ship class function code

ship::ship(){
	sunk = false;
}

bool ship::match(location& matchLoc) const{
	return compare(matchLoc, loc);
}

void ship::sink(){
	sunk = true;
}

void ship::setLocation(const location& matchLoc){
	loc = matchLoc;
}

void ship::printShip() const{
	loc.print();
	if (sunk == true){
		cout << " sunk" << endl;
	}
	else if (sunk == false) {
		cout << " not sunk" << endl;
	}
}

// fleet class function code

void fleet::deployFleet(){
	location loc;
	for (int i = 0; i < fleetSize; i++){
		loc.pick();
		ships[i].setLocation(loc);
	}
}

bool fleet::operational() const{
	for (int i = 0; i < fleetSize; i++){
		if (ships[i].isSunk == false)
			return true;
	}
	return false;
}

bool fleet::isHitNSink(const location&){
	for (int i = 0; i < fleetSize; i++){
		if (ships[i].match(matchLoc) == true && ships[i].isSunk() == false){
			ships[i].sink();
			return true;
		}
		else{
			return false;
		}
	}
}

void fleet::printFleet() const{
	for (int i = 0; i < fleetSize; i++){
		ships[i].printShip();
	}
}

int fleet::check(const location & matchLoc) const{
	for (int i = 0; i < fleetSize; i++){
		if (ships[i].match(matchLoc)){
			return loc;
		}
		else{
			return -1;
		}
	}
}
