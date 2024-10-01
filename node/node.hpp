#include <queue>
#include <vector>

namespace da {

class node {
protected:
  const char name_ = '?';
  std::vector<node *> neighs_ = {};
  mutable std::queue<const node *> fifo_ = {};

public:
  explicit node(const char c, const std::vector<const node *> &n = {});

  auto &neighs() { return neighs_; }
  const auto name() const { return name_; }

  virtual void exec() = delete;

  void send(node *n) const;
  void recv(const node *n);
  void connect(const node *n);
};
} // namespace da
