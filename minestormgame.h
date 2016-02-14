#ifndef MINESTORMGAME_H
#define MINESTORMGAME_H

#include <QPainter>
#include <QMessageBox>
#include <vector>
#include "game.h"
#include "spaceship.h"
#include "mine.h"
#include "bullet.h"
#include "burst.h"
#include <random>

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
        /**
         * @brief keyHandler : Manage the game keys inputs
         * @param key pressed
         * @param isPressed is the key pressed or released?
         * @return
         */
        bool keyHandler(int key, bool isPressed);
        /**
         * @brief spawnMines : Randomly creates mines
         * @param size : size of the mines
         * @param nbItem : amount of mines
         */
        void spawnMines(int size, int nbItem);
protected:
        /**
         * @brief fireBullet : creates a bullet fired by the spaceship
         */
        void fireBullet();
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
        int _lastFire = 0;
        vector<Mine> _mines;
        vector<Bullet> _bullets;
        vector<Burst> _bursts;
};

#endif // MINESTORMGAME_H
