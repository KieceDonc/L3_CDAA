#ifndef JSONFORM_H
#define JSONFORM_H

#include <QWidget>
#include <qfiledialog.h>

namespace Ui {
class JsonForm;
}

class JsonForm : public QWidget
{
    Q_OBJECT

public:
    explicit JsonForm(QWidget *parent = nullptr);
    ~JsonForm();

    QFileDialog * fileDialog;

public slots:
    void onButtonChooseClicked();


private:
    Ui::JsonForm *ui;

};

#endif // JSONFORM_H
