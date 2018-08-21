#include <array>
#include "card.h"

class Solitaire {
public:
	/*
	@brief This function intializes all the necessary decks for the game
	*/
	Solitaire() {
		//create deck
		//create stacks and initialize stacks from deck
	}
	/*
	@brief This function draws all the decks according to the assignment specifications
	*/
	void draw_ui()
	{

	}
	//does all input output stuff 
	void process_game() 
	{

	}
	//void loop() {
		//while (exit_condition) {
			//draw_ui();
			//process_game();
		//}
	//}

private:
	Deck diamond_stack;
	Deck hearts_stack;

	Deck spade_stack;
	Deck clubs_stack;
	std::array<Deck, 6> piles;

};