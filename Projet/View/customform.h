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

/**
 * @brief Widget allowing the user to create a new contact by typing its different values (First name, etc...) and chosing a picture file.
 */
class CustomForm : public QWidget{
    Q_OBJECT
public:
    explicit CustomForm(QWidget *parent = nullptr);
    ~CustomForm();

    QVBoxLayout* mainLayout;
    QFormLayout* fieldsLayout;
    QPushButton* pushButtonOK;
    QFileDialog *fileDialog;

    std::vector<QLabel*> labelList;
    std::vector<QLineEdit*> lineEditList;
    std::vector<QString> fieldNameList;
    std::map<QString,QString> data;

    void init(std::vector<QString> fieldNameList);
    std::map<QString,QString> getData();
    int getSizeOfFieldNameList();


public slots:
    void onButtonOkPush();
    void onButtonPhotoClicked();

signals:
    void onDataReady();
};

#endif // CUSTOMFORM_H
