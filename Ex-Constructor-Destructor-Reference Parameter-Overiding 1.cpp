// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
class Shape
{
private:
    // thành viên private chỉ có thể được truy cập bởi các hàm nằm trong lớp
    int pos_x, pos_y;
    int front_color, back_color;
    // one shape can be connected to one other shape 
    // pointer to the connected shape 
    Shape* connected_shape; 
    std::string name; // name of shape

public:
    // thành viên public có thể được truy cập từ bên ngoài thông qua toán tử ., -> 
    void print();
    std::string get_name() { // inline function 
        return name;
    }
    void set(int x, int y, int front_color, int back_color);
    void set_name(std::string n) {
        name = n;
    }
    // constructor function 
    Shape();
    
    Shape(int x, int y, int front_color, int back_color, std::string n, Shape connected_s);
    // connected_s là một tham số tới đối tượng kiểu Shape => connected_s sẽ được copy thành bản sao 
    // trong hàm Shape(int x, int y, int front_color, int back_color, std::string n, Shape connected_s)
    
    
    Shape(const Shape& s);
    // Hàm tạo copy
    // s là một tham biến tới đối tượng kiểu Shape -> s không được copy thành bản sao trong hàm Shape(const Shape& s)
    // khi truyền tham chiếu vào hàm thì sẽ không tạo ra biến/đối tượng cục bộ trong hàm
    // hàm sẽ truy cập trực tiếp vào biến/đối tượng của hàm gọi 

    // Chú ý: Khi truyền 1 đối tượng vào hàm nên truyền bằng phương pháp tham biến để không sinh các lời gọi 
    // hàm constructor/destructor dư thừa 
    
    // Hàm hủy
    ~Shape();

    // Overriding operator: ghi đè toán tử dùng để triển khai các toán tử tùy biến trên kiểu dữ liệu class 
    Shape operator+(Shape& s);
};
Shape Shape::operator+(Shape& s)
{
    Shape res;
    std::cout << "Operator +:\n";
    res.set(pos_x + s.pos_x, pos_y + s.pos_y, s.front_color, s.back_color);
    res.set_name(name + "+" + s.name);
    return res;
}
void Shape::print()
{
    std::cout << name << ";position: (" << pos_x << "," << pos_y << ")"
        << ";color:front=" << front_color << ";background=" << back_color;
    if (connected_shape)
        std::cout << ";connect to " << connected_shape->get_name() << std::endl;
    else
        std::cout << ";connect to nothing" << std::endl;
}
void Shape::set(int x, int y, int front_color, int back_color)
{
    pos_x = x; pos_y = y; front_color = front_color; back_color = back_color;
}
Shape::Shape()
{
    std::cout << "default constructor\n";
    pos_x = 0; pos_y = 0; front_color = 0x000000; back_color = 0xFFFFFF;
    name = "noname";
    connected_shape = NULL;
}

Shape::Shape(int x, int y, int front_color, int back_color, std::string n, Shape connected_s)

// Hàm tạo được tự động gọi khi khai báo đối tượng của lớp 
{
    std::cout << "full parameter constructor of " << n << "\n";
    pos_x = x; pos_y = y; front_color = front_color; back_color = back_color;
    name = n; 
    // tạo ra 1 con trỏ lớp Shape với các giá trị biến thành viên lấy
    // từ đối tượng connected_s 
    connected_shape = new Shape(connected_s); 
    // Output:
    // copy constructor of copy - main a --> hàm copy constructor được gọi khi toán tử new được dùng 
    // để tạo ra con trỏ connected_shape (lấy dữ liệu từ bản sao của a) (copy copy main a)
   
    // chú ý ở đây tạo ra một đối tượng mới lấy dữ liệu của connected_s
    connected_shape->set_name("pointer " + connected_shape->get_name());

    // Hãy đặt tên cho connected_s là bản sao của tham số được truyền vào hàm Shape
    // và quan sát đối tượng bản sao bị hủy bằng hàm hủy ~Shape 

}
// hàm hủy được sử dụng để giải phóng bộ nhớ được cấp phát cho 
// các biến thành viên của lớp 
// hàm hủy được tự động gọi khi đối tượng của lớp được giải phóng
// (khi kết thúc hàm mà đối tượng được khai báo 
// hoặc khi dùng toán tử delete để giải phóng bộ nhớ dành cho đối tượng 
Shape::~Shape() 
{
    std::cout << "Destructor function for " << name << std::endl; 
    if (connected_shape) {
        delete connected_shape;
        connected_shape = NULL;
    }
}
Shape::Shape(const Shape& s)
{
    std::cout << "copy constructor of " << s.name << "\n";
    pos_x = s.pos_x;
    pos_y = s.pos_y;
    name = "copy-" + s.name;
    front_color = s.front_color;
    back_color = s.back_color;
    connected_shape = NULL; // chú ý không để Shape mới tạo nối đến connected shape của bản gốc 
}

int main()
{
    Shape a; // Output: default constructor

    a.set_name(std::string("main a"));
    
    Shape c(50, 50, 0x00FF00, 0xFFFFFF, std::string("c"), a);
    // copy constructor of main a --> hàm copy constructor được gọi để tạo ra bản sao cho a (copy-main-a)
    // full parameter constructor of c --> hàm full parameter constructor được gọi để tạo ra c 
    // copy constructor of copy - main a --> hàm copy constructor được gọi khi toán tử new được dùng 
    // để tạo ra con trỏ connected_shape (lấy dữ liệu từ bản sao của a) (copy copy main a)
    // Destructor function for copy - main a --> kết thúc hàm Shape c(...) -> hàm destructor được gọi để 
    // xóa bản sao copy-main a 
    Shape d(c);
    // Output: copy constructor of c --> hàm copy constructor được gọi để tạo ra d là bản sao của c

    std::cout << "Hello World!\n";
    // Output: Hello World!      
        
    a.print();
    // Output: main a; position: (0, 0); color:front = 0; background = 16777215; connect to nothing  
    c.print();
    // Output: c; position: (50, 50); color:front = 0; background = 0; connect to pointer copy - copy - main a
    d.print();
    // Output: copy - c; position: (50, 50); color:front = 0; background = 0; connect to nothing     
    
    Shape e = a + c;
    e.print();
    
    
    // Destructor function for copy - c -> Hàm destructor của d được gọi (chú ý d là copy của c)
    // Destructor function for c -> Hàm destructor của c được gọi 
    // Destructor function for pointer copy - copy - main a -> hàm destructor của connected_shape trong c được gọi 
    // khi toán tử delete connected_shape được gọi 
    // Destructor function for main a -> Hàm destructor của a được gọi 
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
