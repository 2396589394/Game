#ifndef __MYSQL_CONFIG_H__
#define __MYSQL_CONFIG_H__

struct MysqlConfig{
	char address[20];
	unsigned short port;
	char db[20];
	char user[20];
	char password[20];

	MysqlConfig(const char* configFile)
	{

	}
};

#endif