#include <QMainWindow>
#include <QApplication>
#include <Qlabel>
#include <QPixmap>
#include <QKeyEvent>
#include <QTime>
#include <QPropertyAnimation>
#include "game.h"


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Game* GameInstance = new Game();
    GameInstance->Initialize();


    int result = app.exec();
    qDebug() << "Exit result: " << result;

    return result;
}
