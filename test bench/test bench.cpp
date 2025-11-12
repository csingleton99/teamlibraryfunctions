// Team6_CmpSc33_Functions.cpp : Defines the functions for the static library.
// Team 6, Andrew Mayak and Chris Singleton
//


#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

const std::vector<std::string> RANKS = { "ace", "2", "3", "4", "5", "6", "7", "8", "9" , "10", "jack", "queen", "king" };
const std::vector<std::string> SUITS = { "clubs", "hearts", "diamonds", "spades" };
std::vector<std::vector<std::string>> handDecoded;

std::vector<std::vector<std::string>> handDecode(std::vector<int> hand)
{
	std::vector<std::vector<std::string>> handMatrix;

	for (int i = 0; i < hand.size(); i++) //loop through the hand
	{
		std::vector<std::string> handHere;
		handHere.push_back(RANKS.at((hand.at(i) - 1) % 13)); // for each element in the hand, set the rank to the modulus of the number and 13
		handHere.push_back(SUITS.at((hand.at(i) - 1) / 13)); // for each element in the hand, set the suit to the result of integer division number/13
		handMatrix.push_back(handHere);
	}
	return handMatrix;
}

int isHandStraight(std::vector<int> hand)
{
	int isStraight = 1;

	sort(hand.begin(), hand.end());

	int lowestCard = hand.at(0); //identify lowest card
	int nextInterval = lowestCard + (13 - (lowestCard % 13)); //identify next suit interval
	int prevCard = lowestCard - 1;

	std::cout << nextInterval - lowestCard << " >= " << hand.size() << "\n"; // TEST CODE

	if (nextInterval - lowestCard >= hand.size()) // make sure a straight is even possible
	{
		for (int i = 0; i < hand.size(); i++) // loop through the hand
		{
			std::cout << hand.at(i) - 1 << " ?= " << prevCard << "\n"; // TEST CODE
			if (hand.at(i) - 1 != prevCard)
				isStraight = 0;
			prevCard = hand.at(i);
		}
	}
	else
	{
		isStraight = 0;
	}
	return isStraight; // return 0 if no, 1 if yes
}

int isHandFlush(std::vector<int> hand)
{
	int isFlush = 1;

	sort(hand.begin(), hand.end());
	handDecoded = handDecode(hand);

	std::string suitKey = handDecoded.at(0).at(1);

	std::cout << suitKey << ": "; //TEST CODE

	for (int i = 0; i < handDecoded.size(); i++)// loop through handDecoded
	{
		std::cout << handDecoded.at(i).at(1) << ", "; //TEST CODE
		if (handDecoded.at(i).at(1) != suitKey) // check if each element is the same as that of the first, set isFlush to 0 if not
			isFlush = 0;
	}
	std::cout << "\n"; //TEST CODE

	return isFlush; // return 0 if no, 1 if regular flush, 2 if royal flush
}

int handIncludesMultiples(std::vector<int> hand)
{
	sort(hand.begin(), hand.end());

	return 0; // return 0 if no, 1 if two-of-a-kind, 2 if three-of-a-kind, 3 if four-of-a-kind 
}







//------------------------------------------------


int main()
{
	int cardCount = 0;
	const std::vector<int> deck = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52};

	const std::vector<int> handone = { 1,2,3,4,5};
	const std::vector<int> handtwo = { 11,12,13,14,15 };
	const std::vector<int> handthree = { 1,6,7,13,50 };
	const std::vector<int> handfour = { 20,30,40,50,52 };

	//isHandFlush(deck);
	//std::cout << isHandFlush(deck) << "\n";

	std::cout << isHandFlush(handone) << "\n";

	std::cout << isHandFlush(handtwo) << "\n";

	std::cout << isHandFlush(handthree) << "\n";

	std::cout << isHandFlush(handfour) << "\n";


	std::cout << isHandStraight(handone) << "\n";

	std::cout << isHandStraight(handtwo) << "\n";

	std::cout << isHandStraight(handthree) << "\n";

	std::cout << isHandStraight(handfour) << "\n";


	/*for (int i = 0; i < 4; i++) // prints out the original contents of the deck
	{
		for (int j = 0; j < 13; j++)
		{
			cardCount++;
			printf("%2d ", cardCount);
		}
		std::cout << "   <-- " << SUITS[i] << "\n";
	}*/
}