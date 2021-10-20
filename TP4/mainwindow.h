#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personne.h"
#include "QDebug"
#include "QMessageBox"
#include "QTimer"
#include "QTime"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slot_aPropos();

private slots:
    void on_pushButton_clicked();
    void updateQTimer();

private:
    bool buttonAlreadyClicked;
    Ui::MainWindow *ui;
    Personne * personne;
    QTimer * qTimer;
};

#endif // MAINWINDOW_H
