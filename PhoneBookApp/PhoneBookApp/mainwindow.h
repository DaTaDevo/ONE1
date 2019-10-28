#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <adddialogwindow.h>
#include <controller.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Controller cntrl;
    void print(std::string str);
private slots:
    void on_closeButton_clicked();
    void on_addButton_clicked();
    void on_listContact_clicked(const QModelIndex &index);
    void on_deleteButton_clicked();
    void refillList();
signals:
    void dataChanged();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
