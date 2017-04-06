#include "AlbumDBao.h"
// Add includes
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "DatabaseManager.h"
#include "Album.h"

// CRUD
// in DatabaseManager.cpp: albumDBao(*mDatabase) => QSqlDatabase* mDatabase is
// mDatabase(new QSqlDatabase)
AlbumDBao::AlbumDBao(QSqlDatabase &database) : mDatabase(database)
{
}

// CREATE (table)
void AlbumDBao::init() const
{
    if ( !mDatabase.tables().contains("albums") )
    {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE albums (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
    }
}
// UPDATE (table)
void AlbumDBao::addAlbum(Album& album) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO albums (name) VALUES (:name)"); // :oracle ?ODBC
    query.bindValue(":name", album.getName()); // expects QVariant
    query.exec();
    album.setId(query.lastInsertId().toInt());
}

void AlbumDBao::updateAlbum(const Album& album) const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE albums SET name = (:name) WHERE id = (:id)");
    query.bindValue(":name", album.getName());
    query.bindValue(":id", album.getId());
    query.exec();
}

void AlbumDBao::removeAlbum(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM albums WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

QVector<Album*> AlbumDBao::getAlbums() const
{
    QSqlQuery query("SELECT * FROM albums", mDatabase);
    query.exec();
    // name is now title
    QVector<Album*> list;
    while(query.next()) {
        Album* album = new Album();
        album->setId(query.value("id").toInt());
        album->setName(query.value("name").toString()); // throws exception!! Memory leak!!
        // try catch - except delete album ? need delete
        // who is oowner ? who must dealloc
        // retain or release to callee
        // So SMART pointer - explicitly indicate OWNERSHIP
        // oon stack
        list.append(album);
    }
    return list;
}



