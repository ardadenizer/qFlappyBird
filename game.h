#ifndef GAME_H
#define GAME_H

#include <QTimer>
#include <QMainWindow>
#include <QApplication>
#include <memory.h>
#include "bird.h"
#include "pillar.h"

class Game : public QObject
{
    Q_OBJECT

    private:
        bool m_isGameRunning;
        uint32_t m_score;
        std::unique_ptr<QTimer> m_pGameTimer;
        std::unique_ptr<Bird> m_pBird;
        std::unique_ptr<Pillar> m_pPillar;
        std::unique_ptr<QMainWindow> m_pGamePlayWindow;

    public:
        Game();
        void initialize();
        void destroy();
        void handle();
        void detectCollision();
        void gameLoop();

        // These APIs based on QTimer object
        void run();
        void pause();
        void end();
};

#endif // GAME_H
