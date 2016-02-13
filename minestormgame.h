#ifndef MINESTORMGAME_H
#define MINESTORMGAME_H

#include <QPainter>
#include <QMessageBox>
#include "game.h"

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

    private:

        virtual void step();
        void initialize();

};

#endif // MINESTORMGAME_H
