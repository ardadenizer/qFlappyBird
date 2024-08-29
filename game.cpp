#include "game.h"

Game::Game() : m_isGameRunning(false)
{
    m_pGameTimer = std::make_unique<QTimer>(this);
    connect(m_pGameTimer.get(), &QTimer::timeout, this, &Game::gameLoop);
}

void Game::initialize()
{
    /*------------------------------------------- WINDOW INITIALIZE [START]------------------------------------------------------ */

    m_pGamePlayWindow = std::make_unique<QMainWindow>();

    m_pGamePlayWindow->setStyleSheet("QMainWindow { background-image: url('../../Assets/background.png'); background-position: center; background-repeat: no-repeat; }");
    m_pGamePlayWindow->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT); // Set window size
    m_pGamePlayWindow->show();

    /*------------------------------------------- WINDOW INITIALIZE [END]------------------------------------------------------ */

    /*------------------------------------------- ENTITY INITIALIZE [START]------------------------------------------------------ */

    m_pBird   =   std::make_unique<Bird> (m_pGamePlayWindow.get(), BIRD_X_POS, BIRD_Y_POS); // deleted when game is over.

    m_pPillar =   std::make_unique<Pillar>(m_pGamePlayWindow.get());

    /*------------------------------------------- ENTITY INITIALIZE [END]------------------------------------------------------ */

    run();
}


void Game::run()
{
    m_isGameRunning = true;
    int frameInterval = 16;  // Approximately 60 FPS (1000ms / 60 ≈ 16.67ms)
    m_pGameTimer->start(frameInterval);  // Starts the timer
}

void Game::pause()
{
    m_isGameRunning = false;
    m_pGameTimer->stop();  // Stops the timer
}

void Game::end()
{
    m_isGameRunning = false;
    m_pGameTimer->stop();  // Stops the timer
}

void Game::gameLoop()
{
    if (!m_isGameRunning) return;

    // Handle collisions, score updates, etc.

    // Render the updated frame (typically handled by Qt's event loop)
    m_pGamePlayWindow->update();  // This would trigger a repaint of the window
}
