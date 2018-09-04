#include "redis.h"
#include <errno.h>
#include "log/log.h"

redisContext* Redis::redis_

void Redis::init(RedisConfig& config)
{
	Redis::redis_ = redisAsyncConnect(config.address, config.port);
	if(Redis::redis_->err)
	{
		Log::printf_error("Errno: %d, Redis connect fail", errno);
	}
}

void Redis::finit()
{
	redisFree(Redis::redis_);
}