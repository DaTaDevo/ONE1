#ifndef ADDDIALOGWINDOW_H
#define ADDDIALOGWINDOW_H

#include <QDialog>

namespace Ui {
class AddDialogWindow;
}

class AddDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialogWindow(QWidget *parent = nullptr);
    ~AddDialogWindow();
    QString name;
    QString num;

private slots:
    void saveEnabled();

    void on_adw_clsoeButton_clicked();

    void on_adw_saveButton_clicked();

private:
    Ui::AddDialogWindow *ui;
};

#endif // ADDDIALOGWINDOW_H
