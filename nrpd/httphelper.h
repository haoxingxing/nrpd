#ifndef HTTPHELPER_H
#define HTTPHELPER_H
#include "../configs.h"
#include "lib/httplib.h"
#ifdef WIN32
#include "Windows.h"
#endif
namespace httphelper
{
	std::string dump_headers(const httplib::Headers& headers) {
		std::string s;
		char buf[BUFSIZ];

		for (auto it = headers.begin(); it != headers.end(); ++it) {
			const auto& x = *it;
			snprintf(buf, sizeof(buf), "%s: %s\n", x.first.c_str(), x.second.c_str());
			s += buf;
		}

		return s;
	}

	std::string dump_multipart_files(const httplib::MultipartFormDataMap& files) {
		std::string s;
		char buf[BUFSIZ];

		s += "--------------------------------\n";

		for (const auto& x : files) {
			const auto& name = x.first;
			const auto& file = x.second;

			snprintf(buf, sizeof(buf), "name: %s\n", name.c_str());
			s += buf;

			snprintf(buf, sizeof(buf), "filename: %s\n", file.filename.c_str());
			s += buf;

			snprintf(buf, sizeof(buf), "content type: %s\n", file.content_type.c_str());
			s += buf;

			snprintf(buf, sizeof(buf), "text length: %lu\n", file.content.size());
			s += buf;

			s += "----------------\n";
		}

		return s;
	}

	namespace logger {
		enum Level
		{
			ERR,
			WARN,
			INFO,
			DEBUG
		};

		std::string log(const httplib::Request& req, const httplib::Response& res) {
			std::string s;
			char buf[BUFSIZ];

			s += "================================\n";

			snprintf(buf, sizeof(buf), "%s %s %s", req.method.c_str(),
				req.version.c_str(), req.path.c_str());
			s += buf;

			std::string query;
			for (auto it = req.params.begin(); it != req.params.end(); ++it) {
				const auto& x = *it;
				snprintf(buf, sizeof(buf), "%c%s=%s",
					(it == req.params.begin()) ? '?' : '&', x.first.c_str(),
					x.second.c_str());
				query += buf;
			}
			snprintf(buf, sizeof(buf), "%s\n", query.c_str());
			s += buf;

			s += dump_headers(req.headers);
			s += dump_multipart_files(req.files);

			s += "--------------------------------\n";

			snprintf(buf, sizeof(buf), "Status: %d\n", res.status);
			s += buf;
			s += dump_headers(res.headers);
			s += "================================\n";

			return s;
		}
		void logreq(const httplib::Request& req, const httplib::Response& res, Level l = INFO)
		{
			if (l > WARN) {
				std::cout << "[" << req.remote_addr << "]" << ":" << req.remote_port <<  " " << req.version << " <" << req.method << ">" << req.path << " *" << res.status <<"\n";
				if (l >= DEBUG) {

					std::cout << log(req, res);
				}
			}
		}
		void log_handler(const httplib::Request& req, const httplib::Response& res)
		{
			logreq(req,res,LOG_LEVEL);
		}
	}

}

#endif // HTTPHELPER_H
