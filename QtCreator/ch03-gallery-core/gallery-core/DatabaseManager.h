#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include "AlbumDBao.h"
#include "PictureDBao.h"
#include <QString>

// separated queries/insert (AlbumDBao) from  connection (DatabaseManager)!!

// Manage dependencies - application indep of data implement
class QSqlDatabase; // forward dec no need for header - do not want multiple inclusions - want application not to depend on it

const QString DATABASE_FILENAME = "gallery.db";

// SINGLETON PATTERN
class DatabaseManager
{
public:
    // DatabaseManager(); - no public CTOR
    static DatabaseManager& instance();
    ~DatabaseManager();
protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);
public:
    // this encapsulates the actual queries/inserts
    // from outside DatabaseManager::instance().albumDao
    const AlbumDBao albumDBao;
    const PictureDBao pictureDBao;
private:
    // <QSqlDatabase> - resources - connection field - mDatabase(new QSqlDatabase)
    QSqlDatabase* mDatabase;
};

#endif // DATABASEMANAGER_H
