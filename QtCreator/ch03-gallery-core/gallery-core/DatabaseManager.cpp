#include "DatabaseManager.h"

#include <QSqlDatabase>
#include <QDebug>

// DATABASE LAYER
// Single entry point

// Test
// #include "DatabaseManager.h"
// Test
// DATA CLASS
// DatabaseManager db1; - cannot access protected member
// DatabaseManager db1 = DatabaseManager::instance(); OK
// separated queries from  connection!!

DatabaseManager&DatabaseManager::instance()
{
    qDebug() << "DatabaseManager::instance()";
    qDebug() << "create singleton object";
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::DatabaseManager(const QString& path) : mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
                                                        albumDBao(*mDatabase), // dereferenced pointer is object
                                                        pictureDBao(*mDatabase)
{
    qDebug() << "DatabaseManager CTOR - open() dB";
    mDatabase->setDatabaseName(path);
    mDatabase->open();
    // make an abstract Dao class - PV init() - map to string - for loop - registry
    albumDBao.init(); // albumDBao contains actual queries
    pictureDBao.init();
}

DatabaseManager::~DatabaseManager()
{
    mDatabase->close(); // like delete
}

// const AlbumDBao albumDBao;

