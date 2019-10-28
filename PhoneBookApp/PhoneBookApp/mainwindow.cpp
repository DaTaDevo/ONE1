#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStatusBar>
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->deleteButton->setEnabled(false);
    connect(this,SIGNAL(dataChanged()),this,SLOT(refillList()));
    emit dataChanged();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_closeButton_clicked()
{
    close();
}

void MainWindow::on_addButton_clicked()
{
    AddDialogWindow adw(this);
    adw.show();
    Model tempModel(adw.name.toStdString(),adw.num.toStdString());
    this->cntrl.addModel(&tempModel);
    emit dataChanged();
    adw.exec();

}

void MainWindow::on_listContact_clicked(const QModelIndex &index)
{
    ui->deleteButton->setEnabled(true);
}

void MainWindow::on_deleteButton_clicked()
{
    QModelIndex index = ui->listContact->currentIndex();
    QString text = index.data().toString();
    statusBar()->showMessage(text);
    emit dataChanged();
}
void MainWindow::refillList()
{
    if(cntrl.size() == 0)
    {
        statusBar()->showMessage("Storage is empty");
    }
    else
    {
        for(unsigned int i = 0;i< cntrl.size();i++)
        {
            Model temp = cntrl.getModel(i);
            QStringListModel *model = new QStringListModel(this);
            std::string data = cntrl.getName() + "\t" + cntrl.getName();
            QString qData = QString::fromStdString(data);
            QStringList text;
            text <<qData;
            model->setStringList(text);
            ui->listContact->setModel(model);
            ui->listContact->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }
    }
}
