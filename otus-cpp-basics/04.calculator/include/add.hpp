#pragma once

#include <string>

#include "astnode.hpp"

class Add : public ASTNode {
public:
    Add(ASTNode *current_root, ASTNode *right_token) : ASTNode("+", current_root, right_token) {};

private:
    std::string val_;
};