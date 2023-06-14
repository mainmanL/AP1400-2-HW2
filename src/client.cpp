#include "client.h"
#include "crypto.h"
#include <cstdlib>

Client::Client(std::string id, const Server &server) :
    server(&server), id(id)
{
    crypto::generate_key(public_key, private_key);
}

const std::string Client::get_id() const noexcept
{
    return id;
}

const std::string Client::get_publickey() const noexcept
{
    return public_key;
}

const double Client::get_wallet() const noexcept
{
    return server->get_wallet(id);
}

std::string Client::sign(std::string txt)
{
    return {};
}

bool Client::transfer_money(std::string receiver, double value)
{
    return false;
}

size_t Client::generate_nonce()
{
    return 0;
}