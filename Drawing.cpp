#include "Drawing.h"
#include "ListArray.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>

Drawing::Drawing() : shapes(new ListArray<Shape*>()) {}

Drawing::~Drawing() {
    // Drawing owns the figures added to it.
    while (!shapes->empty()) {
        Shape* shape = shapes->remove(0);
        delete shape;
    }
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

void Drawing::print_all() {
    std::cout << "Drawing contents:" << std::endl;
    for (int i = 0; i < shapes->size(); ++i) {
        shapes->get(i)->print();
        std::cout << std::endl;
    }
}

double Drawing::get_area_all_circles() {
    double total = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Circle* circle = dynamic_cast<Circle*>(shapes->get(i));
        if (circle != nullptr) total += circle->area();
    }
    return total;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Square* square = dynamic_cast<Square*>(shapes->get(i));
        if (square != nullptr) square->translate(incX, incY);
    }
}
