#include "server.h"
#include <iostream>
#include <random>
#include "crypto.h"

std::shared_ptr<Client> Server::add_client(std::string id)
{
    for (const auto &it : clients) {
        if (id == it.first->get_id()) {
            std::random_device seed;
            std::ranlux48 engine(seed());
            std::uniform_int_distribution distrib(10000, 99999);
            int random = distrib(engine);
            id += std::to_string(random);
            break;
        }
    }
    auto client{std::make_shared<Client>(id, *this)};
    clients[client] = 5;
    return client;
}

std::shared_ptr<Client> Server::get_client(std::string id) const noexcept
{
    for (auto const &[name, value] : clients) {
        bool flag = true;
        for (size_t i = 0; i < id.size(); i++) {
            if (id[i] != name->get_id().at(i)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return name;
        }
    }
    return {};
}

double Server::get_wallet(std::string id) const noexcept
{
    for (const auto &[name, value] : clients) {
        const std::strong_ordering order = id <=> (*name).get_id();
        if (std::is_eq(order)) {
            return value;
        }
    }
    throw std::logic_error("Client is not found!");
}

bool Server::parse_trx(std::string trx, std::string sender, std::string receiver, double value)
{
    return false;
}

bool Server::add_pending_trx(std::string trx, std::string signature)
{
    return false;
}

size_t Server::mine()
{
    return 0;
}