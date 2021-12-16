#ifndef JSONFORM_H
#define JSONFORM_H

#include <QWidget>
#include <qfiledialog.h>


namespace Ui {
class JsonForm;
}

/**
 * @brief Widget allowing the user to chose a directory location to export a JSON file containing the informations about the contacts and their interactions.
 */
class JsonForm : public QWidget
{
    Q_OBJECT

public:
    explicit JsonForm(QWidget *parent = nullptr);
    ~JsonForm();

    QFileDialog * fileDialog;
    Ui::JsonForm *ui;

public slots:
    void onButtonChooseClicked();
    void onButtonOkClicked();

signals:
    void makeJson(const QString &);
};

#endif // JSONFORM_H
