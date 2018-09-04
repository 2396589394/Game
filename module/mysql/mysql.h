#ifndef __MYSQL_H__
#define __MYSQL_H__

#include "mysqlConfig.h"
#include <mysql/mysql.h>

class Mysql
{
private:
	static MYSQL* mysql_;

public:
	Mysql() = delete;
	~Mysql() = delete;

	static void init(MysqlConfig& config);
	static void finit();
};

#endif