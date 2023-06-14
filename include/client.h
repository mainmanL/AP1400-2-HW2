#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "server.h"

class Server;

class Client {
public:
    Client(std::string id, const Server &server);
    const std::string get_id() const noexcept;
    const std::string get_publickey() const noexcept;
    const double get_wallet() const noexcept;
    std::string sign(std::string txt);
    bool transfer_money(std::string receiver, double value);
    size_t generate_nonce();

private:
    Server const *const server;
    const std::string id;
    std::string public_key;
    std::string private_key;
};

#endif // CLIENT_H