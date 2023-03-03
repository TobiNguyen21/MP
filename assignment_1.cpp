#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;
class Classroom;
class School;

// string randomString(int len)
// {
//     // A function to generate random strings of length -->
//     // "len"
//     string str;
//     for (int i = 0; i < len; i++)
//     {
//         char ch = 'A' + rand() % 26;
//         str.push_back(ch);
//     }
//     return str;
// }

// float randomFloat(float start, float end)
// {
//     float range = end - start;
//     float random_value = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
//     return start + (random_value * range);
// }

class Student
{
private:
    string _studentname;
    float _diemTB;

public:
    virtual void createStudent(int index);

    // void getter()
    // {
    //     _studentname = randomString(5);
    //     _diemTB = randomFloat(0.0, 10.0);
    // }

    // void setter(string studentName, float grade)
    // {
    //     _studentname = studentName;
    //     _diemTB = grade;
    // }

    string getStudentName()
    {
        return _studentname;
    }
    float getDiem()
    {
        return _diemTB;
    }
};

class Classroom : public Student
{
private:
    string _classname;
    int _number;
    vector<Student> _membersList;

public:
    virtual void createClassRoom(int index);

    // void addStudent(Student student)
    // {
    //     _membersList.push_back(student);
    // }

    string getClassname()
    {
        return _classname;
    }

    int getNumber()
    {
        return _number;
    }

    void setClassname(string value)
    {
        _classname = value;
    }

    void setNumber(int value)
    {
        _number = value;
    }

    vector<Student> getStudentList()
    {
        return _membersList;
    }
};

// create class school
class School : public Classroom
{
private:
    int _classnumber;
    vector<Classroom> _classList;

public:
    virtual void createSchool();
    virtual void printSchool();

    // void addClass(Classroom classroom)
    // {
    //     _classList.push_back(classroom);
    // }

    int getClassnumber()
    {
        return _classnumber;
    }

    void setClassnumber(int value)
    {
        _classnumber = value; //=5
    }

    vector<Classroom> getClassList()
    {
        return _classList;
    }
};

void Student::createStudent(int index)
{
    string studentName;
    float grade;
    // student.getter();
    cout << "\nEnter Student " << index + 1 << ": ";
    cin.ignore();
    getline(cin, studentName);
    cout << "Grade: ";
    cin >> grade;
    _studentname = studentName;
    _diemTB = grade;
}

void Classroom::createClassRoom(int index)
{
    string className;
    int studentNum;
    cout << "\n---------------------------------\n";
    cout << "\nClass " << index + 1;
    cout << "\nEnter class name: ";
    cin.ignore();
    getline(cin, className);
    cout << "\nEnter student numbers: ";
    cin >> studentNum;
    _number = studentNum;
    _classname = className;

    for (int j = 0; j < _number; j++)
    {
        Student student;
        student.createStudent(j);
        // addStudent(student);
        _membersList.push_back(student);
    }
}

void School::createSchool()
{

    for (int i = 0; i < _classnumber; i++)
    {
        Classroom classroom;
        classroom.createClassRoom(i);
        _classList.push_back(classroom);
    }
}

void School::printSchool()
{
    for (auto &classroom : _classList)
    {
        cout << "\n--------------" << classroom.getClassname() << "----------------\n";
        for (auto &student : classroom.getStudentList())
        {
            cout << student.getStudentName() << "-" << student.getDiem() << endl;
        }
    }
}

int main()
{
    int classNum;
    cout << "\n Class Number: ";
    cin >> classNum;

    School school;
    school.setClassnumber(classNum);
    school.createSchool();
    school.printSchool();
    return 0;
}
