#pragma once

#include <string>

#include "astnode.hpp"

class Sub : public ASTNode {
public:
    Sub(ASTNode *current_root, ASTNode *right_token) : ASTNode("-", current_root, right_token) {};

private:
    std::string val_;
};