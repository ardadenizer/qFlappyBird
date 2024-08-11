#include <QMainWindow>
#include <QApplication>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow window;
    window.setStyleSheet("QMainWindow { background-image: url('../../Assets/background.png'); background-position: center; background-repeat: no-repeat; }");
    window.resize(800, 600); // Set window size
    window.show();
    return app.exec();
}
