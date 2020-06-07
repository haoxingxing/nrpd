#ifndef HTTPHELPER_H
#define HTTPHELPER_H
#include "httplib.h"
#ifdef WIN32
#include "Windows.h"
#endif
namespace httphelper
{
	namespace logger {
		enum Level
		{
			ERR,
			WARN,
			INFO,
			DEBUG
		};
		void logreq(const httplib::Request& req, Level l = INFO)
		{
			if (l > WARN) {
				std::cout << "[" << req.remote_addr << "]" << ":" << req.remote_port <<  " " << req.version << " <" << req.method << ">" << req.path << "\n";
				if (l > DEBUG) {
					
					for (auto i = req.headers.begin(); i != req.headers.end(); ++i)
					{
						std::cout << i->first << ":" << i->second << "\n";
					}
				}
			}
		}
	}

}

#endif // HTTPHELPER_H
