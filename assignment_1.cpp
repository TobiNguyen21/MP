#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

// create class Student
class Student
{
private:
    string _studentname;
    float _diemTB;
    int _id;

public:
    virtual void createStudent(int index);
    bool checkExcellent()
    {
        if (_diemTB > 8.0)
        {
            return true;
        }
        return false;
    }
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

    string getStudentName() { return _studentname; }
    float getDiem() { return _diemTB; }
    int getID() { return _id; }
};

// create class Classrom
class Classroom
{
private:
    string _classname;
    int _number;
    vector<Student> _membersList;

public:
    virtual void createClassRoom(int index);
    virtual bool check_5ExcellentStudent();
    virtual Student find_ExcellentStudent(); // The student with the highest grade
    // void addStudent(Student student)
    // {
    //     _membersList.push_back(student);
    // }

    string getClassname() { return _classname; }

    int getNumber() { return _number; }

    void setClassname(string value) { _classname = value; }

    void setNumber(int value) { _number = value; }

    vector<Student> getStudentList() { return _membersList; }
};

// create class school
class School
{
private:
    int _classnumber;
    vector<Classroom> _classList;

public:
    virtual void createSchool();
    virtual void printSchool();
    virtual vector<string> printClass_5ExcellentStudent();
    virtual string printClass_TheLargestNumber();
    virtual string printClass_TheSmallestNumber();
    virtual void printStudent_Excellent();

    int getClassnumber() { return _classnumber; }

    void setClassnumber(int value) { _classnumber = value; } //=5

    vector<Classroom> getClassList() { return _classList; }
};

// Method of class Student
void Student::createStudent(int index)
{
    string studentName;
    float grade;
    int id;

    cout << "\nEnter Student " << index + 1 << ": ";
    cin.ignore();
    getline(cin, studentName);

    cout << "Grade: ";
    cin >> grade;

    cout << "ID: ";
    cin >> id;

    _studentname = studentName;
    _diemTB = grade;
    _id = id;
}

// Method of class Classroom
void Classroom::createClassRoom(int index)
{
    string className;
    int studentNum;

    cout << "\n---------------------------------\n";
    cout << "\nClass " << index + 1;
    cout << "\nEnter class name: ";
    cin.ignore();
    getline(cin, className);
    cout << "\nEnter capacity of class: ";
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

bool Classroom::check_5ExcellentStudent()
{
    int cout = 0;
    for (auto &student : _membersList)
    {
        if (student.checkExcellent())
            cout++;
    }
    if (cout > 5)
        return true;
    return false;
}

Student Classroom::find_ExcellentStudent()
{
    float maxGrade = _membersList.at(0).getDiem();
    for (auto &student : _membersList)
    {
        if (student.getDiem() > maxGrade)
        {
            maxGrade = student.getDiem();
        }
    }

    for (auto &student : _membersList)
    {
        if (student.getDiem() == maxGrade)
        {
            return student;
        }
    }
    return {};
}

// Method of class School
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
            cout << student.getID() << "-" << student.getStudentName() << "-" << student.getDiem() << endl;
        }
    }
}

vector<string> School::printClass_5ExcellentStudent()
{
    vector<string> listClass_5ExcellentStudent = {};
    for (auto &classroom : _classList)
    {
        if (classroom.check_5ExcellentStudent())
        {
            listClass_5ExcellentStudent.push_back(classroom.getClassname());
        }
    }
    return listClass_5ExcellentStudent;
}

string School::printClass_TheLargestNumber()
{
    int max = _classList.at(0).getNumber();
    for (auto &classroom : _classList)
    {
        if (classroom.getNumber() > max)
        {
            max = classroom.getNumber();
        }
    }
    for (auto &classroom : _classList)
    {
        if (classroom.getNumber() == max)
        {
            return classroom.getClassname();
        }
    }
    return NULL;
}

string School::printClass_TheSmallestNumber()
{
    int min = _classList.at(0).getNumber();
    for (auto &classroom : _classList)
    {
        if (classroom.getNumber() < min)
        {
            min = classroom.getNumber();
        }
    }
    for (auto &classroom : _classList)
    {
        if (classroom.getNumber() == min)
        {
            return classroom.getClassname();
        }
    }
    return NULL;
}

////>> The student with the highest grade
void School::printStudent_Excellent()
{
    vector<Student> resultExcellentOfClassroom;
    for (auto &classroom : _classList)
    {
        resultExcellentOfClassroom.push_back(classroom.find_ExcellentStudent());
    }
    float max = resultExcellentOfClassroom.at(0).getDiem();
    for (auto &item : resultExcellentOfClassroom)
    {
        if (item.getDiem() > max)
        {
            max = item.getDiem();
        }
    }
    for (auto &item : resultExcellentOfClassroom)
    {
        if (item.getDiem() == max)
        {
            cout << "The student with the highest grade: " << item.getStudentName() << " ID:" << item.getID();
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

    cout << "\n------------------------------------------\n";
    cout << "Class with more than 5 excellent students: ";
    for (auto &item : school.printClass_5ExcellentStudent())
    {
        cout << item << ", ";
    }

    cout << "\n------------------------------------------\n";
    cout << "Class with the largest number: " << school.printClass_TheLargestNumber();

    cout << "\n------------------------------------------\n";
    cout << "Class with the smallest number: " << school.printClass_TheSmallestNumber();

    cout << "\n------------------------------------------\n";
    school.printStudent_Excellent();

    cout << "\n------------------------------------------\n";
    school.printSchool();
    return 0;
}
