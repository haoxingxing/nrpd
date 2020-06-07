#ifndef HANDLER_H
#define HANDLER_H
#include "../httphelper.h"
namespace api {
	namespace v1
	{
		void handle(const httplib::Request& req, httplib::Response& res);

	};
};
#endif // HANDLER_H
