#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <conio.h>

#define pi 3.14
#define outFile "textfile.txt"
#define inFile "data.txt"

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

        virtual void setX (float x)
        {
            pos_x = x;
        }

        virtual void setY (float y)
        {
            pos_y = y;
        }

        virtual void setName (string n)
        {
            name = n;
        }

        virtual void setSize1(float size){}

        virtual void setSize2(float size){}
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

        // Write data to file
        virtual void writeFile (ofstream &file)
        {
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

        // Circle only has 1 size
        virtual void setSize1 (float size)
        {
            radius = size;
        }
       
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
    
        // Write Circle data to file in JSON
        void writeFile (ofstream &file)
        {
            file << "        {" << endl;
            file << "            \"type\": \"Circle\"," << endl;
            file << "            \"name\": \"" << name << "\"," << endl;
            file << "            \"pos_x\": " << pos_x << "," << endl;
            file << "            \"pos_y\": " << pos_y << "," << endl;
            file << "            \"radius\": " << radius << endl;
            file << "        }," << endl;
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

        // Square only has 1 size
        void setSize1 (float size)
        {
            edge = size;
        }

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

        // Write Square data to file in JSON
        void writeFile (ofstream &file)
        {
            file << "        {" << endl;
            file << "            \"type\": \"Square\"," << endl;
            file << "            \"name\": \"" << name << "\"," << endl;
            file << "            \"pos_x\": " << pos_x << "," << endl;
            file << "            \"pos_y\": " << pos_y << "," << endl;
            file << "            \"edge\": " << edge << endl;
            file << "        }," << endl;
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

        // Rectangle has 2 size
        void setSize1 (float size)
        {
            length = size;
        }

        void setSize2 (float size)
        {
            width = size;
        }

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

         // Write Rectangle data to file in JSON
        void writeFile (ofstream &file)
        {
            file << "        {" << endl;
            file << "            \"type\": \"Rectangle\"," << endl;
            file << "            \"name\": \"" << name << "\"," << endl;           
            file << "            \"pos_x\": " << pos_x << "," << endl;
            file << "            \"pos_y\": " << pos_y << "," << endl;
            file << "            \"length\": " << length << "," << endl;
            file << "            \"width\": " << width << endl;
            file << "        }," << endl;
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

        // Triangle has 2 size
        void setSize1 (float size)
        {
            bottom = size;
        }

        void setSize2 (float size)
        {
            height = size;
        }

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

        // Write Triangle data to file in JSON
        void writeFile (ofstream &file)
        {
            file << "        {" << endl;
            file << "            \"type\": \"Triangle\"," << endl;           
            file << "            \"name\": \"" << name << "\"," << endl;
            file << "            \"pos_x\": " << pos_x << "," << endl;
            file << "            \"pos_y\": " << pos_y << "," << endl;
            file << "            \"bottom\": " << bottom << "," << endl;
            file << "            \"height\": " << height << endl;
            file << "        }," << endl;
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

        // Ellipse has 2 size
        void setSize1 (float size)
        {
            minor = size;
        }

        void setSize2 (float size)
        {
            major = size;
        }

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

        // Write Ellipse data to file in JSON
        void writeFile (ofstream &file)
        {
            file << "        {" << endl;
            file << "            \"type\": \"Ellipse\"," << endl;
            file << "            \"name\": \"" << name << "\"," << endl;
            file << "            \"pos_x\": " << pos_x << "," << endl;
            file << "            \"pos_y\": " << pos_y << "," << endl;
            file << "            \"minor\": " << minor << "," << endl;
            file << "            \"major\": " << major << endl;
            file << "        }," << endl;
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
        cout << endl << endl;
        for (i = 0; i < Shape_List.size(); i++)
        {
            cout << "Shape " << i + 1 << ":" << endl;
            Shape_List[i]->print();
            cout << endl;
        }
    }
};

// Compare two Shape based on its distance
bool compareDistance (Shape* &Shape1, Shape* &Shape2)
{
    return Shape1->calDistance() < Shape2->calDistance();
};

// Sort the list based on the distance from the object to the origin (Increasing)
void sortShape (vector <Shape*> Shape_List)
{
    sort (Shape_List.begin(), Shape_List.end(), compareDistance);
    cout << endl << endl << "The list after sorting is: " << endl;
    for (int i = 0; i < Shape_List.size(); i++)
    {
        cout << "Shape " << i + 1 << ":" << endl;
        Shape_List[i]->print();
        cout << endl;
    }
};

// Write the list to file in JSON
void writeShape (ofstream &file, vector <Shape*> Shape_List)
{
    file << "{" << endl << "    \"shape\": [" << endl;
    for (int i = 0; i < Shape_List.size(); i++)
    {
        Shape_List[i]->writeFile(file);
    }
    file << "    ]" << endl << "}";
}

// Read the list in JSON
void readShape (string inputFile, vector <Shape*> &Shape_List)
{
    fstream fileIn;
    string temp, textStr = "";
    fileIn.open (inputFile, ios::in);
    
    if (fileIn.fail()) //
    {
        cout << "Cannot read this file!" << endl;
        return;
    }
    while(!fileIn.eof())
    {
        getline (fileIn, temp);                    // Read file from beginning to "," then assign it to temp        
        //cout << temp << endl << endl;
        textStr = textStr + temp;
    }

    // Delete edundant text
    textStr.erase(textStr.begin(), textStr.begin() + 15);
    textStr.erase(textStr.end() - 6, textStr.end());
    //cout << textStr << endl;

    int typeIndex1, typeIndex2;                                         // Index to identify type
    int nameIndex1, nameIndex2, nameSize;                               // Index to identify name
    string nameTemp, posxTemp, posyTemp, size1Temp, size2Temp;
    int posxIndex1, posxIndex2, posxSize; 
    int posyIndex1, posyIndex2, posySize;
    int size1Index1, size1Index2, size1Size;
    int size2Index1, size2Index2, size2Size;

    while (textStr != "")
    {
        // Identify type
        typeIndex1 = textStr.find(":");
        typeIndex2 = textStr.find(",");

        switch (textStr[typeIndex1 + 3])
        {
            case 'C':                                                   // Circle
            {
                    Shape_List.push_back (FactoryShape::createShape(1));

                    // Identify name
                    textStr.erase(textStr.begin(), textStr.begin() + typeIndex2 + 1);
                    nameIndex1 = textStr.find(":");                
                    nameIndex2 = textStr.find(",");
                    nameSize = distance (textStr.begin() + nameIndex1 + 3, textStr.begin() + nameIndex2 - 1);
                    nameTemp = textStr.substr (nameIndex1 + 3, nameSize);
                    Shape_List.back()->setName(nameTemp);

                    // Identify pos x
                    textStr.erase(textStr.begin(), textStr.begin() + nameIndex2 + 1);
                    posxIndex1 = textStr.find(":");                
                    posxIndex2 = textStr.find(",");
                    posxSize = distance (textStr.begin() + posxIndex1 + 2, textStr.begin() + posxIndex2);
                    posxTemp = textStr.substr (posxIndex1 + 2, posxSize);
                    Shape_List.back()->setX(stof(posxTemp));

                    // Identify pos y
                    textStr.erase(textStr.begin(), textStr.begin() + posxIndex2 + 1);
                    posyIndex1 = textStr.find(":");                
                    posyIndex2 = textStr.find(",");
                    posySize = distance (textStr.begin() + posyIndex1 + 2, textStr.begin() + posyIndex2);
                    posyTemp = textStr.substr (posyIndex1 + 2, posySize);
                    Shape_List.back()->setY(stof(posyTemp));

                    // Identify radius
                    textStr.erase(textStr.begin(), textStr.begin() + posyIndex2 + 1);
                    size1Index1 = textStr.find(":");                
                    size1Index2 = textStr.find("}");
                    size1Size = distance (textStr.begin() + size1Index1 + 2, textStr.begin() + size1Index2 - 8);
                    size1Temp = textStr.substr (size1Index1 + 2, size1Size);
                    Shape_List.back()->setSize1(stof(size1Temp));

                    // End
                    textStr.erase(textStr.begin(), textStr.begin() + size1Index2 + 2);
					cout << "textStr con lai sau khi doc Circle la:" << textStr << endl << endl;
					break;
            }

			case 'S':                                                   // Square
            {
                    Shape_List.push_back (FactoryShape::createShape(2));

                    // Identify name
                    textStr.erase(textStr.begin(), textStr.begin() + typeIndex2 + 1);
                    nameIndex1 = textStr.find(":");                
                    nameIndex2 = textStr.find(",");
                    nameSize = distance (textStr.begin() + nameIndex1 + 3, textStr.begin() + nameIndex2 - 1);
                    nameTemp = textStr.substr (nameIndex1 + 3, nameSize);
                    Shape_List.back()->setName(nameTemp);

                    // Identify pos x
                    textStr.erase(textStr.begin(), textStr.begin() + nameIndex2 + 1);
                    posxIndex1 = textStr.find(":");                
                    posxIndex2 = textStr.find(",");
                    posxSize = distance (textStr.begin() + posxIndex1 + 2, textStr.begin() + posxIndex2);
                    posxTemp = textStr.substr (posxIndex1 + 2, posxSize);
                    Shape_List.back()->setX(stof(posxTemp));

                    // Identify pos y
                    textStr.erase(textStr.begin(), textStr.begin() + posxIndex2 + 1);
                    posyIndex1 = textStr.find(":");                
                    posyIndex2 = textStr.find(",");
                    posySize = distance (textStr.begin() + posyIndex1 + 2, textStr.begin() + posyIndex2);
                    posyTemp = textStr.substr (posyIndex1 + 2, posySize);
                    Shape_List.back()->setY(stof(posyTemp));

                    // Identify radius
                    textStr.erase(textStr.begin(), textStr.begin() + posyIndex2 + 1);
                    size1Index1 = textStr.find(":");                
                    size1Index2 = textStr.find("}");
                    size1Size = distance (textStr.begin() + size1Index1 + 2, textStr.begin() + size1Index2 - 8);
                    size1Temp = textStr.substr (size1Index1 + 2, size1Size);
                    Shape_List.back()->setSize1(stof(size1Temp));

                    // End
                    textStr.erase(textStr.begin(), textStr.begin() + size1Index2 + 2);
					cout << "textStr con lai sau khi doc Square la:" << textStr << endl << endl;
					break;
            }

			case 'R':                                                   // Rectangle
            {
                    Shape_List.push_back (FactoryShape::createShape(3));

                    // Identify name
                    textStr.erase(textStr.begin(), textStr.begin() + typeIndex2 + 1);
                    nameIndex1 = textStr.find(":");                
                    nameIndex2 = textStr.find(",");
                    nameSize = distance (textStr.begin() + nameIndex1 + 3, textStr.begin() + nameIndex2 - 1);
                    nameTemp = textStr.substr (nameIndex1 + 3, nameSize);
                    Shape_List.back()->setName(nameTemp);

                    // Identify pos x
                    textStr.erase(textStr.begin(), textStr.begin() + nameIndex2 + 1);
                    posxIndex1 = textStr.find(":");                
                    posxIndex2 = textStr.find(",");
                    posxSize = distance (textStr.begin() + posxIndex1 + 2, textStr.begin() + posxIndex2);
                    posxTemp = textStr.substr (posxIndex1 + 2, posxSize);
                    Shape_List.back()->setX(stof(posxTemp));

                    // Identify pos y
                    textStr.erase(textStr.begin(), textStr.begin() + posxIndex2 + 1);
                    posyIndex1 = textStr.find(":");                
                    posyIndex2 = textStr.find(",");
                    posySize = distance (textStr.begin() + posyIndex1 + 2, textStr.begin() + posyIndex2);
                    posyTemp = textStr.substr (posyIndex1 + 2, posySize);
                    Shape_List.back()->setY(stof(posyTemp));

                    // Identify length
                    textStr.erase(textStr.begin(), textStr.begin() + posyIndex2 + 1);
                    size1Index1 = textStr.find(":");                
                    size1Index2 = textStr.find(",");
                    size1Size = distance (textStr.begin() + size1Index1 + 2, textStr.begin() + size1Index2);
                    size1Temp = textStr.substr (size1Index1 + 2, size1Size);
                    Shape_List.back()->setSize1(stof(size1Temp));

                    // Identify width
                    textStr.erase(textStr.begin(), textStr.begin() + size1Index2 + 1);
                    size2Index1 = textStr.find(":");                
                    size2Index2 = textStr.find("}");
                    size2Size = distance (textStr.begin() + size2Index1 + 2, textStr.begin() + size2Index2 - 8);
                    size2Temp = textStr.substr (size2Index1 + 2, size2Size);
                    Shape_List.back()->setSize2(stof(size2Temp));

                    // End
                    textStr.erase(textStr.begin(), textStr.begin() + size2Index2 + 2);
					cout << "textStr con lai sau khi doc Rectangle la:" << textStr << endl << endl;
                    break;
            }

			case 'T':                                                   // Triangle
            {
                    Shape_List.push_back (FactoryShape::createShape(4));

                    // Identify name
                    textStr.erase(textStr.begin(), textStr.begin() + typeIndex2 + 1);
                    nameIndex1 = textStr.find(":");                
                    nameIndex2 = textStr.find(",");
                    nameSize = distance (textStr.begin() + nameIndex1 + 3, textStr.begin() + nameIndex2 - 1);
                    nameTemp = textStr.substr (nameIndex1 + 3, nameSize);
                    Shape_List.back()->setName(nameTemp);

                    // Identify pos x
                    textStr.erase(textStr.begin(), textStr.begin() + nameIndex2 + 1);
                    posxIndex1 = textStr.find(":");                
                    posxIndex2 = textStr.find(",");
                    posxSize = distance (textStr.begin() + posxIndex1 + 2, textStr.begin() + posxIndex2);
                    posxTemp = textStr.substr (posxIndex1 + 2, posxSize);
                    Shape_List.back()->setX(stof(posxTemp));

                    // Identify pos y
                    textStr.erase(textStr.begin(), textStr.begin() + posxIndex2 + 1);
                    posyIndex1 = textStr.find(":");                
                    posyIndex2 = textStr.find(",");
                    posySize = distance (textStr.begin() + posyIndex1 + 2, textStr.begin() + posyIndex2);
                    posyTemp = textStr.substr (posyIndex1 + 2, posySize);
                    Shape_List.back()->setY(stof(posyTemp));

                    // Identify bottom
                    textStr.erase(textStr.begin(), textStr.begin() + posyIndex2 + 1);
                    size1Index1 = textStr.find(":");                
                    size1Index2 = textStr.find(",");
                    size1Size = distance (textStr.begin() + size1Index1 + 2, textStr.begin() + size1Index2);
                    size1Temp = textStr.substr (size1Index1 + 2, size1Size);
                    Shape_List.back()->setSize1(stof(size1Temp));

                    // Identify height
                    textStr.erase(textStr.begin(), textStr.begin() + size1Index2 + 1);
                    size2Index1 = textStr.find(":");                
                    size2Index2 = textStr.find("}");
                    size2Size = distance (textStr.begin() + size2Index1 + 2, textStr.begin() + size2Index2 - 8);
                    size2Temp = textStr.substr (size2Index1 + 2, size2Size);
                    Shape_List.back()->setSize2(stof(size2Temp));

                    // End
                    textStr.erase(textStr.begin(), textStr.begin() + size2Index2 + 2);
                    cout << "textStr con lai sau khi doc Triangle la " << textStr << endl << endl;
                    break;                    
            }

			case 'E':                                                   // Ellipse
            {
                    Shape_List.push_back (FactoryShape::createShape(5));

                    // Identify name
                    textStr.erase(textStr.begin(), textStr.begin() + typeIndex2 + 1);
                    nameIndex1 = textStr.find(":");                
                    nameIndex2 = textStr.find(",");
                    nameSize = distance (textStr.begin() + nameIndex1 + 3, textStr.begin() + nameIndex2 - 1);
                    nameTemp = textStr.substr (nameIndex1 + 3, nameSize);
                    Shape_List.back()->setName(nameTemp);

                    // Identify pos x
                    textStr.erase(textStr.begin(), textStr.begin() + nameIndex2 + 1);
                    posxIndex1 = textStr.find(":");                
                    posxIndex2 = textStr.find(",");
                    posxSize = distance (textStr.begin() + posxIndex1 + 2, textStr.begin() + posxIndex2);
                    posxTemp = textStr.substr (posxIndex1 + 2, posxSize);
                    Shape_List.back()->setX(stof(posxTemp));

                    // Identify pos y
                    textStr.erase(textStr.begin(), textStr.begin() + posxIndex2 + 1);
                    posyIndex1 = textStr.find(":");                
                    posyIndex2 = textStr.find(",");
                    posySize = distance (textStr.begin() + posyIndex1 + 2, textStr.begin() + posyIndex2);
                    posyTemp = textStr.substr (posyIndex1 + 2, posySize);
                    Shape_List.back()->setY(stof(posyTemp));

                    // Identify minor
                    textStr.erase(textStr.begin(), textStr.begin() + posyIndex2 + 1);
                    size1Index1 = textStr.find(":");                
                    size1Index2 = textStr.find(",");
                    size1Size = distance (textStr.begin() + size1Index1 + 2, textStr.begin() + size1Index2);
                    size1Temp = textStr.substr (size1Index1 + 2, size1Size);
                    Shape_List.back()->setSize1(stof(size1Temp));

                    // Identify major
                    textStr.erase(textStr.begin(), textStr.begin() + size1Index2 + 1);
                    size2Index1 = textStr.find(":");                
                    size2Index2 = textStr.find("}");
                    size2Size = distance (textStr.begin() + size2Index1 + 2, textStr.begin() + size2Index2 - 8);
                    size2Temp = textStr.substr (size2Index1 + 2, size2Size);
                    Shape_List.back()->setSize2(stof(size2Temp));

                    // End
                    textStr.erase(textStr.begin(), textStr.begin() + size2Index2 + 2);
                    cout << "textStr sau khi doc Ellipse la " << textStr << endl << endl;
                    break;                    
            }
		}
    }
    fileIn.close();
    //showShape(Shape_List);
};

class Graph
{
    public:
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
                cout << "4. Write Shape into file." << endl;
                cout << "5. Get Shape from file" << endl;
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

                    case 3:
                        sortShape (ShapeList);
                        break;

                    case 4:
                    {
                        ofstream fileOut;
                        fileOut.open (outFile, ios::out);
                        writeShape (fileOut, ShapeList);
                        fileOut.close();
                        cout << "Successfully write file!" << endl;
                        break;
                    }

                    case 5:
                    {
                        readShape (inFile, ShapeList);
                        cout << "Successfully read file!" << endl;
                        break;
                    }

                    case 6:
                        break; 

                    default:
                        cout << "Enter number from 1 to 6!" << endl;
                        break;
                }
                //break;
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
