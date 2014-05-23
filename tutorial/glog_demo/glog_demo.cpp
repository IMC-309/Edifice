#include <iostream>
#include <glog/logging.h>

using namespace std;

int main(int argc, char** argv) {
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir=".";
    LOG(INFO) << "Hello, glog!";
    return 0;
}
