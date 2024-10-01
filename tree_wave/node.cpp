#include "tree_wave/node.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <thread>

namespace {
void wait_for_tok(const char name) {
  std::cout << name << ": Waited for tok." << std::endl; 
  std::this_thread::sleep_for(std::chrono::milliseconds{667 + random() % 1000});
}
} // namespace

namespace da::tw {
node::node(const char c) : da::node(c) { init_bvec(); }

void node::init_bvec() {
  bneighs_.clear();
  for (const auto n : neighs_)
    bneighs_[n] = false;
}

void node::exec() {

  init_bvec();

  auto recv = [](auto p) { return !p.second; };

  while (std::count_if(bneighs_.begin(), bneighs_.end(), recv) > 1) {
    if (!fifo_.empty()) {
      bneighs_[fifo_.front()] = true;
      fifo_.pop();
    }
    wait_for_tok(name_);
  }

  auto is_sn = [&](auto n) { return !bneighs_[n]; };

  // Guaranteed to succeed.
  auto sn = *std::find_if(neighs_.begin(), neighs_.end(), is_sn);
  std::cout << name_ << ": My Silent neighbour is " << sn->name() << std::endl;
  send(sn);
  while (fifo_.empty() && fifo_.front() != sn) {
    wait_for_tok(name_);
  }
}
} // namespace da::tw
