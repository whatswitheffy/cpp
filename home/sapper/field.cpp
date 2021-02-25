#include "field.h"
#include <QDebug>
Field::Field(int row , int col , QWidget * parent)
    :QPushButton(parent) , row(row), col(col) {
    qDebug() << " CONSTRUCTOR " ;
    connect(this, SIGNAL ( clicked ()),
    this, SLOT (clickhandler()));
}

void Field::clickhandler() {
 emit moved(row, col);
}
