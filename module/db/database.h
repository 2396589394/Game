#ifndef __DATABASE_H__
#define __DATABASE_H__

#include "dbConfig.h"

class Database
{
private:

public:
	Database(DbConfig& config);
	~Database();
};

#endif