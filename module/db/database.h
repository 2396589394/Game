#ifndef __DATABASE_H__
#define __DATABASE_H__

#include "dbConfig.h"
#include <mysql/mysql.h>
#include <hiredis/hiredis.h>

class Database
{
private:
	static MYSQL* mysql_;
	static redisContext* redis_;

public:
	Database() = delete;
	~Database() = delete;

	static void init(DbConfig& config);
	static void finit();
};

#endif