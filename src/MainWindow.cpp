#include "MainWindow.hpp"
#include "Widget/SideMenuWidget.hpp"
#include "Widget/ActuatorWidget.hpp"
#include "Widget/AlertLogWidget.hpp"
#include "Widget/ChartWidget.hpp"

#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QSplitter>
#include <QLayout>
#include <QMenu>

using namespace HumanMachineInterface;

MainWindow::MainWindow()
{
    QPalette pal = palette();
    QPalette blk = palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setWindowTitle("Sample");
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setWindowState(windowState() ^ Qt::WindowMaximized);

    QSplitter* horizontalSplitter = new QSplitter(Qt::Horizontal, this);
    QSplitter* verticalRightSplitter = new QSplitter(Qt::Vertical, this);

    QWidget* leftWidget = new SideMenuWidget(this);
    QWidget* centralWidget = new ChartWidget(this);
    QWidget* rightTopWidget = new ActuatorWidget(this);
    QWidget* rightBottomWidget = new AlertLogWidget(this);

    verticalRightSplitter->addWidget(rightTopWidget);
    verticalRightSplitter->addWidget(rightBottomWidget);

    horizontalSplitter->addWidget(leftWidget);
    horizontalSplitter->addWidget(centralWidget);
    horizontalSplitter->addWidget(verticalRightSplitter);
    
    horizontalSplitter->setStretchFactor(0,1);
    horizontalSplitter->setStretchFactor(1,6);
    horizontalSplitter->setStretchFactor(2,2);
    verticalRightSplitter->setStretchFactor(0,1);
    verticalRightSplitter->setStretchFactor(1,2);

    this->setCentralWidget(horizontalSplitter);


    bool releaseFlag = false;
    if(releaseFlag){
        this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    }

    this->show();
}

void MainWindow::handleSelectionChanged(int index)
{
    qInfo() << "Item:" << index << "was selected.";
}

MainWindow::~MainWindow()
{
}

