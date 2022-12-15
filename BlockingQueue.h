
#ifndef META_SERVER_BLOCKINGQUEUE_H
#define META_SERVER_BLOCKINGQUEUE_H
#include <vector>
#include <queue>
#include <mutex>

template <class T>
class BlockingQueue {
    std::queue<T> tasks;
    std::mutex mx;
    std::condition_variable cv;

public:
    BlockingQueue() {};
    ~BlockingQueue() {};

    T pop() {
        std::unique_lock<std::mutex> lock(mx);
        if (tasks.empty())
            cv.wait(lock, [&](){return !(this->tasks.empty());});

        T tmpFun = tasks.front();
        tasks.pop();
        return tmpFun;
    }

    void push(const T &task) {
        {
            std::unique_lock<std::mutex> lock(mx);
            tasks.push(task);
        }
        cv.notify_one();
    }
};


#endif //META_SERVER_BLOCKINGQUEUE_H
