#include <iostream>
#include <vector>
#include <string>

using namespace std;


// make a class for student so i can store the information
class default_student{
    public:
    string first_name;
    string last_name;
    string gender;

    default_student(string first_name, string last_name, string gender){
        this -> first_name = first_name;
        this -> last_name = last_name;
        this -> gender = gender;
    }
};


// so i can store the students inside 
class default_class{
    public:
    string class_name;
    string branch;
    vector<default_student> students;

    default_class(string class_name, string branch){
        this -> class_name = class_name;
        this -> branch = branch;
    }
    // function for adding to the vector of students
    void add_student(default_student& student){
        students.push_back(student);
    }

    // function for displaying the students in a class  
    void display_students(){
        size_t vector_size = students.size();
        cout << "******************************" << endl
             << "class name: " << class_name << endl
             << "branch: " << branch << endl;
        for(size_t i = 0; i < vector_size; i++){
            const default_student& student = students[i];
            cout << "******************************" << endl
                 << "first name: " << student.first_name << endl
                 << "last name: " << student.last_name << endl
                 << "gender: " << student.gender << endl
                 << "******************************" << endl << endl;
            
        }
    }


    // need to make a function to add the students from here
    void create_student(){
        default_class class_401("class_401", "math");
        string first_name;
        string last_name;
        string gender;
        cout << "enter the first name of the student: \n";
        cin >> first_name;
        cout << "enter the last name: \n";
        cin >> last_name;
        cout << "enter the gender: \n";
        cin >> gender;
        default_student student(first_name , last_name, gender);
        add_student(student);
    }


    
};
// make a school class so i can add the classes to the new vector
class default_school{
    public:
    string school_name;
    string grade;
    vector<default_class> classes;


    default_school(string school_name, string grade){
        this -> school_name = school_name;
        this -> grade = grade;
    }

    // funtion so i can add new classes to the vector
    void add_class(default_class& new_class){
        classes.push_back(new_class);
    }


    // make a function so i can create a new class
    void create_class(){
        string class_name;
        string branch;
        cout << "enter the name of the class: ";
        cin >> class_name;
        cout << "enter the branch of the class: ";
        cin >> branch;
        default_class new_class(class_name, branch);
        add_class(new_class);
    }

    void display_classes(){
        size_t vector_size = classes.size();
        cout << "******************************" << endl
             << "class name: " << school_name << endl
             << "branch: " << grade << endl;
        for(size_t i = 0; i < vector_size; i++){
            const default_class& new_class = classes[i];
            cout << "******************************" << endl
                 << "class name: " << new_class.class_name << endl
                 << "branch: " << new_class.branch << endl
                 << "******************************" << endl << endl;
            
        }

    }
    
};


int main(){
    int choise;
    bool exit = true;
    // difine the school
    default_school school("navab", "highshcool");
    // define the classes
    default_class class_401("class_401", "math");
    default_class class_402("class_402", "science");
    default_class class_403("class_403", "arts");
    // put the clsses in the vector
    school.add_class(class_401);
    school.add_class(class_402);
    school.add_class(class_403);
    // define the students
    default_student shayan("shayan", "hamidian", "male");
    default_student mohamad("mohamad", "moradi", "male");
    default_student iman("iman", "moradi", "male");
    default_student sara("sara", "sepahvand", "female");
    default_student maryam("maryam", "soltani", "female");
    default_student ali("ali", "kamali", "male");
    // add them to the classes
    class_401.add_student(shayan);
    class_401.add_student(mohamad);
    class_402.add_student(iman);
    class_402.add_student(sara);
    class_403.add_student(maryam);
    class_403.add_student(ali);
    // i need to create a loop so you can stay in the program for as long as you want
    while(exit == true){
        // get input to display the class
        cout << "what funtion do you want to acces(1/2/3/4/5/6):\n"
            << "1_class 401\n"
            << "2_class 402\n"
            << "3_class 403\n"
            << "4_add class\n"
            << "5_add student\n"
            << "6_exit\n";
        cin >> choise;
        // switch so i can display the class based on the input
        switch(choise){
            case 1:
            class_401.display_students();
            break;
            case 2:
            class_402.display_students();
            break;
            case 3:
            class_403.display_students();
            break;
            case 4:
            school.create_class();
            school.display_classes();
            break;
            case 5:
            class_401.create_student();
            class_401.display_students();
            case 6:
            exit = false;
            cout << "{{goodbye}}\n";
            break;
            default:
            cout << "invalid input\n";
            break;
        };
    }
    return 0;
    }
