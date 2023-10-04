#include "Coin.h"
#include <cstdlib> 
#include <iostream>
#include <ctime> 
#include <cmath> 
#include <fstream>
#include <string>
#include <iomanip>
#include <random>
using namespace std;

void Coin::toss()
{
	//this functions Inteded Purpose is to generate a random number between 1 and 2, 
	/*
	* 1 being heads
	* 2 being tails 
	* 
	* then depending on the result, set sideup to the coin side facing up 
	*/
	int min = 1, max = 2;

	//seed random number generator 

	//THE FOLLOWING CODE HAS BEEN IMPLEMENTED BECAUSE THE PREVIOUSLY USED Random number generator is to slow for C++'s complier task I am preforming 
	random_device rd;
	mt19937 generator(rd());
	
	uniform_int_distribution<int> distribution(1, 2);

	//generate a random number to guess 
	int randomCoinSide = distribution(generator);

	//switch out the value, and depending on what it is set sideUp to it 
	switch (randomCoinSide)
	{
	case 1:
		sideUp = "Heads!";
		break;
	case 2: 
		sideUp = "Tails!";
		break;
	default:
		break;
	}
}

void Coin::displaySideUp()
{
	//Functions Purpose is to cout the flipped C
	cout << sideUp;
}

void Coin::setSideUp(string newSide)
{
	sideUp = newSide;
}

void Coin::doToss()
{

	//flip the coin 100 times, and add its flipped value to the array
	//tc = Toss Count
	for (int tc = 0; tc < 100; tc++) {
		//first call toss to generate a flip value
		toss();
		//with the flipped value set, add that coin to mass flipped
		massTosses[tc] = sideUp;



	}

	//PROGRAMS ORDER: First call the do toss, which will call calculate stats, which when done will FINALLY call dataWrite()
	calculateStats();


}

void Coin::dataWrite()
{
	//make the output file 
	ofstream outPutFile("results.txt");

	//first append the 100 values neatly to results 
	
	//to do this, iterate on the mass array, and print each statement to the page 
	cout << setprecision(4);
	outPutFile << setprecision(4);
	//TR = Toss Result
	for (string tr : massTosses) {
		//write the output to the file 
		outPutFile << tr << "\n";

		//PRG RECS
		cout << tr << endl;
	}
	//now write out the number each toss took 

	outPutFile << "Heads Was Flipped: " << headCount << "Times!\n" << "Tails Was Flipped: " << tailCount << "Times!\n";
	cout << "Heads Was Flipped: " << headCount << "Times!\n" << "Tails Was Flipped: " << tailCount << "Times!\n";
	//finally, print the ratio of the flips 


	outPutFile << "The Ratio Of Heads Appearances To Tails is: " << coinRatio;
	cout << "The Ratio Of Heads Appearances To Tails is: " << coinRatio;
	//for project requirements, Cout Everything Else too

}

void Coin::calculateStats()
{
	//this section will calculate the ratio of heads/Tails, and seperates them out from the array preforms the required manipulation 

	

	//now loop over the list, and depending on whats in the list add 1 to the respective value 

	//using a for each loop, loop through the values in the massToss 

	for (string result : massTosses) {
		if (result == "Heads!") {
			headCount++;
		}
		else if (result == "Tails!")
		{
			//because im testing against heads, We can assume anything else in the array would be tails
			tailCount++;
		}
	}

	//with the tallied results, now calculate the ratio of Heads To Tails 

	//to avoid any potential division errors, convert headcount to a double 
	coinRatio = static_cast<double>(headCount) / tailCount;

	//with now all the data gathered, call dataWrite to write all the required Data to the File. 
	dataWrite();


}
