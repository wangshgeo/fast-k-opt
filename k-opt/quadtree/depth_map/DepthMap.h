#pragma once

#include "transform.h"
#include <primitives.h>
#include <quadtree/QuadtreeNode.h>

#include <array>
#include <map>

namespace quadtree {
namespace depth_map {

class DepthMap
{
public:

    using NodeContainer = std::map<transform::hash_t, QuadtreeNode*>;

    void add_root(QuadtreeNode* root) { add_node(0, 0, 0, root); }
    const QuadtreeNode* get_node(int depth, transform::hash_t hash) const;
    const NodeContainer& get_nodes(int depth) const;
    void add_node(int depth, transform::grid_coord_t x, transform::grid_coord_t y, QuadtreeNode* node);
    void remove_node(int depth, transform::grid_coord_t x, transform::grid_coord_t y);

private:
    std::array<NodeContainer, primitives::MaxTreeDepth> m_nodes;
};

} // namespace depth_map
} // namespace quadtree

