#include "mainwindow.h"
#include <iostream>
#include <QApplication>

class LogDuration {
public:
    LogDuration(std::string id)
            : id_(std::move(id)) {
    }

    ~LogDuration() {
        const auto end_time = std::chrono::steady_clock::now();
        const auto dur = end_time - start_time_;
        std::cout << id_ << ": ";
        std::cout << "operation time"
                  << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
                  << " ms" << std::endl;
    }

private:
    const std::string id_;
    const std::chrono::steady_clock::time_point start_time_ = std::chrono::steady_clock::now();
};

int main(int argc, char *argv[])
{

    Vector<std::string> v;
    {
        LogDuration l("vector");
        for(int i = 0; i < 100000000; i++) {
            v.push_back("qwerqwerqwerqwer");
        }
    }
    for(int i = 0; i < 100000000; i++){
        v[i] = "odfgopidsf";
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
