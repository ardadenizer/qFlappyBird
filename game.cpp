#include "game.h"

Game::Game() {}

void Game::Initialize()
{
    m_pGamePlayWindow = std::make_unique<QMainWindow>();

    m_pGamePlayWindow->setStyleSheet("QMainWindow { background-image: url('../../Assets/background.png'); background-position: center; background-repeat: no-repeat; }");
    m_pGamePlayWindow->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT); // Set window size
    m_pGamePlayWindow->show();

    /* Initialization of bird object */
    m_pBird   =   std::make_unique<Bird> (m_pGamePlayWindow.get(), BIRD_X_POS, BIRD_Y_POS); // deleted when game is over.

    m_pPillar =   std::make_unique<Pillar>(m_pGamePlayWindow.get());
}


void Game::Destroy()
{

}
