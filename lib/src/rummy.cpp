#include <boost/log/trivial.hpp>

#include "rummy.hpp"

using namespace std;

Rummy::Rummy() {
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
}

Rummy::~Rummy() {

}
