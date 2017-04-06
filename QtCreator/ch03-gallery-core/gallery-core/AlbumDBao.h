#ifndef ALBUMDBAO_H
#define ALBUMDBAO_H
#include <QVector>

class QSqlDatabase; // fwd declaration
class Album; // fwd dec

class AlbumDBao
{
public:
    // ctor via DB connection
    AlbumDBao(QSqlDatabase& database); // <QSqlDatabase>
    // create albums table
    void init() const;
    void addAlbum(Album& album) const;
    void updateAlbum(const Album& album) const;
    void removeAlbum(int id) const;
    QVector<Album*> getAlbums() const;
private:
    // REF (alias to obj) cf DatabaseManager (pointer) mDatabase(new QSqlDatabase)
    QSqlDatabase& mDatabase;
};

#endif // ALBUMDBAO_H
