#include "network.h"
#include <boost/bind.hpp>
#include "log/log.h"

Network::Network(NetConfig& config, void(*task)(boost::asio::ip::tcp::socket* socket), std::atomic<bool>& quit)
: io_context_(config.threadNumber),
  thread_pool_(config.threadNumber - 1),
  acceptor_(io_context_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), config.port)),
  task_(task),
  quit_(quit)
{
    for(int i = 0; i < config.threadNumber - 1; i++)
    {
        boost::asio::post(this->thread_pool_, boost::bind([](std::atomic<bool>& quit, boost::asio::io_context& io_context){
            while(!quit)
            {
                io_context.run();
            }
        }, this->quit_, this->io_context_));
    }
}

Network::˜Network()
{
    this->thread_pool_.join();
}

void Network::listen()
{
    boost::asio::ip::tcp::socket* socket = new boost::asio::ip::tcp::socket(this->io_context_);
    this->acceptor_.async_accept(*socket, boost::bind([this](boost::asio::ip::tcp::socket* socket, boost::system::error_code error){
        if(error)
        {
            Log::printf_warn(error.message().c_str());
        }
        else
        {
            boost::asio::post(this->io_context_, boost::bind(this->task_, socket));
        }

        this->listen();
    }, socket, boost::asio::placeholders::error));
}

void Network::run()
{
    this->listen();

    while(!this->quit_)
    {
        this->io_context_.run();
    }
}