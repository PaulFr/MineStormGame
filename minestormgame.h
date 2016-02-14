#ifndef MINESTORMGAME_H
#define MINESTORMGAME_H

#define MINE_SMALL 8
#define MINE_AVERAGE 13
#define MINE_BIG 20
#define BURST_LIFETIME 40
#define BULLET_LIFETIME 30
#define BULLET_SPEED 15
#define TIME_BEFORE_RESPAWN 60
#define PLAYER_LIVES 4

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
        /**
         * @brief createBurst : create a new burst explosion
         * @param position : position of the burst
         */
        void createBurst(QPoint position);
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
        bool _playerAlive = true;
        int _lastFire = 0;
        int _lives;
        int _counterBeforeRespawn = 0;
        int _score = 0;
        vector<Mine> _mines;
        vector<Bullet> _bullets;
        vector<Burst> _bursts;
};

#endif // MINESTORMGAME_H
