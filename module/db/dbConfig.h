#ifndef __DB_CONFIG_H__
#define __DB_CONFIG_H__

struct DbConfig{
	char mysql_address[20];
	unsigned short mysql_port;
	char mysql_db_name[20];
	char mysql_user[20];
	char mysql_password[20];

	char redis_address[20];
	unsigned short redis_port;

	DbConfig(const char* configFile)
	{

	}
};

#endif