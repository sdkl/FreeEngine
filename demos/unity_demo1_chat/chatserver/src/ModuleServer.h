/*
** Free game server engine
**
** Copyright (C) 2016 Eleven. See Copyright Notice in base.h
*/



#ifndef _US_MODULE_SERVER_
#define _US_MODULE_SERVER_

#include <vector>
#include <cinttypes>

#include "IModule.h"
#include "NetService.h"

namespace ff
{
	namespace demo
	{
		class ModuleServer : public ff::IModule, public ff::NetService::Listener
		{
		public:
			virtual bool initialize();
			virtual	void finalize();

		private:
			virtual void newconn(ff::NetService* net, int32_t id);
			virtual void lostconn(ff::NetService* net, int32_t id);
			virtual void recvdata(ff::NetService* net, int32_t id, const char* data, int32_t datalen);

		private:
			ff::NetService*		 mNet;
			std::vector<int32_t> mIds;
		};
	}
}

#endif
