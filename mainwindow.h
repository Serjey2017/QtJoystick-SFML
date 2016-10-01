#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "xinputGamepad.h"

#include "xqTblMgr.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
	XInput input;
	QTimer tmr;

	XTableMgr tblAxis;
	XTableMgr tblButtons;

	bool f_haveJoystick;

public slots:
	void readJoystickState();
};



#endif // MAINWINDOW_H
