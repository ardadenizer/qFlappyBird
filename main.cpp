#include <QMainWindow>
#include <QApplication>
#include <Qlabel>
#include <QPixmap>
#include <QKeyEvent>
#include <QTime>
#include "bird.h"

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
    window.setFixedSize(800, 600); // Set window size
    window.show();

    /* Initialization of bird object */
    Bird* p_bird = nullptr;
    p_bird = new Bird(&window); // deleted when game is over.

    QPixmap birdPixMap;
    if (birdPixMap.load("../../Assets/bird.png")) {
        qDebug() << "Bird image is loaded!";
    } else {
        qDebug() << "Failed to load bird image.";
    }

    // Bird spwaning location:
    p_bird->setPosX(0);
    p_bird->setPosY(300);

    birdPixMap = birdPixMap.scaled(100, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    p_bird->setPixmap(birdPixMap);
    p_bird->setGeometry(p_bird->getPosX(), p_bird->getPosY(), birdPixMap.width(), birdPixMap.height());
    p_bird->raise();
    p_bird->show();

    // Debugging output:
    qDebug() << "QLabel geometry:" << p_bird->geometry();
    qDebug() << "QLabel visible:" << p_bird->isVisible();

    p_bird->setFocusPolicy(Qt::StrongFocus);



    int result = app.exec();

    delete p_bird; // Clean up the QLabel when the application exits
    p_bird = nullptr;

    return result;
}
