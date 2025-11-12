// Team6_CmpSc33_Functions.cpp : Defines the functions for the static library.
// Team 6, Andrew Mayak and Chris Singleton
//


#include "pch.h"
#include "framework.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

const std::vector<std::string> RANKS = { "ace", "2", "3", "4", "5", "6", "7", "8", "9" , "10", "jack", "queen", "king" };
const std::vector<std::string> SUITS = { "clubs", "hearts", "diamonds", "spades" };
std::vector<std::vector<std::string>> handDecoded;

static std::vector<std::vector<std::string>> handDecode(std::vector<int> hand)
{
	std::vector<std::vector<std::string>> handMatrix;

	for (int i = 0; i < hand.size(); i++) //loop through the hand
	{
		std::vector<std::string> handHere;
		handHere.push_back(RANKS.at((hand.at(i)-1) % 13)); // for each element in the hand, set the rank to the modulus of the number and 13
		handHere.push_back(SUITS.at((hand.at(i)-1) / 13)); // for each element in the hand, set the suit to the result of integer division number/13
		handMatrix.push_back(handHere);
	}
	return handMatrix;
}

int isHandStraight(std::vector<int> hand)
{
	std::cout << "RUNNING isHandStraight Function" << "\n";

	int isStraight = 0;
	int straightCounter = 0;

	sort(hand.begin(), hand.end());

	int lowestCard = hand.at(0); //identify lowest card
	int nextInterval = lowestCard + (13 - (lowestCard % 13)); //identify next suit interval
	int prevCard = (lowestCard - 1) % 13 ;

	std::cout << nextInterval - lowestCard << " >= " << hand.size() << "\n"; // TEST CODE

	if (nextInterval - lowestCard >= hand.size()) // make sure a straight is even possible
	{
		for (int i = 0; i < hand.size(); i++) // loop through the hand
		{
			std::cout << (hand.at(i) - 1) % 13 << " ?= " << (prevCard) % 13 << "\n"; // TEST CODE

			if ((hand.at(i) - 1) % 13 == (prevCard) % 13)
				straightCounter++;

			std::cout << "straight count: " << straightCounter << "\n"; // test code

			if (straightCounter >= 5)
				isStraight = 1;

			if (hand.at(i) == nextInterval)
			{
				straightCounter = 0;
				nextInterval += 13;
			}

			prevCard = hand.at(i);
		}
	}
	return isStraight; // return 0 if no, 1 if yes
}

int isHandFlush(std::vector<int> hand)
{
	std::cout << "RUNNING isHandFlush Function" << "\n";
	int isFlush = 0;
	int clubCounter = 0;
	int heartCounter = 0;
	int diamondCounter = 0;
	int spadeCounter = 0;

	sort(hand.begin(), hand.end());
	handDecoded = handDecode(hand);

	for (int i = 0; i < handDecoded.size(); i++)// loop through handDecoded
	{
		std::cout << handDecoded.at(i).at(1) << ", "; //TEST CODE
		if (handDecoded.at(i).at(1) == "clubs") // check suit and add to counter
			clubCounter++;
		if (handDecoded.at(i).at(1) == "hearts")
			heartCounter++;
		if (handDecoded.at(i).at(1) == "diamonds")
			diamondCounter++;
		if (handDecoded.at(i).at(1) == "spades")
			spadeCounter++;

		if (clubCounter >= 5 or heartCounter >= 5 or diamondCounter >= 5 or spadeCounter >= 5)
			isFlush = 1;
	}

	return isFlush; // return 0 if no, 1 if regular flush, 2 if royal flush
}

int handIncludesMultiples(std::vector<int> hand)
{
	std::cout << "RUNNING handIncludesMultiples Function" << "\n";

	sort(hand.begin(), hand.end());

	// loop through the hand, checking each decoded rank against all others present. Set a flag if the count reaches 2, 3, or 4
	// ideally find a way to skip the loop if that rank has already appeared, maybe by adding that rank to a list for comparison?

	return 0; // return 0 if no, 1 if two-of-a-kind, 2 if three-of-a-kind, 3 if four-of-a-kind 
}
