#ifndef _GAME_H
#define _GAME_H
#include <QVector2D>
#include <QSize>
#include <QPixmap>

class Game {
      QSize size;
      QVector2D position[16];
      QVector2D velocity[16];
      QVector2D gravity;
      double tau;
      double radius;
      QPixmap *texture_ball[16];
      QPixmap *table;
      friend class MainWindow;
public:
      Game();
      ~Game();
      void step();
      void draw(QPixmap *pixmap);
};

#endif
