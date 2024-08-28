#ifndef GAME_H
#define GAME_H

#include <QTimer>
#include <QMainWindow>
#include <QApplication>
#include <memory.h>
#include "bird.h"
#include "pillar.h"

class Game
{
private:
    bool isGameRunning;
    std::unique_ptr<QTimer> m_pGameTimer;
    std::unique_ptr<Bird> m_pBird;
    std::unique_ptr<Pillar> m_pPillar;
    std::unique_ptr<QMainWindow> m_pGamePlayWindow;

public:
    Game();
    void Initialize();
    void Destroy();

    // These APIs based on QTimer object
    void Run();
    void Pause();
    void End();
};

#endif // GAME_H
