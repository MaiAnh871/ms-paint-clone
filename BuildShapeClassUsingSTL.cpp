#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <conio.h>

#define pi 3.14

using namespace std;

// Declare base abstract class Shape
class Shape
{
    protected:
        float pos_x, pos_y;             // Coordinates of the shape
        string name;                    // Name of the shape
        float distance;                 // Distance from O to shape

    public:
        // Constructor function
        Shape ()
        {
            pos_x = pos_y = 0;
            name = "";
            distance = 0;
        };

        // Deconstructor function
        ~Shape()
        {
        };

        // Intialize a shape
        virtual void setShape()
        {
            cout << "Enter characteristics of this Shape!" << endl;
            cout << "Enter the position x of this Shape: x = ";
            cin >> pos_x;
            cout << "Enter the position y of this Shape: y = ";
            cin >> pos_y;
            cout << "Enter the name of this Shape: name = ";
            cin >> name;
        };

        /*
        // Overloading operator <<
        friend ostream& operator << (ostream& os, Shape s)
        {
            os << "Name: " << s.name << endl << "Pos_x = " << s.pos_x << endl << "Pos_y = " << s.pos_y << endl << endl; 
            return os; 
        };
        */

        // Calculate distance from 0 to Shape
        float calDistance()
        {
            return sqrt (pos_x * pos_x + pos_y * pos_y);
        };

        // Calculate area of shape
        virtual float calArea()
        {
            return 0;
        };

        // Show position, name and distance of Shape
        virtual void print()
        {
            cout << "Name of this shape: " << name << endl;
            cout << "Position of this shape: x = " << pos_x << "; y = " << pos_y << endl;
            cout << "Distance from 0 to this shape: " << calDistance() << endl;
        };
};


// Declare derived class: Circle
class Circle: public Shape
{
    protected:
        float radius;                   // Radius of the circle
    
    public:
        // Constructor function
        Circle()
        {
            radius = 0;
        };

        // Intialize a Circle
        void setShape()
        {
            cout << endl << endl << "This is a Circle!" << endl;
            Shape::setShape();
            cout << "Enter radius of this Shape: r = ";
            cin >> radius;
        };

        // Calculate area of Circle
        float calArea()
        {
            return pi * radius * radius;
        };

        // Show all characteristics of the Circle
        void print()
        {
            cout << "This is a Circle!" << endl;
            Shape::print();
            cout << "Radius of this shape: " << radius << endl;
            cout << "Area of this shape: " << Circle::calArea() << endl;
        };

};

// Declare derived class: Square
class Square: public Shape
{
    protected:
        float edge;                   // Edge of the square
    
    public:
        // Constructor function
        Square()
        {
            edge = 0;
        };

        // Intialize a Square
        void setShape()
        {
            cout << endl << endl <<  "This is a Square!" << endl;
            Shape::setShape();
            cout << "Enter edge of this Shape: e = ";
            cin >> edge;
        };

        // Calculate area of Square
        float calArea()
        {
            return edge * edge;
        };

        // Show all characteristics of the Square
        void print()
        {
            cout << "This is a Square!" << endl;
            Shape::print();
            cout << "Edge of this shape: " << edge << endl;
            cout << "Area of this shape: " << Square::calArea() << endl;
        };
};

// Declare derived class: Rectangle
class Rectangle: public Shape
{
    protected:
        float length, width;                   // Length and width of the rectangle
    
    public:
        // Constructor function
        Rectangle()
        {
            length = width = 0;
        };

        // Intialize a Rectangle
        void setShape()
        {
            cout << endl << endl << "This is a Rectangle!" << endl;
            Shape::setShape();
            cout << "Enter length of this Shape: l = ";
            cin >> length;
            cout << "Enter width of this Shape: w = ";
            cin >> width;
        };

        // Calculate area of Rectangle
        float calArea()
        {
            return length * width;
        };

        // Show all characteristics of the Rectangle
        void print()
        {
            cout << "This is a Rectangle!" << endl;
            Shape::print();
            cout << "Length of this shape: " << length << endl;
            cout << "Width of this shape: " << width << endl;
            cout << "Area of this shape: " << Rectangle::calArea() << endl;
        };
};

// Declare derived class: Triangle
class Triangle: public Shape
{
    protected:
        float bottom, height;                   // Bottom and height of the triangle
    
    public:
        // Constructor function
        Triangle()
        {
            bottom = height = 0;
        };

        // Intialize a Triangle
        void setShape()
        {
            cout << endl << endl << "This is a Triangle!" << endl;
            Shape::setShape();
            cout << "Enter bottom of this Shape: b = ";
            cin >> bottom;
            cout << "Enter height of this Shape: h = ";
            cin >> height;
        };

        // Calculate area of Triangle
        float calArea()
        {
            return bottom * height / 2;
        };

        // Show all characteristics of the Triangle
        void print()
        {
            cout << "This is a Triangle!" << endl;
            Shape::print();
            cout << "Bottom of this shape: " << bottom << endl;
            cout << "Height of this shape: " << height << endl;
            cout << "Area of this shape: " << Triangle::calArea() << endl;
        };
};

// Declare derived class: Ellipse
class Ellipse: public Shape
{
    protected:
        float minor, major;                   // Minor radius and majot radius of the ellipse
    
    public:
        // Constructor function
        Ellipse()
        {
            minor = major = 0;
        };

        // Intialize a Ellipse
        void setShape()
        {
            cout << endl << endl << "This is a Ellipse!" << endl;
            Shape::setShape();
            cout << "Enter minor of this Shape: mi = ";
            cin >> minor;
            cout << "Enter major of this Shape: ma = ";
            cin >> major;
        };

        // Calculate area of Ellipse
        float calArea()
        {
            return pi * minor * major;
        };

        // Show all characteristics of the Ellipse
        void print()
        {
            cout << "This is a Ellipse!" << endl;
            Shape::print();
            cout << "Minor of this shape: " << minor << endl;
            cout << "Major of this shape: " << major << endl;
            cout << "Area of this shape: " << Ellipse::calArea() << endl;
        };
};

class FactoryShape
{
    // Constructor function
    FactoryShape()
    {
    };

    // Deconstructor function
    ~FactoryShape()
    {
    };

    // Declare shape type enum
    enum Shape_Type 
    {
        circle = 1,
        square = 2,
        rectangle = 3,
        triangle = 4,
        ellipse = 5
    };

    public:
        // Create new Shape lasting till the end of the program
        static Shape* createShape (int shapeType)
        {
            switch (shapeType)
            {
                case 1:
                    return new Circle;
                    break;

                case 2:
                    return new Square;
                    break;

                case 3:
                    return new Rectangle;
                    break;

                case 4:
                    return new Triangle;
                    break;

                case 5:
                    return new Ellipse;
                    break;
            }
        };
};

// Add new Shape to the list
void addShape (vector <Shape*> &Shape_List)
{
    Shape *S;
    int shape;
    cout << endl << endl << "                  MENU SHAPE                " << endl;
    cout << "Enter the number corresponding to the Shape you want to add!" << endl;
    cout << "1. Circle." << endl;
    cout << "2. Square." << endl;
    cout << "3. Rectangle." << endl;
    cout << "4. Triangle." << endl;
    cout << "5. Ellipse." << endl;
    cout << "Input your select: ";
    cin >> shape;

    // Call the function to add 1 Shape to the Shape_List
    Shape_List.push_back (FactoryShape::createShape (shape));

    // Call the setShape function for the Shape just pushed_back
    Shape_List.back()->setShape();
};

// Print all the shape entered
void showShape (vector <Shape*> &Shape_List)
{
    int i;
    if (Shape_List.size() == 0)
    {
        cout << "The list has no Shape!" << endl;
    }
    else
    {
        for (i = 0; i < Shape_List.size(); i++)
        {
            cout << endl << endl << "Shape " << i + 1 << ":" << endl;
            Shape_List[i]->print();
            cout << endl;
        }
    }
};

class Graph
{
    protected:
        // Declare the vector of the Shape class (contains a pointer)
        vector <Shape*> ShapeList;

    public:
        // Constructor function
        Graph()
        {
        };

        // Deconstructor function
        ~Graph()
        {
        };

        // Create menu
        void menu()
        {
            int choice = 0;
            while (1)
            {
                cout << endl << endl;
                cout << "                   MENU                  " << endl;
                cout << "Enter the number corresponding to the one you want to do!" << endl;
                cout << "1. Enter a Shape." << endl;
                cout << "2. Show list of Shape." << endl;
                cout << "3. Sort the Shape list depend on distance." << endl;
                cout << "4. Get Shape from file." << endl;
                cout << "5. Write Shape into file." << endl;
                cout << "6. Exit!" << endl;
                cout << "Input your select: ";
                cin >> choice;
                switch (choice)
                {
                    case 1:
                        addShape (ShapeList);
                        break;

                    case 2:
                        showShape (ShapeList);
                        break;

                    default:
                        cout << "Enter number from 1 to 6!" << endl;
                        break;
                }
            };
        };
};

int main()
{
    Graph g; 
    do
    {
        g.menu();
        break; 
    }
    while (1); 
    system ("pause");
    return 0;
}
