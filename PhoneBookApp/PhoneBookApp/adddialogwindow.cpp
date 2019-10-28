#include "adddialogwindow.h"
#include "ui_adddialogwindow.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
AddDialogWindow::AddDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialogWindow)
{
    ui->setupUi(this);
    ui->adw_saveButton->setEnabled(false);
    QRegExp regName("[a-zA-z]{1,10}[0-9]{0}");
    QRegExp regNumber("[+]{1}[0-9]{12}");
//    QRegExpValidator valName;
//    valName.setRegExp(regName);
    ui->adw_nameLine->setValidator(new QRegExpValidator(regName,this));
    ui->adw_numberLine->setValidator(new QRegExpValidator(regNumber,this));
    connect(ui->adw_numberLine,SIGNAL(textChanged(QString)),this,SLOT(saveEnabled()));

}
void AddDialogWindow::saveEnabled()
{
    ui->adw_saveButton->setEnabled(ui->adw_nameLine->hasAcceptableInput() && ui->adw_numberLine->hasAcceptableInput());
}
AddDialogWindow::~AddDialogWindow()
{
    delete ui;
}

void AddDialogWindow::on_adw_clsoeButton_clicked()
{
    reject();
}

void AddDialogWindow::on_adw_saveButton_clicked()
{
    name = ui->adw_nameLine->text();
    num  = ui->adw_numberLine->text();
    accept();
}
