#include "Handler.h"

void api::v1::handle(const httplib::Request& req, httplib::Response& res)
{
	res.set_content(req.path, "text/plain");
}
