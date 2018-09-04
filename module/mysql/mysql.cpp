#include "mysql.h"
#include <errno.h>
#include "log/log.h"

MYSQL* Mysql::mysql_;

void Mysql::init(MysqlConfig& config)
{
	mysql_init(Mysql::mysql_);
	mysql_real_connect(Mysql::mysql_, config.address, config.user, config.passwd, config.db, config.port, 0, 0);
	if(!Mysql::mysql_)
	{
		Log::printf_error("Errno: %d, Mysql connect fail", errno);
	}
}

void Mysql::finit()
{
	mysql_close(Mysql::mysql_);
}