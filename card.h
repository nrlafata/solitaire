#pragma once
#include <vector>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <ctime>  

#include "Stack.h"

//Create struct for card

#define ace 1
#define jack 11
#define queen 12
#define king 13

using std::string;

struct Card
{
	Card(const int &ivalue, const string& isuit)
	{
		value = ivalue;
		suit = isuit;
	}
	Card() {
		suit = "";
		value = 0;
	}
	//suit
	//value 1-13
	string suit; 
	int value;
};
inline
bool operator <(const Card&x, const Card &y)
{
	
		return x.value < y.value;
}
inline
bool operator >(const Card&x, const Card &y)
{

		return x.value > y.value;
}
inline
bool operator *(const Card&x, const Card &y)
{
	if (x.suit != y.suit)
	{
		return x.suit.front() < y.suit.front();
	}
	else
		return x.value < y.value;



}
inline
std::ostream & operator << (std::ostream &out, const Card &c)
{
	
	if (c.value == 1)
	{
		out << "{" << "A" << c.suit.front() << "}";
	}
	else if (c.value == 11)
	{
		out << "{" << "J" << c.suit.front() << "}";
	}
	else if (c.value == 12)
	{
		out << "{" << "Q"<< c.suit.front() << "}";
	}
	else if (c.value == 13)
	{
		out << "{" << "K"<< c.suit.front() << "}";
	}
	else 
		out << "{" << c.value << c.suit.front() << "}";
	return out;
}

class Deck
{
public:
	Deck() 
	{
//		deck.reserve(52);
		//Create a 52 card deck with all suits
			for (int i = 0; i<13; ++i) //0-12
			{
				deck.push_back( Card(i + 1, "Hearts"));
			}
			for (int i = 0; i < 13; ++i)//13-25
			{
				deck.push_back(Card(i + 1, "Diamonds"));
			}
			for (int i = 0; i < 13; ++i)//26-38
			{
				deck.push_back(Card(i + 1, "Clubs"));
			}
			for (int i = 0; i < 13; ++i)//39-52
			{
				deck.push_back(Card(i + 1, "Spades"));
			}
	}
	void sort(bool order)
	{
		deck.BubbleSort(deck.size(),order);
	}
	void printDeck()
	{
		deck.printStack();
	}
	/**
	@brief this function takes 2 card indexes and swaps their positions
	*/
	void swap(const int& card1, const int& card2)
	{
		deck.swap(card1, card2);
	}
	/*
	@brief this function swaps random card indexes n number of times
	*/
	void shuffle_deck(const int& n)
	{
		srand(time(NULL));
		for (int i = 0; i < n; ++i)
		{
			int y = rand() % 52;
			int x = rand() % 52;
			swap(x, y);
		}
	}
	void sortBySuit(bool order)
	{

		deck.BubbleSortWeird(deck.size(),order);
	}
	/*
	@brief remove a card from the back(top) of the deck and return it
	*/
	Card draw()
	{
		Card T = deck.at(deck.size() - 1);
		deck.pop_back();
		return T;
	}
	/*
	@brief place a card on the back(top) of the deck
	*/
	void emplace(const Card& c)
	{
		deck.push_back(c);
	}
	//move cards

private:
	Stack<Card> deck;
};
