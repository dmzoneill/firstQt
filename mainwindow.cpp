#include "mainwindow.h"
#include <QtGui/QTableView>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setPlainText("select * from serial where id<100");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;

        default:
            break;
    }
}


void MainWindow::clickedSqlQueryButton()
{
    DB * j = new DB();
    QString query = ui->plainTextEdit->toPlainText();
    if(j->open())
    {
        j->doQuery(query);
        QString qstr = j->getResult();
        ui->textEdit->setText(qstr);
        qDebug() << " open";
    }
    else
    {
        qDebug() << j->getError() << " not open";
    }
}


void MainWindow::clickedCurlButton()
{
    CurlFetch * curl = new CurlFetch();
    QString fetch = QString::fromStdString(curl->getResult());
    ui->textEdit->setPlainText(fetch);
}


int MainWindow::findPos(QString c, QString l)
{
    int f = -1;

    for(int y = 0 ; y < c.length() && l.length() && f==-1; y++)
    {
        if(c[y] != l[y])
        {
            f = y;
        }
    }

    if(c.length() > l.length() && f==-1)
        f = c.length();

    return f;
}


QString MainWindow::getPreviousWord(int pos, QString sql)
{
    QString lastWord = "";
    QString left = sql.left( pos + 1 );

    if(left.contains(' ',Qt::CaseSensitive))
    {
        QStringList lefttree = left.split(' ',QString::KeepEmptyParts,Qt::CaseSensitive);
        bool found = false;

        for(int j = lefttree.length() -1; j >= 0 && found == false; j--)
        {
            if(lefttree[j].length() > 0)
            {
                found = true;
                lastWord = lefttree[j];
            }
        }
    }
    else
    {
        lastWord = left;
    }
    return lastWord;
}


void MainWindow::sqlInputChanged()
{
    QString sql = ui->plainTextEdit->toPlainText();
    QStringList list = sql.split(' ',QString::KeepEmptyParts,Qt::CaseSensitive);

    int cIndex = this->findPos( sql , previousSql );

    if(cIndex > -1)
    {
        if(sql[cIndex - 1] == ' ' && sql[cIndex] == ' ')
        {
            QString previousWord = this->getPreviousWord( cIndex , sql );
        }
        else if(sql[cIndex] == ' ')
        {
            QString previousWord = this->getPreviousWord( cIndex , sql );
        }
        else
        {
            // do nothing
        }
    }

    this->previousList = ui->plainTextEdit->toPlainText().split(' ',QString::KeepEmptyParts,Qt::CaseSensitive);
    this->previousSql = ui->plainTextEdit->toPlainText();
}
