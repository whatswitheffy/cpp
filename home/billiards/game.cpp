#include <QPainter>
#include <QColor>
#include <QDebug>
#include "game.h"
#include <time.h>
Game::Game() {
  size = QSize(1166, 606);
  table = new QPixmap("C:/Qt/billiard2/pictures/table.png");
  srand(time(0));
  for(int i = 0; i < 16;++i) {
      position[i] = QVector2D(0 + rand() % 1200, 0 + rand() % 600);
      velocity[i] = QVector2D(3000 + rand() % 5000 , 3000 + rand() % 5000);
      texture_ball[i] = new QPixmap("C:/Qt/billiard2/pictures/" + QString::number(i + 1) + ".png");
  }
  gravity = QVector2D(0.0, 0.0);
  tau = 0.0003;
  radius = 18.0;
}

void Game::step() {
    QVector2D vectorDistance;
    double length;
    QVector2D tg[2];
    QVector2D norm[2];
    QVector2D e;
    for(int i = 0; i < 16; ++i) {
        position[i] = position[i] + tau * velocity[i];
        velocity[i] = velocity[i] + tau * gravity;
    }
  QVector2D normal[] = { QVector2D(1, 0),
                         QVector2D(0, -1),
                         QVector2D(-1, 0),
                         QVector2D(0, 1) };
  QVector2D border[] = { QVector2D(radius + 58, radius + 58),
                         QVector2D(radius + 58, size.height() - radius + 58),
                         QVector2D(size.width() - radius + 58, size.height() - radius + 58),
                         QVector2D(size.width() - radius + 58, radius + 58)};
  for (int i = 0; i < 4; i++) {
      for(int j = 0; j < 16; ++j) {
          qreal normal_factor = QVector2D::dotProduct(position[j] - border[i], normal[i]);
          if (normal_factor < 0) {
            position[j] = position[j] - 2 * normal_factor * normal[i];
            velocity[j] = velocity[j] - 2 * QVector2D::dotProduct(velocity[j], normal[i]) * normal[i];
      }
           qDebug() << j;
           qDebug() << position[j] << velocity[j];
    }
  }
 for(int i = 0; i < 16; ++i) {
    for(int j = i + 1; j < 16; ++j) {
        vectorDistance = position[i] - position[j];
        length = vectorDistance.length();
        if(length <= radius * 2) {
            length = radius * 2 - length;
            e = vectorDistance.normalized();
            position[i] = position[i] + (e * length / 2);
            position[j] = position[j] + (-e * length / 2);
            norm[0] = QVector2D::dotProduct(velocity[i], e) * e ;
            tg[0] = velocity[i] - norm[0];
            norm[1] = QVector2D::dotProduct(velocity[j], e) * e ;
            tg[1] = velocity[j] - norm[1];
            velocity[i] = tg[0] + norm[1];
            velocity[j] = tg[1] + norm[0];
        }
    }
  }
}

void Game::draw(QPixmap *pixmap) {
  pixmap->load("C:/Qt/billiard2/pictures/table.png");
  QPainter painter(pixmap);
  for(int i = 0; i < 16; ++i) {
      painter.drawPixmap(position[i].x() - radius,
                         position[i].y() - radius,
                         *texture_ball[i]);
  }
}

Game::~Game() {
    for(int i = 0; i < 16; ++i) {
          delete texture_ball[i];
    }
}
