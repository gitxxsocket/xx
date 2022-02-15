//
//

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <memory_resource>
using namespace std;
using namespace pmr;
int main() {
    pool_options opt;
    opt.largest_required_pool_block = 1024 * 1024 * 10; //10mb
    opt.max_blocks_per_chunk = 1024 * 1024 * 100;

    //线程安全
    synchronized_pool_resource mpool(opt);
    int size = 1024 * 1024;
    std::vector<void *> datas;
    for (int i = 0; i < 32000; ++i) {
        try {
            auto data = mpool.allocate(size);
            datas.push_back(data);
            cout << "+" << flush;
            this_thread::sleep_for(100ns);
        } catch (std::exception &ex) {
            cerr << "failed" << ex.what() << endl;
            exit(0);
        }
    }

    auto b1 = mpool.allocate(1024 * 1024 * 20);
    mpool.deallocate(b1,1024 * 1024 * 20);

    for(auto  d: datas){
        mpool.deallocate(d,size);
        cout << "-" << flush;
        this_thread::sleep_for(100ns);

    }
    return 0;
}