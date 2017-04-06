#ifndef PICTURE_H
#define PICTURE_H
// gnul add includes
#include <QUrl>
#include <QString>

#include "gallery-core_global.h"

class GALLERYCORESHARED_EXPORT Picture
{
public:
    Picture( const QString& filePath = "");
    Picture( const QUrl& fileUrl);

    int getId() const;
    void setId(int id);

    int getAlbumID() const;
    void setAlbumId( int albumId);
    QUrl getFileUrl() const;
    void setFileUrl(const QUrl& fileUrl);
private:
    int mId;
    int mAlbumId; // Picture belongs to this ID
    QUrl mFileUrl;
};

#endif // PICTURE_H
