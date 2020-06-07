#include "nrpd.h"
#include "../configs.h"
#include "v1/Handler.h"
#include "v1/plastebin.h"
using namespace std;
using namespace httplib;

#define ROUTE_ALL(svr, reg,handle)\
svr.Get(reg, handle); \
svr.Delete(reg, handle); \
svr.Options(reg, handle); \
svr.Post(reg, handle); \
svr.Patch(reg, handle); \
svr.Put(reg, handle); 

int main()
{
	Server svr;
	svr.set_logger(&httphelper::logger::log_handler);
	ROUTE_ALL(svr, "/v1/plastebin/.*", &api::v1::plastebin::handle);
	svr.listen(SERVER_ADDR, SERVER_PORT);
	return 0;
}
