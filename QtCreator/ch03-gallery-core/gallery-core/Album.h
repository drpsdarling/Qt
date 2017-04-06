#ifndef ALBUM_H
#define ALBUM_H
// Added bby gnul
#include <QString>
#include "gallery-core_global.h"

class GALLERYCORESHARED_EXPORT Album
{

public:
    // gnul add explicit and name
    explicit Album( const QString& name = "");
    // gnul adds these member functions
    int  getId() const;
    void setId(int id);
    QString getName() const;
    void setName(const QString& name);
// gnul add private data members
private:
    int mId; // Database ID
    QString mName;
    // Decouple Picture and Album
    // QVector<Picture>mPictures
};

#endif // ALBUM_H
