
#include <vnx/database/Server.h>

#include <vnx/vnx.h>
#include <vnx/Terminal.h>
#include <vnx/Server.h>


int main(int argc, char** argv)
{
	std::map<std::string, std::string> options;
	options["n"] = "node";
	options["l"] = "location";
	options["node"] = "server url";
	options["name"] = "server name";
	options["location"] = "location path";
	
	vnx::init("vnx_database_server", argc, argv, options);
	
	std::string node = "vnx_database_server.sock";
	vnx::read_config("node", node);
	
	std::string name = "Database";
	vnx::read_config("name", name);
	
	{
		vnx::Handle<vnx::Terminal> terminal = new vnx::Terminal("Terminal");
		terminal.start_detached();
	}
	{
		vnx::Handle<vnx::Server> server = new vnx::Server("Server", vnx::Endpoint::from_url(node));
		server.start_detached();
	}
	{
		vnx::Handle<vnx::database::Server> module = new vnx::database::Server(name);
		vnx::read_config("location", module->location);
		module.start_detached();
	}
	
	vnx::wait();
	return 0;
}
