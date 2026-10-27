#include "Shape.h"
#include <stdexcept>
#include <utility>

namespace {
    bool valid_color(const std::string& color) {
        return color == "red" || color == "green" || color == "blue";
    }
}

Shape::Shape() : color("red") {}

Shape::Shape(std::string color) : color(std::move(color)) {
    if (!valid_color(this->color)) {
        throw std::invalid_argument("Invalid color!");
    }
}

std::string Shape::get_color() const {
    return color;
}

void Shape::set_color(std::string c) {
    if (!valid_color(c)) {
        throw std::invalid_argument("Invalid color!");
    }
    color = std::move(c);
}
