#ifndef CUSTOMFORM_H
#define CUSTOMFORM_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QFileDialog>

#include <vector>
#include <map>

class CustomForm : public QWidget{
    Q_OBJECT
public:
    explicit CustomForm(QWidget *parent = nullptr);
    ~CustomForm();

    void init(std::vector<QString> fieldNameList);
    std::map<QString,QString> getData();
    int getSizeOfFieldNameList();

private:
    QVBoxLayout* mainLayout;
    QFormLayout* fieldsLayout;

    std::vector<QLabel*> labelList;
    std::vector<QLineEdit*> lineEditList;
    QPushButton* pushButtonOK;

    std::vector<QString> fieldNameList;
    std::map<QString,QString> data;

    QFileDialog *fileDialog;


public slots:
    void onButtonOkPush();
    void onButtonPhotoClicked();
    void onFileSelected(const QString &);

signals:
    void onDataReady();
};

#endif // CUSTOMFORM_H
