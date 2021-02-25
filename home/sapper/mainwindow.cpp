#include "mainwindow.h"
MainWindow::MainWindow(QWidget * parent) :
            QMainWindow(parent) {
    resize (500 , 500);
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    layout = new QGridLayout(centralWidget);
    int size = 5;
    fields.resize(size);
    for(int i = 0; i < size; ++i) {
        fields[i].resize(size);
        for (int j = 0; j < size ; ++j) {
            Field *newfield = new Field(i, j , this);
            newfield->setText("*");
            fields[i][j] = newfield;
            layout->addWidget(newfield, i, j);
            connect(newfield, SIGNAL (moved(int, int)),
            this, SLOT(movehandler(int, int)));
        }
    }
}
MainWindow::~MainWindow() {
    for(int i = 0; i < fields.size(); ++i) {
        for(int j = 0; j < fields.size(); ++j) {
            delete fields[i][j];
        }
        fields[i].clear();
    }
    fields.clear();
    delete layout;
    delete centralWidget;
}

void MainWindow::movehandler(int row, int col) {
    qDebug() << row << col;
    fields[row][col]->setText("PRESSED");
    fields[row][col]->setEnabled(false);
}
