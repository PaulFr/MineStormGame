#ifndef MINESTORMGAME_H
#define MINESTORMGAME_H

#include <QPainter>
#include <QMessageBox>
#include "game.h"
#include "spaceship.h"
#include "mine.h"

using namespace std;

class MineStormGame : public Game
{
    Q_OBJECT
    public:
        MineStormGame(const QSize &size,QObject *parent = nullptr);
        virtual void draw(QPainter &painter, QRect &rect) override;
        void mousePressed( int x, int y) override;
        void keyPressed( int key ) override;
        void keyReleased( int key ) override;
        void mouseReleased( int x, int y) override;
        void mouseMoved(int x, int y) override;
        ~MineStormGame();
        bool keyHandler(int key, bool isPressed);
private:

        virtual void step();
        void initialize();
        Spaceship *_spaceship;
        Mine *_mine;
        bool _keyLeft = false;
        bool _keyRight = false;
        bool _keyUp = false;
        bool _keyDown = false;
        bool _keySpace = false;

};

#endif // MINESTORMGAME_H
