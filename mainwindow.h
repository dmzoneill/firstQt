#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSql>
#include <QMainWindow>
#include "db.h"
#include "curlfetch.h"


namespace Ui {
    class MainWindow;
}

class QListBox;
class QListBoxItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    public slots:
        void clickedSqlQueryButton();
        void clickedCurlButton();
        void sqlInputChanged();

    protected:
        void changeEvent(QEvent *e);

    private:
        Ui::MainWindow *ui;
        QStringList previousList;
        QString previousSql;
        int findPos(QString c, QString l);
        QString getPreviousWord(int pos, QString sql);


};

#endif // MAINWINDOW_H
