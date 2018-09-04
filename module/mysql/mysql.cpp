#include "mysql.h"
#include <errno.h>
#include "log/log.h"

MYSQL* Mysql::mysql_;

bool Mysql::init(MysqlConfig& config)
{
	mysql_init(Mysql::mysql_);
	mysql_real_connect(Mysql::mysql_, config.address, config.user, config.password, config.db, config.port, 0, 0);
	if(!Mysql::mysql_)
	{
		Log::printf_error("Errno: %d, mysql connect fail", errno);
		return false;
	}

	return true;
}

void Mysql::finit()
{
	mysql_close(Mysql::mysql_);
}

bool Mysql::query(MYSQL_RES* res, const char* format, ...)
{
	va_list marker;
    va_start(marker, format);

	char sql[100];
	sprintf(sql, format, marker);
	
	va_end(marker);

	if(!mysql_query(Mysql::mysql_, sql))
	{
		Log::printf_warn("Errno: %d, mysql anomaly", errno);
		return false;
	}

	res = mysql_store_result(Mysql::mysql_);
	
	return true;
}

bool Mysql::query(const char* format, ...)
{
	va_list marker;
    va_start(marker, format);

	char sql[100];
	sprintf(sql, format, marker);
	
	va_end(marker);

	if(!mysql_query(Mysql::mysql_, sql))
	{
		Log::printf_warn("Errno: %d, mysql anomaly", errno);
		return false;
	}

	return true;
}