#include <iostream>
#include "name_generator.h"

/**
    Simple random team generate for my friends and me when we get
	together and play Halo or pitch. Generates 3v3 or 2v2v2.

	@author Vasili Papastrat
	@version 1.0 5/23/2014
*/

/*
0 = Vasili
1 = Dimit
2 = Peter
3 = John
4 = Josh
5 = Chris
*/

int main()
{
    name_generator<> generator("Vasili", "Dimit", "Peter", "John", "Josh", "Chris");
    std::cout << generator;
}
