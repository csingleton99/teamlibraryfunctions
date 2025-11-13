// Team6_CmpSc33_Functions.cpp : Defines the functions for the static library.
// Team 6, Andrew Mayak and Chris Singleton
//

#include "pch.h"
#include "framework.h"
#include <vector>
#include <set>
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

	if (nextInterval - lowestCard >= hand.size()) // make sure a straight is even possible
	{
		for (int i = 0; i < hand.size(); i++) // loop through the hand
		{
			if ((hand.at(i) - 1) % 13 == (prevCard) % 13)
				straightCounter++;

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

	int isStraight = 0;
	int currentCounter = 0;
	int highestCounter = 0;
	std::set<std::string> rankSet;

	sort(hand.begin(), hand.end());
	handDecoded = handDecode(hand);

	for (int i = 0; i < handDecoded.size(); i++) //create a set which just tracks the unique ranks in the hand
		rankSet.insert(handDecoded.at(i).at(0));

	for (std::string rankHere : rankSet) // for every unique rank in the hand...
	{
		for (int i = 0; i < handDecoded.size(); i++) // loop through the hand once...
		{
			if (rankHere == handDecoded.at(i).at(0)) // and total the occurances of that rank
				currentCounter++;
		}

		if (currentCounter > highestCounter) // If the rank you just checked occurs more often than the previous...
			highestCounter = currentCounter; // Then it becomes the new highest

		currentCounter = 0; //reset counter after each loop
	}

	if (highestCounter == 1)
		isStraight = 0;
	else if (highestCounter == 2)
		isStraight = 1;
	else if (highestCounter == 3)
		isStraight = 2;
	else if (highestCounter == 4)
		isStraight = 3;

	return isStraight; // return 0 if no, 1 if two-of-a-kind, 2 if three-of-a-kind, 3 if four-of-a-kind 
}
