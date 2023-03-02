#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;
class Classroom;
class School;

string randomString(int len)
{
    // A function to generate random strings of length -->
    // "len"
    string str;
    for (int i = 0; i < len; i++)
    {
        char ch = 'A' + rand() % 26;
        str.push_back(ch);
    }
    return str;
}

float randomFloat(float start, float end)
{
    float range = end - start;
    float random_value = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    return start + (random_value * range);
}

class Student
{
private:
    string _studentname;
    float _diemTB;

public:
    void getter()
    {
        _studentname = randomString(10);
        _diemTB = randomFloat(0.0, 10.0);
    }
    string getStudentName()
    {
        return _studentname;
    }
    float getDiem()
    {
        return _diemTB;
    }
};

class Classroom
{
private:
    string _classname;
    int _number;
    vector<Student> _membersList;

public:
    void addStudent(Student student)
    {
        _membersList.push_back(student);
    }
    string getClassname()
    {
        return _classname;
    }
    int getNumber()
    {
        return _number;
    }
    // Student getMembersList()
    // {
    //     return _membersList;
    // }

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
class School
{
private:
    int _classnumber;
    vector<Classroom> _classList;

public:
    void addClass(Classroom classroom)
    {
        _classList.push_back(classroom);
    }
    int getClassnumber()
    {
        return _classnumber;
    }
    // vector<Classroom> getClasslist()
    // {
    //     return _classList;
    // }
    void setClassnumber(int value)
    {
        _classnumber = value; //=5
    }

    vector<Classroom> getClassList()
    {
        return _classList;
    }
};

int main()
{
    int classNum = 3;
    int studentNum;

    School school;
    Student student;
    string className;

    school.setClassnumber(classNum);

    for (int i = 0; i < school.getClassnumber(); i++)
    {
        Classroom classroom;
        cout << "\n---------------------------------\n";
        cout << "\nClass " << i + 1;
        cout << "\nEnter student numbers: ";
        cin >> studentNum;
        cout << "\nEnter class name: ";
        cin.ignore();
        getline(cin, className);
        classroom.setNumber(studentNum);
        classroom.setClassname(className);

        for (int j = 0; j < classroom.getNumber(); j++)
        {
            student.getter();
            classroom.addStudent(student);
        }

        school.addClass(classroom);
    }

    // cout << school.getClassnumber() << endl;

    // Duyet tung sinh vien
    for (int i = 0; i < school.getClassnumber(); i++)
    {
        cout << "\n--------------" << school.getClassList().at(i).getClassname() << "----------------\n";
        for (int j = 0; j < school.getClassList().at(i).getNumber(); j++)
        {
            cout << "-" << school.getClassList().at(i).getStudentList().at(j).getStudentName() << "-" << school.getClassList().at(i).getStudentList().at(j).getDiem() << endl;
        }
    }

    // cout << school.getClassList().at(0).;
    return 0;
}
