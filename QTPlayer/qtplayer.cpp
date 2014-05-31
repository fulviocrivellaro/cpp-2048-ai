#include "qtplayer.h"
#include <math.h>
#include <qevent.h>
#include <qmessagebox.h>

QTPlayer::QTPlayer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	mDirectionMap[Qt::Key_Left] = Direction::Left;
	mDirectionMap[Qt::Key_Right] = Direction::Right;
	mDirectionMap[Qt::Key_Up] = Direction::Up;
	mDirectionMap[Qt::Key_Down] = Direction::Down;

	mpLabels[0][0] = ui.label_00;
	mpLabels[0][1] = ui.label_01;
	mpLabels[0][2] = ui.label_02;
	mpLabels[0][3] = ui.label_03;
	mpLabels[1][0] = ui.label_10;
	mpLabels[1][1] = ui.label_11;
	mpLabels[1][2] = ui.label_12;
	mpLabels[1][3] = ui.label_13;
	mpLabels[2][0] = ui.label_20;
	mpLabels[2][1] = ui.label_21;
	mpLabels[2][2] = ui.label_22;
	mpLabels[2][3] = ui.label_23;
	mpLabels[3][0] = ui.label_30;
	mpLabels[3][1] = ui.label_31;
	mpLabels[3][2] = ui.label_32;
	mpLabels[3][3] = ui.label_33;

	ResetGrid(mGrid);
	Randomize();
	AddNewTile(mGrid);
	RefreshUI();
}

QTPlayer::~QTPlayer()
{

}

void QTPlayer::RefreshUI()
{
	for (tilePtr c=0; c<SIZE; ++c)
	{
		for (tilePtr r=0; r<SIZE; ++r)
		{
			if (mGrid[c][r] == 0)
			{
				mpLabels[c][r]->setText("");
			}
			else
			{
				mpLabels[c][r]->setText(QString::number(pow(2, (int)mGrid[c][r])));
			}
		}
	}

	if (Stalled(mGrid))
	{
		QMessageBox::information(NULL, "Nothing to do anymore...", "Shit!");
	}
}

bool QTPlayer::event(QEvent *event)
 {
     if (event->type() == QEvent::KeyPress) {
         QKeyEvent *ke = static_cast<QKeyEvent *>(event);

		 try
		 {
			 Direction dir = mDirectionMap.at(ke->key());
			 if (CanMove(mGrid, dir))
			 {
				Move(mGrid, dir);
				AddNewTile(mGrid);
				RefreshUI();
			 }
		 }
		 catch (std::exception)
		 {}
     }

     return QWidget::event(event);
 }