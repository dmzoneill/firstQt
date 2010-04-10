#ifndef DB_H
#define DB_H

#include <iostream>
#include <QtSql>

#define DRIVER       "QMYSQL"
#define DATABASE     "elearning"
#define USER         "CS4313_G5"
#define PASSWORD     "ghbn56"
#define HOST         "localhost"

using std::string;


class DB
{
    private:
        QSqlDatabase db;
        QString result;        
        QString error;

    public:
        DB();
        bool open();
        void doQuery(QString sql);
        QString getResult();
        QString getError();

};

#endif // DB_H
