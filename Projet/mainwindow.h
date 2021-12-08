#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>

#include <map>

#include <customform.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
    void onContactFormComplete();
    void onInteractionFormComplete();

    void onQActionContactClicked();
    void onQActionInteractionClicked();
};

#endif // MAINWINDOW_H
