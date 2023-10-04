#pragma once
#include <string>
using namespace std;

class Coin {


private:
	//Just in case, I have given it a default initializer. If the User Had Asked for the coin before being flipped, It could have returned an error
	//This Deals with that case
	string sideUp = "Not Flipped!";

	string massTosses[100];

	double coinRatio = 0;

	//counters for how often each future tossed appears in the array 
	int headCount = 0, tailCount = 0;

public:
	void toss();

	void displaySideUp();

	void setSideUp(string newSide);

	void doToss();

	void calculateStats();

	void dataWrite();



};