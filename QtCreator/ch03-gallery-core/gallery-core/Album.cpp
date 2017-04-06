#include "Album.h"
// Test
// #include "DatabaseManager.h"
// Test
// DATA CLASS

Album::Album( const QString& name ) : mId(-1), mName(name)
{
    // DatabaseManager db1; - cannot access protected member
    // DatabaseManager db1 = DatabaseManager::instance(); OK
}

int Album::getId() const
{
    return mId;
}

void Album::setId(int id)
{
    mId = id;
}

QString Album::getName() const
{
    return mName;
}

void Album::setName(const QString& name)
{
    mName = name;
}

