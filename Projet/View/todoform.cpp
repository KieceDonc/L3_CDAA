#include "todoform.h"
#include "ui_todoform.h"

TodoForm::TodoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TodoForm)
{
    this-
}

TodoForm::~TodoForm()
{
    delete ui;
}
