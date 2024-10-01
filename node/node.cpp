#include "node.hpp"

#include <chrono>
#include <iostream>
#include <ostream>
#include <thread>

namespace da {

node::node(const char c, const std::vector<const node *> &n)
    : name_(c), neighs_(n) {
  std::cout << c << ": Created." << std::endl;
}

void node::recv(const node *n) {
  std::this_thread::sleep_for(std::chrono::seconds{5});
  fifo_.emplace(n);
  std::cout << name_ << ": Received <tok> from " << n->name() << std::endl;
}

void node::send(node *n) const {
  std::cout << name_ << ": Sent <tok> to " << n->name() << std::endl;
  n->recv(this);
};

void node::connect(node *n) {
  std::cout << name_ << " <==> " << n->name() << std::endl;
  neighs_.push_back(n);
  n->neighs_.push_back(this);
}

} // namespace da
