#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>

#include <map>

#include <customform.h>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    CustomForm* contactForm;
    CustomForm* interactionForm;
    CustomForm* currentForm;

private:
    Ui::MainWindow *ui;

public slots:
    void onFormComplete();

    void onQActionContactClicked();
    void onQActionInteractionClicked();
};

#endif // MAINWINDOW_H
