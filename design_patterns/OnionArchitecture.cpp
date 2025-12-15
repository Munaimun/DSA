#include<bits/stdc++.h>

using namespace std;

// ========================
// Core Layer - Models
// ========================
// The core layer is the center of Onion Architecture.
// It contains domain entities and business objects.
// It has no dependency on any other layer.

class Student
{
public:
    int StudentId;
    string Name;
    string Email;

    // Constructor using member initializer list
    Student(int id, string name, string email)
        : StudentId(id), Name(name), Email(email) {}
};

class Trainer
{
public:
    int TrainerId;
    string Name;
    string Email;
};

class Course
{
public:
    int CourseId;
    string Name;
    string Description;
};

// ========================
// Fake Database (Infrastructure support)
// ========================
// This simulates a database for demonstration purposes.
// In real applications, this could be a SQL database, NoSQL, etc.
// Note: Database is in outer layer, not in the core.

class Database
{
public:
    vector<shared_ptr<Student>> students;
    vector<shared_ptr<Course>> courses;
    vector<shared_ptr<Trainer>> trainers;
};

// ========================
// Interfaces (Abstract Classes) - Core Layer
// ========================
// Interfaces define contracts for repositories and services.
// Outer layers implement these interfaces. 
// Core depends on nothing, outer layers depend on core.

class IStudentRepository
{
public:
    virtual void AddStudent(shared_ptr<Student> student) = 0;
    virtual void RemoveStudent(shared_ptr<Student> student) = 0;
    virtual shared_ptr<Student> UpdateStudent(shared_ptr<Student> student) = 0;
    virtual vector<shared_ptr<Student>> GetAllStudents() = 0;
    virtual ~IStudentRepository() = default; // virtual destructor
};

// ========================
// Infrastructure Layer - Repositories
// ========================
// Implements repository interfaces defined in core.
// This layer interacts with database or any external data source.
// Depends on Core Layer (entities and interfaces) but Core does NOT depend on it.

class StudentRepository : public IStudentRepository
{
private:
    Database *db; // Dependency on database (outer layer)

public:
    StudentRepository(Database *database) : db(database) {}

    void AddStudent(shared_ptr<Student> student) override
    {
        cout << "StudentRepository.AddStudent()" << endl;
        db->students.push_back(student); // Add student to fake DB
    }

    void RemoveStudent(shared_ptr<Student> student) override
    {
        db->students.erase(remove(db->students.begin(), db->students.end(), student), db->students.end());
    }

    shared_ptr<Student> UpdateStudent(shared_ptr<Student> student) override
    {
        // Normally, update logic goes here (search & modify)
        return student;
    }

    vector<shared_ptr<Student>> GetAllStudents() override
    {
        return db->students; // Return all students
    }
};

// ========================
// Service Layer - Business Logic Layer
// ========================
// Services implement business rules.
// They use repositories to interact with data.
// Service layer depends on core interfaces, not concrete database.

class IStudentService
{
public:
    virtual void AddStudent(shared_ptr<Student> student) = 0;
    virtual void RemoveStudent(shared_ptr<Student> student) = 0;
    virtual shared_ptr<Student> UpdateStudent(shared_ptr<Student> student) = 0;
    virtual vector<shared_ptr<Student>> GetAllStudents() = 0;
    virtual ~IStudentService() = default;
};

class StudentService : public IStudentService
{
private:
    IStudentRepository *studentRepository; // Depends on repository interface

public:
    StudentService(IStudentRepository *repo) : studentRepository(repo) {}

    void AddStudent(shared_ptr<Student> student) override
    {
        cout << "StudentService.AddStudent()" << endl;
        // Additional business logic can be added here
        studentRepository->AddStudent(student);
    }

    void RemoveStudent(shared_ptr<Student> student) override
    {
        studentRepository->RemoveStudent(student);
    }

    shared_ptr<Student> UpdateStudent(shared_ptr<Student> student) override
    {
        return studentRepository->UpdateStudent(student);
    }

    vector<shared_ptr<Student>> GetAllStudents() override
    {
        return studentRepository->GetAllStudents();
    }
};

// ========================
// Presentation Layer - Controller
// ========================
// The outermost layer interacts with the user or frontend.
// It depends on services (business logic) but core is independent.
// Controllers call services to perform operations.

class StudentController
{
private:
    IStudentService *studentService;

public:
    StudentController(IStudentService *service) : studentService(service) {}

    void AddStudent(shared_ptr<Student> student)
    {
        cout << "StudentController.AddStudent()" << endl;
        studentService->AddStudent(student);
    }

    void RemoveStudent(shared_ptr<Student> student)
    {
        studentService->RemoveStudent(student);
    }

    shared_ptr<Student> UpdateStudent(shared_ptr<Student> student)
    {
        return studentService->UpdateStudent(student);
    }

    vector<shared_ptr<Student>> GetAllStudents()
    {
        return studentService->GetAllStudents();
    }
};

// ========================
// Main Function - Entry Point
// ========================

int main()
{
    Database db; // Fake database

    // Setup repository, service, controller
    StudentRepository studentRepo(&db);
    StudentService studentService(&studentRepo);
    StudentController studentController(&studentService);

    // Create students
    auto student1 = make_shared<Student>(1, "Shahriar", "shahriar@gmail.com");
    auto student2 = make_shared<Student>(2, "Shahriar2", "shahriar2@gmail.com");

    // Add students via controller
    studentController.AddStudent(student1);
    studentController.AddStudent(student2);

    cout << "------------------------------" << endl;
    cout << "Students Added" << endl;
    cout << "------------------------------" << endl;

    // Display students
    auto students = studentController.GetAllStudents();
    for (auto &s : students)
    {
        cout << "Student Details:" << endl;
        cout << "ID: " << s->StudentId << endl;
        cout << "Name: " << s->Name << endl;
        cout << "Email: " << s->Email << endl;
        cout << "------------------------------" << endl;
    }

    return 0;
}
