#ifndef __REDIS_H__
#define __REDIS_H__

#include "redisConfig.h"
#include <hiredis/hiredis.h>

class Redis
{
private:
	static redisContext* redis_;

public:
	Redis() = delete;
	~Redis() = delete;

	static void init(RedisConfig& config);
	static void finit();
};

#endif