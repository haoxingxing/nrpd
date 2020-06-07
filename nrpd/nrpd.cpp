#include "nrpd.h"
#include "../configs.h"
using namespace std;
using namespace httplib;


int main()
{
	Server svr;
	svr.set_logger(&httphelper::logger::log_handler);
    svr.listen(SERVER_ADDR, SERVER_PORT);
	
	return 0;
}
