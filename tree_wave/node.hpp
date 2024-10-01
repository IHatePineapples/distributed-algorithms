#include "node/node.hpp"
#include <map>

namespace da::tw {

class node : public da::node {

  std::map<const da::node *, bool> bneighs_;

public:
  node(const char = '?');
  void init_bvec();

  void exec() override;

  ~node(){}; 
};
} // namespace da::tw
