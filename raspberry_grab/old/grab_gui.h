#ifndef GRAB_GUI_H
#define GRAB_GUI_H

#include <QMainWindow>

namespace Ui {
class grab_gui;
}

class grab_gui : public QMainWindow
{
    Q_OBJECT

public:
    explicit grab_gui(QWidget *parent = 0);
    ~grab_gui();
    QPixmap * pix;
    struct video_dev * pvd;


private slots:
    void on_grabButton_clicked();

private:
    Ui::grab_gui *ui;
};

#endif // GRAB_GUI_H
