#pragma once

#include <QDebug>
#include <QMainWindow>

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	GameWindow();
	~GameWindow() { qDebug() << __FUNCTION__; }

private:
	//
};
