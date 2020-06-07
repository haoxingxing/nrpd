#ifndef PLASTEBIN_H
#define PLASTEBIN_H
#include "../httphelper.h"
#include <map>
namespace api
{
	namespace v1 {
		namespace plastebin
		{

			inline void handle(const httplib::Request& req, httplib::Response& res)
			{
				static std::map<std::string, std::string> data;
				if (req.method == "POST")
				{
					data[req.path]=req.body;
					std::cout << req.path << " -> " << req.body << std::endl;
				}
				res.set_content(data.at(req.path), "text/plain");
			}

		}
	};
}
#endif // PLASTEBIN_H
