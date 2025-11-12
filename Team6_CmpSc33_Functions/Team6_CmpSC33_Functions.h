#pragma once

#include <vector>
#include <iostream>

// returns 0 for no, 1 for yes, 2 for straight-flush
int isHandStraight(std::vector<int> hand);

// returns 0 for no, 1 for yes, 2 for royal flush
int isHandFlush(std::vector<int> hand);

// returns 0 for no, 1 for two-of-a-kind, 2 for three-of-a-kind, 3 for four-of-a-kind
int handIncludesMultiples(std::vector<int> hand);
