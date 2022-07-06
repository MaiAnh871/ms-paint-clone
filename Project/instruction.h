#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <shape.h>
#include <QObject>
#include <memory>
#include <vector>

using namespace std;
namespace Paint
{
class Instruction : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Instruction intialize
     */
    explicit Instruction (std::vector <unique_ptr<Shape>> &l, std::unique_ptr<Shape> &&s);

    // https://stackoverflow.com/questions/3065154/undefined-reference-to-vtable
    virtual ~Instruction() {};

    /**
     * @brief Add shape just drew to List
     */
    void addShape();

    /**
     * @brief Show all shape in list
     */
    void showShape();

    /**
     * @brief For sortShape function
     */
    bool static compareDistance (std::unique_ptr<Shape> &s1, std::unique_ptr<Shape> &s2);

    /**
     * @brief Sort Shape based on distance
     * @param List
     */
    void sortShape ();

private:
    std::vector <unique_ptr<Shape>> shapeList;
    std::unique_ptr<Shape> shape;
};
} // namespace Paint
#endif // INSTRUCTION_H
