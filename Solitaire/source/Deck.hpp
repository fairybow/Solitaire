#pragma once

#include "Card.hpp"

#include <QDebug>
#include <QList>

#include <algorithm>
#include <random>

class Deck
{
public:
	Deck()
	{
		for (auto& suit : Card::suits())
			for (auto rank = 0; rank < 14; ++rank)
				m_cards << Card(suit, rank);

		shuffle();
	}

	~Deck()
	{
		qDebug() << __FUNCTION__;
	}

	void print() const
	{
		for (auto& card : m_cards)
			qDebug() << card;
	}

	void shuffle()
	{
		std::random_device seed;
		std::mt19937 random_number_generator(seed());

		std::shuffle(m_cards.begin(), m_cards.end(), random_number_generator);
	}

private:
	QList<Card> m_cards;
};
