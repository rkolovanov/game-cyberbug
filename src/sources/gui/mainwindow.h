#ifndef SOURCES_GUI_MAIN_WINDOW_H
#define SOURCES_GUI_MAIN_WINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QToolBar>
#include <QImage>
#include <QLabel>
#include <QMap>

#include "sources/game/gamecontroller.h"
#include "sources/gui/texture.h"
#include "sources/gui/commands/commandtype.h"
#include "sources/game/settings.h"
#include "sources/gui/commands/command.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

namespace gui {

using sharedMainWindowUi = std::shared_ptr<Ui::MainWindow>;
using sharedQGraphicsView = std::shared_ptr<QGraphicsView>;
using sharedQGraphicsScene = std::shared_ptr<QGraphicsScene>;
using sharedQPixmap = std::shared_ptr<QPixmap>;
using sharedQLabel = std::shared_ptr<QLabel>;
using sharedQToolBar = std::shared_ptr<QToolBar>;


class MainWindow final: public QMainWindow {
    Q_OBJECT

private:
    sharedMainWindowUi ui_;
    sharedQGraphicsView view_;
    sharedQGraphicsScene scene_;
    sharedQPixmap fieldPixelMap_;
    sharedQLabel levelLabel_;
    sharedQLabel healthLabel_;
    sharedQLabel maxHealthLabel_;
    sharedQLabel attackLabel_;
    sharedQLabel armorLabel_;
    QMap<CommandType, sharedCommand> commands_;
    logging::sharedLoggingListener logger_;
    game::sharedGameController controller_;
    bool screenPinning_ = false;
    bool isPressed_ = false;

public:
    MainWindow(const game::sharedGameController& controller, const logging::sharedLoggingListener& logger, QWidget* parent = nullptr);

    void updateScene(bool move_view = false);
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void quit();

private slots:
    void on_action_new_triggered();
    void on_action_save_triggered();
    void on_action_load_triggered();
    void on_action_exit_triggered();
}; // class MainWindow


}; // namespace gui


#endif // SOURCES_GUI_MAIN_WINDOW_H
