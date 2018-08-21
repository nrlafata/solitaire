#include "card.h"
#include "Stack.h"
#include<iostream>

int main() 
{
	Deck setOne;
	setOne.shuffle_deck(500);
	//setOne.printDeck();
	std::cout << "Sorted by suit: ";
	setOne.sortBySuit(false);
	setOne.printDeck();
	std::cout << std::endl;
	std::cout << "Sorted ascending: ";
	setOne.sort(true);
	setOne.printDeck();
	std::cout << std::endl << "Sorted descending: ";
	setOne.sort(false);
	setOne.printDeck();
	std::cout << setOne.draw();
	//Solitaire game;
	//game.loop();
	system("pause");
	return 0;
}