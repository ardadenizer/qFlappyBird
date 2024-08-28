#include "game.h"

Game::Game() {}

void Game::Initialize()
{

    gamePlayWindow.setStyleSheet("QMainWindow { background-image: url('../../Assets/background.png'); background-position: center; background-repeat: no-repeat; }");
    gamePlayWindow.setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT); // Set window size
    gamePlayWindow.show();

    /* Initialization of bird object */
    m_pBird   =   std::make_unique<Bird> (&gamePlayWindow, BIRD_X_POS, BIRD_Y_POS); // deleted when game is over.

    m_pPillar =   std::make_unique<Pillar>(&gamePlayWindow);
}


void Game::Destroy()
{

}
