#include "db.h"

DB::DB()
{


}

bool DB::open()
{
    this->db = QSqlDatabase::addDatabase(DRIVER);
    this->db.setHostName(HOST);
    this->db.setDatabaseName(DATABASE);
    this->db.setUserName(USER);
    this->db.setPassword(PASSWORD);
    bool ok = this->db.open();

    qDebug() << this->db.driverName();

    if(!ok)
        this->error = this->db.lastError().text();

    return ok;
}


QString DB::getResult()
{
    return this->result;
}



void DB::doQuery(QString sql)
{
    if(this->db.isOpen())
    {
        QSqlDatabase::database().transaction();
        
        QSqlQuery query;

        if(query.exec(sql))
        {
            while (query.next())
            {
                 QString name = query.value(0).toString();
                 this->result = this->result + name + "\n";
                 //qDebug() << name << salary;
            }
        }
        else
        {
            this->result = "";
        }

        QSqlDatabase::database().commit();
    }
    else
    {
        qDebug() << "Not open ....";
    }
}


QString DB::getError()
{
    return this->error;
}
