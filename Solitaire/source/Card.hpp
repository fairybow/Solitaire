#pragma once

#include <QDebug>
#include <QList>
#include <QString>

#include <ostream>

class Card
{
public:
	enum class Suit {
		Club,
		Diamond,
		Heart,
		Spade
	};

	Card(Suit suit, int rank)
		: m_suit(suit), m_rank(qBound(0, rank, 13))
	{}

	~Card()
	{
		qDebug() << __FUNCTION__;
	}

	friend std::ostream& operator<<(std::ostream& os, const Card& card)
	{
		os << "("
			<< "Card(" << &card << "), "
			<< card.suitName().toStdString() << ", "
			<< card.m_rank
			<< ")";

		return os;
	}

	friend QDebug operator<<(QDebug debug, const Card& card)
	{
		debug.nospace() << "("
			<< "Card(" << &card << "), "
			<< card.suitName().toStdString() << ", "
			<< card.m_rank
			<< ")";

		return debug.maybeSpace();
	}

	static QList<Suit> suits()
	{
		return { Suit::Club, Suit::Diamond, Suit::Heart, Suit::Spade };
	}

	QString suitName() const
	{
		QString name;

		switch (m_suit) {
		case Suit::Club:
			name = "Club";
			break;
		case Suit::Diamond:
			name = "Diamond";
			break;
		case Suit::Heart:
			name = "Heart";
			break;
		case Suit::Spade:
			name = "Spade";
			break;
		}

		/*switch (m_suit) {
		case Suit::Club:
			name = QChar(0x2663);
			break;
		case Suit::Diamond:
			name = QChar(0x2666);
			break;
		case Suit::Heart:
			name = QChar(0x2665);
			break;
		case Suit::Spade:
			name = QChar(0x2660);
			break;
		}*/

		return name;
	}

private:
	Suit m_suit;
	int m_rank;
};
