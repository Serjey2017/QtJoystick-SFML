#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    f_haveJoystick = input.initInput(0);
	if (!f_haveJoystick)
	{
		this->setWindowTitle(QString("%1 :: %2").arg(this->windowTitle()).arg("Joystick not found"));
	}
	else
	{
		this->setWindowTitle(QString("%1 :: %2").arg(this->windowTitle()).arg("Joystick present"));
	}

	// init tables
	tblAxis.initTbl(ui->tblAxis);
	tblAxis.setHHeaderText(0,"Axis ID");
	tblAxis.setHHeaderText(1,"Value");

	tblButtons.initTbl(ui->tblButtons);
	tblButtons.setHHeaderText(0,"Button ID");
	tblButtons.setHHeaderText(1,"State");

	// refresh timer interval (reads new values from joystick)
	if (f_haveJoystick)
	{
		tmr.setInterval(15);
		connect(&tmr,SIGNAL(timeout()),this,SLOT(readJoystickState()));
		tmr.start();
	}
}

void MainWindow::readJoystickState()
{
    if (!input.updateState()) return;

    // Update main axes
    ui->sliderVertical->setValue((input.getVertical()+1.0f)*50.0f);
    ui->sliderHorizontal->setValue((input.getHorizontal()+1.0f)*50.0f);
    ui->dialRotation->setValue((input.getRotationZ()+1.0f)*50.0f);
    ui->dialThrottle->setValue((input.getThrottle()+1.0f)*50.0f);


    // Output raw axes values
    for (int r = 0;
         r < std::min( tblAxis.rows(), input.getRawAxisCount() );
         r++)
	{
		tblAxis.setText(r,0,QString("%1").arg(r));
        float value = input.getRawAxis(r);
		tblAxis.setText( r,1, QString("%1").arg(value) );
	}

    // Output buttons' state
	for (int r = 0; r < tblButtons.rows(); r++)
	{
		tblButtons.setText( r,0,QString("%1").arg(r) );

        bool isPressed = input.isKeyPressed(r);
		QString stateString("-");
		if (isPressed) stateString = QString("Pressed");

		tblButtons.setText( r,1, stateString );
	}
}

MainWindow::~MainWindow()
{
    delete ui;
}

