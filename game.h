#ifndef GAME_H
#define GAME_H

#include <QTimer>

class Game
{
private:
    bool isGameRunning;
    QTimer *gameTimer;

public:
    Game();
    void Initialize();

    // These APIs based on QTimer object
    void Run();
    void Pause();
    void End();
};

#endif // GAME_H
