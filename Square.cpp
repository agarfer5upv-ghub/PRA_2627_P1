#include "Square.h"
#include <stdexcept>

bool Square::check(Point2D* vertices) {
    if (vertices == nullptr) return false;
    double side = Point2D::distance(vertices[0], vertices[1]);
    return side == Point2D::distance(vertices[1], vertices[2]) &&
           side == Point2D::distance(vertices[2], vertices[3]) &&
           side == Point2D::distance(vertices[3], vertices[0]);
}

Square::Square() : Rectangle() {
    Point2D vertices[N_VERTICES] = {
        Point2D(-1, 1), Point2D(1, 1),
        Point2D(1, -1), Point2D(-1, -1)
    };
    set_vertices(vertices);
}

Square::Square(std::string color, Point2D* vertices)
    : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
    Rectangle::set_vertices(vertices);
}

void Square::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& out, const Square& s) {
    out << "[Square: color = " << s.color;
    for (int i = 0; i < Rectangle::N_VERTICES; ++i) {
        out << "; v" << i << " = " << s.vs[i];
    }
    out << "]";
    return out;
}
