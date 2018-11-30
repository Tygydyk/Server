void accept_thread() {
    ip::tcp::acceptor acceptor{service, ip::tcp::endpoint{ip::tcp::v4{}, 8001}};
    while (true) {
        auto client = std::make_shared<talk_to_client>(); // talk_to_client - user defined class
        acceptor.accept(client->sock());
        boost::recursive_mutex::scoped_lock lock{mutex};
        clients.push_back(client);
    }
}

void handle_clients_thread() {
    while (true) {
        std::this_thread::sleep(std::chrono::milliseconds{1});
        boost::recursive_mutex::scoped_lock lock{mutex};
        for (auto& client : clients) {
            // for each client calling answer_to_client();
        }
        // and then erase clients that timed out
      }
}

int main(int /*argc*/, char* /*argv*/[]) {

    boost::thread_group threads;
    threads.create_thread(accept_thread);
    threads.create_thread(handle_clients_thread);
    threads.join_all();
}
