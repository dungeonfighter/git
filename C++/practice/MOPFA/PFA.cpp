#include "PFA.h"

#include <stdlib.h>
using namespace std;

PFA::PFA(size_t a, size_t b, size_t c, double d, double e, size_t f, size_t g)
{
    dim = a;     // dim of solutions
    size = b;    // number of solutions
    fit_dim = c; // dim of fitness e.g multi-objective problem
    max_bound = d;
    min_bound = e;
    iter = f;  // iteration
    round = g; // rounds for average

    cerr << "setting: " << dim << " " << size << " " << fit_dim << " " << max_bound << " " << min_bound << " " << iter << " " << round << " " << endl
         << endl;
}

void PFA::initialization()
{
    srand(time(NULL));
    vector<double> temp(dim, 0);
    solutions.assign(size, temp);
    temp.clear();
    temp.resize(fit_dim, RAND_MAX);
    fitness.assign(size, temp);
    box.reserve(50);

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < dim; j++)
        {
            solutions[i][j] = (max_bound - min_bound) * rand() / (RAND_MAX + 1.0) + min_bound;
        }
    }

    for (size_t i = 0; i < size; i++)
    {
        ZDT1(solutions[i], fitness[i]);
    }
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < dim; j++)
        {
            cerr << solutions[i][j] << " ";
        }
        cerr << endl;
    }
    cerr << endl;

    cerr << endl;
    for (size_t i = 0; i < size; i++)
    {
        cerr << fitness[i][0] << " " << fitness[i][1] << endl;
    }
}

int PFA::add_to_box()
{
    cerr << endl;
    int num = 0;
    vector<bool> selected(size, true);
    for (size_t i = 0; i < size; i++)
    {

        for (size_t j = i + 1; j < size; j++)
        {
            if (selected[j] == false)
            {
                break;
            }

            vector<bool> ob_win(fit_dim, false);
            size_t count = 0;

            for (size_t k = 0; k < fit_dim; k++)
            {
                if (fitness[i][k] < fitness[j][k]) // objective k win?
                {
                    ob_win[k] = true;
                }
                else
                {
                    ++count;
                }
            }

            if (count == fit_dim) // all lose
            {
                selected[i] = false;
                break;
            }
            else if(count == 0) // all win ,the one be compared disable
            {
                selected[j] = false;
            }
        }
    }

    for (size_t i = 0; i < size; i++)
    {
        if (selected[i] == true)
        {
            box.push_back(solutions[i]);
            for (size_t j = 0; j < dim; j++)
            {
                cerr << solutions[i][j] << " ";
            }
            cerr << endl;
            ++num;
        }
    }

    return num;
}