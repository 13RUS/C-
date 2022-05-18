#pragma once

#include <string>

#include "astnode.hpp"

class Div : public ASTNode {
public:
    Div(ASTNode *current_root, ASTNode *right_token) : ASTNode("/", current_root, right_token) {};

private:
    std::string val_;
};