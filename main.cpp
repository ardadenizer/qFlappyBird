#include <QMainWindow>
#include <QApplication>
#include <Qlabel>
#include <QPixmap>
#include <QKeyEvent>
#include <QTime>
#include <QPropertyAnimation>
#include "bird.h"
#include "constants.h"

void delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QMainWindow window;

    window.setStyleSheet("QMainWindow { background-image: url('../../Assets/background.png'); background-position: center; background-repeat: no-repeat; }");
    window.setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT); // Set window size
    window.show();

    /* Initialization of bird object */
    Bird* p_bird = nullptr;
    p_bird = new Bird(&window, BIRD_X_POS, BIRD_Y_POS); // deleted when game is over.


    // QPropertyAnimation *animation = new QPropertyAnimation(p_bird, "geometry");
    // animation->setDuration(2000);  // Duration of 2 seconds
    // animation->setStartValue(QRect(0, 0, birdPixMap.width(), birdPixMap.height()));  // Start position and size
    // animation->setEndValue(QRect(600, 400, birdPixMap.width(), birdPixMap.height()));  // End position and size
    // animation->setEasingCurve(QEasingCurve::OutBounce);  // Easing curve for bounce effect

    // animation->start();  // Start the animation


    int result = app.exec();

    delete p_bird; // Clean up the QLabel when the application exits
    p_bird = nullptr;

    return result;
}
