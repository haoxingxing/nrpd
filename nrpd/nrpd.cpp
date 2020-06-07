// nrpd.cpp: 定义应用程序的入口点。
//

#include "nrpd.h"

using namespace std;
using namespace httplib;
int main()
{
    Server svr;

    svr.Get("/hi", [](const Request& /*req*/, Response& res) {
        res.set_content("Hello World!", "text/plain");
        });

    svr.listen("localhost", 8080);
	return 0;
}
