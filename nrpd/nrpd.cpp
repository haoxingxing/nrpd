// nrpd.cpp: 定义应用程序的入口点。
//

#include "nrpd.h"

using namespace std;
using namespace httplib;
std::string dump_headers(const Headers& headers) {
    std::string s;
    char buf[BUFSIZ];

    for (auto it = headers.begin(); it != headers.end(); ++it) {
        const auto& x = *it;
        snprintf(buf, sizeof(buf), "%s: %s\n", x.first.c_str(), x.second.c_str());
        s += buf;
    }

    return s;
}

int main()
{
    Server svr;
    svr.Get(".*", [](const Request& req, Response& res) {
        httphelper::logger::logreq(req);
        res.set_content(dump_headers(req.headers), "text/plain");
        });
    svr.listen("localhost", 8080);
	return 0;
}
