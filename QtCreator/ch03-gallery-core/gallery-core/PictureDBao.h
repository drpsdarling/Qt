#ifndef PICTUREDBAO_H
#define PICTUREDBAO_H
#include <QVector>
// FK to PK Album

class QSqlDatabase;
class Picture;

class PictureDBao
{
public:
    explicit PictureDBao(QSqlDatabase& database);
    void init() const;

    void addPictureInAlbum(int albumId, Picture& picture) const;
    void removePicture(int id) const;
    void removePicturesForAlbum(int albumId) const;
    QVector<Picture*> picturesForAlbum(int albumId) const;

    private:
        QSqlDatabase& mDatabase;
};

#endif // PICTUREDBAO_H
