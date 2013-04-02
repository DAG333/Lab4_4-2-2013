#include "stdafx.h"
#include "FiveCardDraw.h"

FiveCardDraw::FiveCardDraw(){ 
	dealer = 0;
	//create all 52 cards
	//add_card them to Deck
	_deck =  Deck(1);
	_trash = Deck();
}


vector<string> FiveCardDraw::tokenize(string input){
	string token;
	istringstream iss(input);
	vector<string> vs;
	while ( getline(iss, token, ' ') )
	{
		vs.push_back(token);
	}
	return vs ;
}

vector<int> FiveCardDraw::discardPrompt(Player & p){
	cout << "Your hand is: " << endl;
	cout << p._hand << endl;

	cout << "What cards do you want to discard?" << endl;
	string input;
	cin >> input; 

	vector<string> vs = tokenize(input);

	vector<int> vi;
	for(unsigned int i =0; i < vs.size(); i++){
		int temp = atoi(vs[i].c_str());
		if(0 < temp < 6){
			vi[i] = temp;
		}
		else{
			cout << "Invalid input! Please type the card numbers you want to discard again" << endl
				<< "e.g. '1 3 5'" << endl;
			discardPrompt(p);
		}
	}
}

int FiveCardDraw::before_turn(Player & p){
	cout << "It is your turn: " << p._name << endl;
	vector<int> vi = discardPrompt(p);
	//sort in decreasing order
	sort(vi.begin(), vi.end(), greater<int>());
	//remove duplicates
	vi.erase( unique(vi.begin(), vi.end()), vi.end());
	//now remove the cards at these indices from hand
	for(int i = 0; i < (int)vi.size(); i++){
		int card_index = vi[i] - 1;
		p._hand.remove_card(card_index);
	}
	return 0;
}

int FiveCardDraw::turn(Player & p){
	return 0;
}

int FiveCardDraw::after_turn(Player & p){
	
	return 0;
}

int FiveCardDraw::before_round(){
	
	return 0;
}

int FiveCardDraw::round(){
	return 0;
}

int FiveCardDraw::after_round(){
	Player * winner = _players[0];
	for(unsigned int i = 0; i < _players.size(); i++){
		if(_players[i] == winner){
			_players[i]->won++;
		}
		else{
			_players[i]->lost++;
		}
	}



	return 0;
}
