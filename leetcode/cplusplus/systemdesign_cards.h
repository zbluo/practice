#pragma once
#include "Solution.h"
#include <iostream>

class systemdesign_cards
{
public:
	systemdesign_cards();
	~systemdesign_cards();
};

enum class CardsType
{
	club,
	spade,
	heart,
	diamond,
	endOfList
};



class Card
{
private:
	CardsType mType;
	int mValue;
	bool mFace;
public:
	Card(CardsType type, int val, bool face) {
		mType = type;
		mValue = val;
		mFace = face;
	}

	bool Face() {
		return mFace;
	}

	void SetFace(bool face) {
		mFace = face;
	}

	CardsType Type() {
		return mType;
	}

	int Value() {
		return mValue;
	}
};
/*
CardsType operator++ (CardsType& type, int) {
	type = static_cast<CardsType>(static_cast<int>(type) + 1);
	if (type == CardsType::endOfList)
		type = CardsType::club;
	return type;
};
*/
class Deck
{
private:
	list<Card> mCardsList;
public:

	Deck() {
		for (int i = 0; i <= 3; i++) {
			for (int j = 1; j <= 13; j++) {
				mCardsList.push_back(Card((CardsType)i, j, true));
			}
		}
	}
	
	list<Card> CardsInDeck() {
		return mCardsList;
	}

	~Deck() {}
};

class CardBox
{
private:
	list<Card> mCardsList;
public:
	CardBox() {}
	~CardBox() {}

	CardBox(Deck initialDeck) {
		mCardsList.insert(mCardsList.end(), initialDeck.CardsInDeck().begin(), initialDeck.CardsInDeck().end());
	}

	void Shuffle() {
		if (mCardsList.empty())
			return;

		vector<Card> cardsToShuffle(mCardsList.begin(), mCardsList.end());
		shuffle(cardsToShuffle.begin(), cardsToShuffle.end(), std::default_random_engine());
		mCardsList.assign(cardsToShuffle.begin(), cardsToShuffle.end());
	}

	void AppendDeck(Deck oneDeck) {
		list<Card> temp = oneDeck.CardsInDeck();
		mCardsList.insert(mCardsList.end(), temp.begin(), temp.end());
	}

	Card PopCard() {
		Card poppedCard = mCardsList.front();
		mCardsList.pop_front();
		return poppedCard;
	}
};

class Gamer {
protected:
	int mID;
	string mName;
	double mMoney;
	list<Card> mHandCards;

public:
	virtual int MakeDecision() = 0;
	virtual void AddCard(Card cardToAdd) = 0;
	virtual list<Card> ShowHand() = 0;
	virtual double ShowMoney() = 0;
	virtual double Win(double money) = 0;
	virtual double Lose() = 0;
	virtual string Name() = 0;
};

class Player : public Gamer {
private:
	double mBet;
public:
	Player() {}
	~Player() {}

	Player(int id, string name, int money) {
		mID = id;
		mName = name;
		mMoney = money;
	}

	string Name() {
		return mName;
	}

	double Win(double money) {
		mMoney = money + mBet;
		return mMoney;
	}

	double Lose() {
		mMoney -= mBet;
		return mBet;
	}

	double ShowMoney() {
		return mMoney;
	}

	void AddCard(Card cardToAdd) {
		mHandCards.insert(mHandCards.end(), cardToAdd);
	}

	// 0 -> add card, 1->ShowHan, 2 -> add more bet
	int MakeDecision() {
		int value = 0;
		if (mHandCards.empty())
			return 0;

		for (auto myCard : mHandCards) {
			value += myCard.Value();
		}

		if (value < 15)
			return 0;
		else if (value >= 15 && value < 20 || value > 21)
			return 1;
		else
			return 2;
	}

	list<Card> ShowHand() {
		list<Card> temp = mHandCards;
		mHandCards.clear();
		mBet = 0;
		return temp;
	}

	int PlayBet(int money) {
		if (money > mMoney)
			return 0;
		mBet += money;
		mMoney -= money;

		return (int)mBet;
	}
};

class Dealer : public Gamer {
private:
	CardBox mCardBox;
	// 0 -> not started, 1 -> on-going, 2 -> finished
	int mGameState = 0;
	int mBet = 0;

public:

	Dealer() { mGameState = 0; }
	~Dealer() {}

	Dealer(int id, string name, int money) {
		mID = id;
		mName = name;
		mMoney = money;
	}

	string Name() {
		return mName;
	}

	double Win(double money) {
		mMoney = money + mBet;
		return mMoney;
	}

	double Lose() {
		mMoney -= mBet;
		return mBet;
	}

	double ShowMoney() {
		return mMoney;
	}

	void RunGame() {
		for (int i = 0; i <= 1; i++) {
			Deck oneDeck;
			mCardBox.AppendDeck(oneDeck);
		}

		mCardBox.Shuffle();
		mGameState = 1;
	}

	// dealer is the first one in the list
	Gamer* DecideWinner(list<Gamer*> playerList) {
		map<int, Gamer*> players;
		
		for (auto player : playerList) {
			int score = 0;
			for (auto card : player->ShowHand())
				score += card.Value();

			if(score <= 21)
  				players[score] = player;
		}

		mGameState = 2;

		return players.empty() ? playerList.front() : players.rbegin()->second;
	}

	void AddCard(Card cardToAdd) {
		mHandCards.insert(mHandCards.end(), cardToAdd);
	}

	// 0 -> add card, 1->ShowHan, 2 -> add more bet
	int MakeDecision() {
		int value = 0;

		if (mHandCards.empty())
			return 0;

		if (mBet == 0)
			return 2;

		for (auto myCard : mHandCards) {
			value += myCard.Value();
		}
		if (value < 15)
			return 0;
		else if (value >= 15 && value < 20 || value > 21)
			return 1;
		else
			return 2;
	}

	list<Card> ShowHand() {
		list<Card> temp = mHandCards;
		mHandCards.clear();
		mBet = 0;
		return temp;
	}

	int PlayBet(int money) {
		if (money > mMoney)
			return 0;
		mBet += money;
		mMoney -= money;

		return mBet;
	}

	Card IssueCard() {
		return mCardBox.PopCard();
	}
};

class GameRoom {
private:
	Dealer* mDealer;
	list<Gamer*> mPlayerList;
public:
	void JointPlayer(Gamer* player) {
		mPlayerList.insert(mPlayerList.end(), player);
	}

	void LeavePlayer(Gamer* playerToLeave) {
		mPlayerList.remove(playerToLeave);
	}

	list<Gamer *> PlayerList() {
		return mPlayerList;
	}

	GameRoom OpenGameRoom() {
		GameRoom room;
		return room;
	}
};

class Casino {
public:

	void NormalOperating() {
		GameRoom room;
		Dealer dealer(0, "Alice", 1000);
		Player player1(1, "Bob", 1000);
		Player player2(2, "John", 1000);
		room.JointPlayer(&dealer);
		room.JointPlayer(&player1);
		room.JointPlayer(&player2);


		dealer.RunGame();
		int j = 0;
		while (j++ < 5) {
			int i = 0;
			while (i++ < 5) {
				switch (dealer.MakeDecision()) {
				case 0:	dealer.AddCard(dealer.IssueCard());
				case 2: dealer.PlayBet(5);
				}
				switch (player1.MakeDecision()) {
				case 0:	player1.AddCard(dealer.IssueCard());
				case 2: player1.PlayBet(5);
				}
				switch (player2.MakeDecision()) {
				case 0:	player2.AddCard(dealer.IssueCard());
				case 2: player2.PlayBet(5);
				}
			}

			Gamer* player = dealer.DecideWinner(room.PlayerList());
			int moneyEarned = 0;
			for (auto p : room.PlayerList()) {
				if (p != player) {
					moneyEarned += (int)p->Lose();
				}
			}
			player->Win(moneyEarned);

			cout << "\nWinner is: " << player->Name();

		}

	}
};

template <class T>
class TemplateTest {
private:
	T x;
	T y;
public:
	TemplateTest(T a, T b) {
		x = a;
		y = b;
	}

	void Set(T a, T b) {
		x = a;
		y = b;
	}

	T GetMax() {
		T c;
		if (x >= y)
			c = x;
		else
			c = y;
		return c;
	}

	T GetMin() {
		T c;
		if (x <= y)
			c = x;
		else
			c = y;
		return c;
	}
};
// to implement the template function in .cpp file, need to include .cpp file here and remove this .cpp file from the project.
// #include "systemdesign_cards.cpp"
