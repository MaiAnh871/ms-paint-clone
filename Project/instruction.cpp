#include <instruction.h>
#include <QDebug>

namespace Paint
{
Instruction::Instruction (std::vector <unique_ptr<Shape>> &l, std::unique_ptr<Shape> &&s) :
    shapeList(std::move(l)), shape(std::move(s))
{
}

void Instruction::addShape()
{
   // https://stackoverflow.com/questions/3283778/why-can-i-not-push-back-a-unique-ptr-into-a-vector
   shapeList.push_back (std::move(shape));
}

void Instruction::showShape()
{
    unsigned long long i = 0;
    if (shapeList.size() == 0)
    {
        qDebug() << "The List has no shape" << endl;
    }
    else
    {
        for (i = 0; i < shapeList.size(); i++)
        {
            qDebug() << "Shape " << i + 1 << ":" << endl;
            shapeList[i]->printInfo();
            qDebug() << endl;
        }
    }
}

bool Instruction::compareDistance (std::unique_ptr<Shape> &s1, std::unique_ptr<Shape> &s2)
{
    return s1->calDistance() < s2->calDistance();
}

void Instruction::sortShape()
{
    // https://stackoverflow.com/questions/33913305/must-use-or-to-call-pointer-to-member-function-in-lessthan-e?newreg=5b534fabd3674150b94bafce726a34b4
    sort (shapeList.begin(), shapeList.end(), compareDistance);
    qDebug() << endl << endl << "The list after sorting is: " << endl;
    for (unsigned long long i = 0; i < shapeList.size(); i++)
    {
        qDebug() << "Shape " << i + 1 << ":" << endl;
        shapeList[i]->printInfo();
        qDebug() << endl;
    };
}
} // namespace Paint
