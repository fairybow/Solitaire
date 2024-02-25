#include "GameWindow.h"

// Testing
#include <QPushButton>

GameWindow::GameWindow()
	: QMainWindow()
{
	auto test_button = new QPushButton(this);
	test_button->setText("Test");
	setCentralWidget(test_button);

	connect(test_button, &QPushButton::pressed, this, [&] {

		m_deck.print();

		});
}
