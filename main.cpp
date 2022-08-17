#define BOOST_LOG_DYN_LINK 1 

#include <iostream>
#include <boost/log/trivial.hpp>
//#include "rummy.hpp"

using namespace std;

int main() {
    //Rummy rummy;
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

    cout << "Hello Dude !!!" << endl;
    return 0;
}
