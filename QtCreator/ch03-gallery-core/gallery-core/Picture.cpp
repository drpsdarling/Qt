#include "Picture.h"
// DATA CLASS
// Calling other ctor - C++11
// Static function fromLocalFile

Picture::Picture(const QString& filePath) : Picture(QUrl::fromLocalFile(filePath))
{
}

Picture::Picture(const QUrl& fileUrl) : mId(-1), mAlbumId(-1), mFileUrl(fileUrl)
{
}

int Picture::getId() const
{
    return mId;
}

void Picture::setId(int id)
{
    mId = id;
}

int Picture::getAlbumID() const
{
    return mAlbumId;
}

void Picture::setAlbumId(int albumId)
{
    mAlbumId = albumId;
}

QUrl Picture::getFileUrl() const
{
  return mFileUrl;
}

void Picture::setFileUrl(const QUrl& fileUrl)
{
    mFileUrl = fileUrl;
}
