#ifndef __REDIS_CONFIG_H__
#define __REDIS_CONFIG_H__

struct RedisConfig{
	char address[20];
	unsigned short port;

	RedisConfig(const char* configFile)
	{

	}
};

#endif