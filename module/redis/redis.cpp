#include "redis.h"
#include <errno.h>
#include "log/log.h"

redisContext* Redis::redis_;

bool Redis::init(RedisConfig& config)
{
	Redis::redis_ = redisConnect(config.address, config.port);
	if(Redis::redis_->err)
	{
		Log::printf_error("Errno: %d, Redis connect fail", errno);
		return false;
	}

	return true;
}

void Redis::finit()
{
	redisFree(Redis::redis_);
}

void* Redis::command(const char* format, ...)
{
	va_list marker;
    va_start(marker, format);
	
	void* result = redisCommand(Redis::redis_, format, marker);

	va_end(marker);

	return result;
}
