#ifndef QTPLAYER_H
#define QTPLAYER_H

#include <QtWidgets/QMainWindow>
#include "ui_qtplayer.h"
#include "2048Core.h"
#include <map>

using namespace Core2048;

class QTPlayer : public QMainWindow
{
	Q_OBJECT

public:
	QTPlayer(QWidget *parent = 0);
	~QTPlayer();

private:

	// handles the events
	bool event(QEvent *event);
	
	// refreshes the UI
	void RefreshUI();

	Ui::QTPlayerClass ui;
	TILE mGrid[SIZE][SIZE];
	QLabel *mpLabels[SIZE][SIZE];

	std::map<int, Direction> mDirectionMap;
};

#endif // QTPLAYER_H
