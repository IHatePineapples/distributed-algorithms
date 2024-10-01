#include "tree_wave/node.hpp"
#include <memory>
#include <thread>

using da::tw::node;

namespace {
void run_tree_wave(node *n) { n->exec(); }
} // namespace

int main() {

  const auto a = std::make_unique<node>('a');
  const auto b = std::make_unique<node>('b');
  const auto c = std::make_unique<node>('c');
  const auto d = std::make_unique<node>('d');

  a->connect(b.get());
  b->connect(c.get());

  d->connect(b.get());

  std::thread ta { run_tree_wave, a.get() };
  std::thread tb { run_tree_wave, b.get() };
  std::thread tc { run_tree_wave, c.get() };
  std::thread td { run_tree_wave, d.get() };

  ta.join();
  tb.join();
  tc.join();
  td.join();

}
