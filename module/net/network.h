#ifndef __NETWORK_H__
#define __NETWORK_H__

#include "netConfig.h"
#include <boost/asio.hpp>

class Network
{
private:
    boost::asio::io_context io_context_;
    boost::asio::thread_pool thread_pool_;
    boost::asio::ip::tcp::acceptor acceptor_;
    void(*task_)(boost::asio::ip::tcp::socket* socket);
    std::atomic<bool>& quit_;

private:
    void listen();

public:
    Network(NetConfig& config, void(*task)(boost::asio::ip::tcp::socket* socket), std::atomic<bool>& quit);
    ˜Network();

    void run();
};

#endif