#define BOOST_LOG_DYN_LINK 1 

#include <iostream>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/expressions.hpp>

#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/attributes/named_scope.hpp>

#include "rummy.hpp"

using namespace std;

namespace logging = boost::log;
namespace expr     = boost::log::expressions;
 
void init_logging() { 
    boost::log::add_common_attributes();
    auto fmtTimeStamp = boost::log::expressions::
        format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S.%f");
    auto fmtThreadId = boost::log::expressions::
        attr<boost::log::attributes::current_thread_id::value_type>("ThreadID");
    auto fmtSeverity = boost::log::expressions::
        attr<boost::log::trivial::severity_level>("Severity");
    auto fmtScope = boost::log::expressions::format_named_scope("Scope",
        boost::log::keywords::format = "%n(%f:%l)",
        boost::log::keywords::iteration = boost::log::expressions::reverse,
        boost::log::keywords::depth = 2);
    boost::log::formatter logFmt =
        boost::log::expressions::format("[%1%] (%2%) [%3%] %4%")
        % fmtTimeStamp % fmtThreadId % fmtSeverity
        % boost::log::expressions::smessage;

    auto consoleSink = boost::log::add_console_log(std::clog);
    consoleSink->set_formatter(logFmt);   

    /*   
    logging::add_file_log("sample.log");
    logging::core::get()->set_filter     (        
      logging::trivial::severity >= logging::trivial::info     
   );
   */
} 

int main() {
    init_logging();

    Rummy rummy;
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

    cout << "Hello Dude !!!" << endl;
    return 0;
}
