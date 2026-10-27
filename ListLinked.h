#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() : first(nullptr), n(0) {
    }

    ~ListLinked() override {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida!");
        }

        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* aux = first;

            for (int i = 0; i < pos - 1; i++) {
                aux = aux->next;
            }

            aux->next = new Node<T>(e, aux->next);
        }

        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }

        Node<T>* aux;
        T e;

        if (pos == 0) {
            aux = first;
            e = first->data;
            first = first->next;
        } else {
            Node<T>* prev = first;

            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }

            aux = prev->next;
            e = aux->data;
            prev->next = aux->next;
        }

        delete aux;
        n--;

        return e;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }

        Node<T>* aux = first;

        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }

        return aux->data;
    }

    int search(T e) override {
        Node<T>* aux = first;
        int pos = 0;

        while (aux != nullptr) {
            if (aux->data == e) {
                return pos;
            }

            aux = aux->next;
            pos++;
        }

        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    T operator[](int pos) {
        return get(pos);
    }

    friend std::ostream& operator<<(std::ostream& out, ListLinked<T>& list) {
        out << "List => [";

        Node<T>* aux = list.first;

        while (aux != nullptr) {
            out << "\n  " << aux->data;
            aux = aux->next;
        }

        out << "\n]";

        return out;
    }
};

#endif
