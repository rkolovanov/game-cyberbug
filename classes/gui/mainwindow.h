#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QImage>
#include <QLabel>
#include <QMap>
#include "classes/game/gamecontroller.h"
#include "classes/enumerations/texture.h"
#include "classes/enumerations/commandtype.h"
#include "classes/common/settings.h"
#include "classes/game/commands/command.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

typedef std::shared_ptr<Ui::MainWindow> pMainWindowUi;
typedef std::shared_ptr<QGraphicsView> pQGraphicsView;
typedef std::shared_ptr<QGraphicsScene> pQGraphicsScene;
typedef std::shared_ptr<QPixmap> pQPixmap;
typedef std::shared_ptr<QLabel> pQLabel;


class MainWindow: public QMainWindow {
    Q_OBJECT

private:
    pMainWindowUi ui_;
    pQGraphicsView view_;
    pQGraphicsScene scene_;
    pQPixmap fieldPixelMap_;
    pQLabel levelLabel_;
    pQLabel healthLabel_;
    pQLabel attackLabel_;
    pQLabel armorLabel_;
    QMap<CommandType, pCommand> commands_;
    pLoggingListener logger_;
    pGameController controller_;
    bool screenPinning_ = false;
    bool isPressed_ = false;

public:
    MainWindow(pGameController& controller, pLoggingListener& logger, QWidget* parent = nullptr);
    void updateScene();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
};


#endif // MAIN_WINDOW_H
