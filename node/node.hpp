#include <queue>
#include <vector>

namespace da {

class node {
protected:
  const char name_ = '?';
  std::vector<node *> neighs_ = {};
  mutable std::queue<const node *> fifo_ = {};

public:
  node(const char = '?');

  auto &neighs() { return neighs_; }
  const auto name() const { return name_; }

  virtual void exec() = 0;

  void send(node *n) const;
  void recv(const node *n);
  void connect(node *n);

  virtual ~node(){};
};
} // namespace da
