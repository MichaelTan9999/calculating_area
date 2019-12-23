//
//  list.cpp
//  calculation_review
//
//  Created by Michael Tan on 2019/12/12.
//  Copyright © 2019 MichaelTan9999. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename value_type>
class list
{
private:
    
    class node
    {
    public:
        value_type data;
        node *next;
    };
    
    node *head, *tail;
    size_t length;

public:
    
    void push(value_type new_node)
    {
        auto p{new node{new_node, nullptr}};
        
        if (head == nullptr)
        {
            head = p;
        }
        else
        {
            tail->next = p;
        }
        
        tail = p;
        length++;
    }
    
    size_t size() const
    {
        return length;
    }
    
    list() : head(nullptr), tail(nullptr), length(0){}
    
    ~list()
    {
        for (auto p{head}; head != nullptr;)
        {
            head = head->next;
            delete p;
            p = head;
        }
        
        head = tail = nullptr;
        length = 0;
    }
    /*
     Below here are codes defined iterator for Class list
     */
    
    friend class my_iterator;
    class my_iterator
    {
    private:
        node* pointer;
        
    public:
        my_iterator(node *t = nullptr) : pointer(t){}
        
        bool operator !=(const my_iterator &i)
        {
            return pointer != i.pointer;
        }
        
        my_iterator& operator ++()
        {
            pointer = pointer->next;
            return *this;
        }
        
        value_type& operator *()
        {
            return pointer->data;
        }
    };
    
    my_iterator begin()
    {
        return my_iterator(head);
    }
    
    my_iterator end()
    {
        return my_iterator();
    }
};
