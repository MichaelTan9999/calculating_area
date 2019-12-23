//
//  main.cpp
//  calculation_review
//
//  Created by Michael Tan on 2019/12/11.
//  Copyright © 2019 MichaelTan9999. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdio>
#include "shapes.cpp"
#include "list.cpp"

using namespace std;

quadrangle* create_shape()
{
    quadrangle* target{nullptr};
    srand(static_cast<unsigned int>(time(NULL)));
    int shape{rand() % 5};
    int width{rand() % 20 + 1}, height{rand() % 20 +1}, backup{rand() % 20 +1};
    switch (shape)
    {
        case 0:
            target = new parallelogram(width, height);
            break;
        case 1:
            target = new rectangle(width, height);
            break;
        case 2:
            target = new diamond(width, height);
            break;
        case 3:
            target = new square(width);
            break;
        case 4:
            target = new trapezoid(width, height, backup);
            break;
    }
    return target;
}

int main()
{
    list<quadrangle*> the_list;
    string insertion;
    cout << " *******************************\n Enter negative number to exit.\n *******************************" << endl;
    while (1)
    {
        quadrangle* p = create_shape();
        // cout << p->get_shape();
        p->print_question();
        cout << "?";
        cin >> insertion;
        if (stod(insertion) < 0)
        {
            delete p;
            p = nullptr;
            break;
        }
        the_list.push(p);
        if (stod(insertion) == p->area())
        {
            cout << "Congratulations!" << endl;
            p->right();
        }
        else
        {
            cout << "Incorrected answer." << endl;
            p->wrong();
        }
        cout << endl;
        p = nullptr;
    }
    
    cout << endl;
    cout << "Reviewing..." << endl;
    int correct{};
    for (auto i{the_list.begin()}; i != the_list.end(); ++i)
    {
        // cout << (*i)->get_shape();
        (*i)->print_question();
        cout << (*i)->area();
        if ((*i)->performance())
        {
            cout << "\033[32m ✔\033[0m";
            correct++;
        }
        else
        {
            cout << "\033[31m ✘\033[0m";
        }
        cout << endl;
    }
    
    cout << endl;
    cout << "Total: " << the_list.size() << ", Correct: " << correct << endl;
    for (auto i : the_list)
    {
        delete i;
    }
}

