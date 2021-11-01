#ifndef IHM_H
#define IHM_H

#include <QMainWindow>

namespace Ui {
class ihm;
}

class ihm : public QMainWindow
{
    Q_OBJECT

public:
    explicit ihm(QWidget *parent = nullptr);
    ~ihm();

private:
    Ui::ihm *ui;
};

#endif // IHM_H
