#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>

#include <QToolBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    table = new QTableWidget (this);
    setCentralWidget(table);
    setWindowTitle("PasswordManager");
    setWindowIcon(QIcon("padlock_color"));
    //setSizePolicy()
   // ui->mainToolBar->del
    table->setRowCount(15);
    table->setColumnCount(2);
    table->setColumnWidth(0, 5);
    table->setRowHeight(2, 2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
