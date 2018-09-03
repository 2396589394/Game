#ifndef __TCP_Network_H__
#define __TCP_Network_H__

#include "tcpNetConfig.h"
#include <boost/asio.hpp>

class TcpNetwork
{
private:
    boost::asio::io_context io_context_;
    boost::asio::thread_pool thread_pool_;
    boost::asio::ip::tcp::acceptor acceptor_;
    void(*task_)(boost::asio::ip::tcp::socket* socket);
    std::atomic<bool> quit_;
    boost::asio::signal_set signals_;

private:
    void listen();

public:
    TcpNetwork(TcpNetConfig& config, void(*task)(boost::asio::ip::tcp::socket* socket));
    ˜TcpNetwork();

    void run();
};

#endif