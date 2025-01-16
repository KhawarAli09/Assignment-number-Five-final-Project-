#include<iostream> 
#include<string>   
#include<iomanip>
using namespace std;

int i = 3;

struct student {
    int ID;
    string  f_name,l_name, father_name , address, phone, email, course, sem;
    char grade;
    float marks, cgpa ,gpa , m_pf, m_ds , m_ict , m_english , m_isl;
    string  name = f_name + " " + l_name;
} s[100] = {
   {1, "Khawar", "Ali","M. Zaroob", "B-17", "9876543210", "khawar123@gmail.com", "Computer Science", "1", 'A', 457, 3.8, 3.8, 95, 89, 88, 90, 95, "Khawar Ali"},
    {2, "Muhammad", "Tayyab","Alyas", "B-17", "9123456789", "tayyab123@gmail.com", "Cyber Security", "2", 'B', 457, 3.2, 3.2, 80, 89, 88, 90, 95},
    {3, "Amish", "Ali", "B-17","M. Zaroob", "9988776655", "amish123@gmail.com", "Software Engineering", "3", 'C', 457, 2.6, 2.6, 65, 89, 88, 90, 95},
};

void menu();
void manu_choice(int);;
void display_student_details(const student &s) ;
void search_manu();
void marks_avg();
void search_students_by_name();
void manu_choice(int a);
void search_std();
void search_student_by_first_name();
void search_by_cgpa();
void search_by_father_name();
void sort_students_by_cgpa() ;
void sort_students_by_name();
void search_students_by_last_name();
void display_students_by_semester();
void find_students_by_grade();
void calculate_avg_marks_cgpa();
void top_performers();
void show_all_students();
void display_all_details();
void delete_record();
void update_record();
void search_record();
void insert_student();

int main() {
    while (true) {
        int choice;
        menu();
        cout << "\n\n Enter your choice: ";
        cin >> choice;
        manu_choice(choice);
           
    }
    return 0;
}

void display_student_details(const student &s) {
    cout<<"\n------------------------------------";
    cout << "\n ID: " << s.ID;
    cout << "\n Name: " <<s.name;
    cout << "\n Father Name: " << s.father_name;
    cout << "\n Address: " << s.address;
    cout << "\n Phone: " << s.phone;
    cout << "\n Email: " << s.email;
    cout << "\n Semester: " << s.sem;
    cout << "\n Department: " << s.course;
    cout << "\n Marks of PF: " << s.m_pf;
    cout << "\n Marks of DS: " << s.m_ds;
    cout << "\n Marks of ICT: " << s.m_ict;
    cout << "\n Marks of English: " << s.m_english;
    cout << "\n Marks of ISL: " << s.m_isl;
    cout << "\n Total Marks: " << s.marks;
    cout << "\n CGPA: " << s.cgpa;
    cout << "\n GPA: " << s.gpa;
    cout << "\n Grade: " << s.grade;
    cout<<"\n------------------------------------\n\n";
}

void insert_student() {
    cout << "\n***Insert record***";
    cout << "\nEnter ID: ";
    cin >> s[i].ID;
    cin.ignore(); 
    cout << "Enter first Name: ";
    cin >> s[i].f_name;
    cout << "Enter last Name: ";
    cin.ignore(); 
    getline(cin, s[i].l_name);
    s[i].name = s[i].f_name + " " + s[i].l_name;
    cout << "Enter Father Name: ";
    getline(cin, s[i].father_name);
    cout << "Enter Address: ";
    getline(cin, s[i].address);
    cout << "Enter Phone: ";
    cin >> s[i].phone;
    cout << "Enter Email: ";
    cin >> s[i].email;
    cout << "Enter Semester: ";
    cin >> s[i].sem;
    cin.ignore();
    cout << "Enter Department: ";
    getline(cin, s[i].course);
    cout << "Enter Marks of PF: ";
    cin >> s[i].m_pf;
    cout << "Enter Marks of DS: ";
    cin >> s[i].m_ds;
    cout << "Enter Marks of ICT: ";
    cin >> s[i].m_ict;
    cout << "Enter Marks of English: ";
    cin >> s[i].m_english;
    cout << "Enter Marks of ISL: ";
    cin >> s[i].m_isl;
    s[i].marks = s[i].m_pf + s[i].m_ds + s[i].m_ict + s[i].m_english + s[i].m_isl;
    s[i].gpa = ((s[i].m_pf + s[i].m_ds + s[i].m_ict + s[i].m_english + s[i].m_isl) / 500)*4;

   
    s[i].cgpa = (s[i].marks / 500.0) * 4;

    if (s[i].cgpa >= 3.5) {
        s[i].grade = 'A';
    } else if (s[i].cgpa >= 3.0) {
        s[i].grade = 'B';
    } else if (s[i].cgpa >= 2.5) {
        s[i].grade = 'C';
    } else if (s[i].cgpa >= 2.0) {
        s[i].grade = 'D';
    } else {
        s[i].grade = 'F';
    }

    i++;
    cout << "\n\n ***Record Inserted Successfully***";
}

void search_record() {
    cout << "\n\n ***Search Record***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        int id, found = 0;
        cout << "\n\n Enter Student ID: ";
        cin >> id;

        
        for (int j = 0; j < i; j++) {
            if (s[j].ID == id) {
                
                display_student_details(s[j]);
                found = 1;
                break;
            }
        }

        if (!found) {
            cout << "\n\n ***No Record Found***";
        }
    }
}

void update_record() {
    cout << "\n ***Update Record***";
    if (i == 0) {
        cout << "\n ***No Record Found***";
    } else {
        int id, found = 0;
        cout << "\n Enter Student ID: ";
        cin >> id;
        for (int j = 0; j < i; j++) {
            if (s[j].ID == id) {
                cout << "\n ***Current Record***";
                display_student_details(s[j]);

                cin.ignore(); 
                cout << "\n Enter New Name: ";
                getline(cin, s[j].name);
                cout << "\n Enter New Address: ";
                getline(cin, s[j].address);
                cout << "\n Enter New Phone: ";
                cin >> s[j].phone;
                cout << "\n Enter New Email: ";
                cin >> s[j].email;
                cout << "\n Enter New Semester: ";
                cin >> s[j].sem;
                cout << "\n Enter New Course: ";
                cin >> s[j].course;
                cout << "\n Enter New Marks: ";
                cin >> s[j].marks;
                s[j].cgpa = (s[j].marks / 100.0) * 4;
                if (s[j].cgpa >= 3.5) {
                    s[j].grade = 'A';
                } else if (s[j].cgpa >= 3.0) {
                    s[j].grade = 'B';
                } else if (s[j].cgpa >= 2.5) {
                    s[j].grade = 'C';
                } else if (s[j].cgpa >= 2.0) {
                    s[j].grade = 'D';
                } else {
                    s[j].grade = 'F';
                }

                cout << "\n ***Record Updated Successfully***";
                found = 1;
                break;
            }
        }

        if (!found) {
            cout << "\n ***No Record Found***";
        }
    }
}

void delete_record() {
    cout << "\n\n ***Delete Record***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        int id, found = 0;
        cout << "\n\n Enter Student ID: ";
        cin >> id;
        for (int j = 0; j < i; j++) {
            if (s[j].ID == id) {
                display_student_details(s[j]);
                found = 1;
                for (int k = j; k < i - 1; k++) {
                    s[k] = s[k + 1];
                }
                i--; 
                cout << "\n\n ***Record Deleted Successfully***";
                break;
            }
        }

        if (!found) {
            cout << "\n\n ***No Record Found***";
        }
    }
}

void display_all_details() {
    cout << "\n\n ***Display All Student Details***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        for (int j = 0; j < i; j++) {
            display_student_details(s[j]);
        }
    }
}

void show_all_students() {
    cout << "\n\n ***Show All Students***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        for (int j = 0; j < i; j++) {
            display_student_details(s[j]);
        }
        return;
    }
}

void top_performers() {
    cout << "\n\n ***Top Performers***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        for (int j = 0; j < i; j++) {
            
            if (s[j].grade == 'A') {
                display_student_details(s[j]);
            }
        }
    }
}

void calculate_avg_marks_cgpa() {
    cout << "\n\n ***Calculate Average Marks and CGPA***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        float total_marks = 0, total_cgpa = 0;
        for (int j = 0; j < i; j++) {
            total_marks += s[j].marks;
            total_cgpa += s[j].cgpa;
        }
       
        cout << "\n\n Average Marks: " << setprecision(2) << fixed << total_marks / i;
        cout << "\n\n Average CGPA: " << setprecision(2) << fixed << total_cgpa / i;
    }
}

void find_students_by_grade() {
    cout << "\n\n ***Find Students by Grade***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        char grade;
        bool is_found = false;
        int index = -1;
        cout << "\n\n Enter Grade: ";
        cin >> grade;
        for (int j = 0; j < i; j++) {
            if (s[j].grade == grade) {
                is_found = true;
                index = j;
            }
        }
        if(is_found){
            display_student_details(s[index]);
        }
        else{
            cout << "\n\n ***No Record Found***";
    }
    }
}

void display_students_by_semester() {
    cout << "\n\n ***Display Students by Semester***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        string sem;
        bool is_found = false;
        int index = -1;
        cout << "\n\n Enter Semester: ";
        cin >> sem;
        for (int j = 0; j < i; j++) {
            if (s[j].sem == sem) {
                is_found = true;
                index = j;
            }
           
        }
        if(is_found){
            display_student_details(s[index]);
        }
        else{
            cout << "\n\n ***No Record Found***";
        }
    }
}

void search_student_by_first_name() {
    cout << "\n\n ***Search Students by first Name***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        string f_name;
        int index = -1;
        bool is_found = false;
        cout << "\n\n Enter first Name: ";
        cin >> f_name;
        for (int j = 0; j < i; j++) {
            if (s[j].f_name == f_name) {
                is_found = true;
                index = j;
            }
            
        }
        if(is_found){
            display_student_details(s[index]);
        }
        else{
            cout << "\n\n ***No Record Found***";
    }
}
}

void search_students_by_last_name() {
    cout << "\n\n ***Search Students by last Name***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        string l_name;
        bool is_found = false;
        int index = -1;
        cout << "\n\n Enter last Name: ";
        cin >> l_name;
        for (int j = 0; j < i; j++) {
            if (s[j].l_name == l_name) {
                is_found = true;
                index = j;
            
            }
           
        }
        if(is_found){
            display_student_details(s[index]);
        }
        else{
            cout << "\n\n ***No Record Found***";
    }
}
}

void sort_students_by_name() {
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        for (int j = 0; j < i - 1; j++) {
            for (int k = 0; k < i - j - 1; k++) {
                if (s[k].name > s[k + 1].name) {
                    student temp = s[k];
                    s[k] = s[k + 1];
                    s[k + 1] = temp;
                }
            }
        }
        cout << "\n\n ***Students Sorted by Name***";
        show_all_students();
    }
}

void sort_students_by_cgpa() {
    if (i <= 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        
        for (int j = 0; j < i - 1; j++) {
            for (int k = 0; k < i - j - 1; k++) {
                if (s[k].cgpa > s[k + 1].cgpa) {
                    student temp = s[k];
                    s[k] = s[k + 1];
                    s[k + 1] = temp;
                }
            }
        }
        cout << "\n\n ***Students Sorted by CGPA***";
        show_all_students(); 
    }
}

void search_by_gpa(){
    cout << "\n\n ***Search Students by GPA***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        float gpa;
        bool is_found = false;
        int index = -1;
        cout << "\n\n Enter GPA: ";
        cin >> gpa;
        for (int j = 0; j < i; j++) {
            if (s[j].gpa == gpa) {
                is_found = true;
                index = j;
            }
            
        }
        if(is_found){
            display_student_details(s[index]);
        }
        else{
            cout << "\n\n ***No Record Found***";
        }
    }
}

void search_by_father_name(){
    cout << "\n\n ***Search Students by Father Name***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        string father_name;
        bool is_found = false;
        int index = -1;
        cout << "\n\n Enter Father Name: ";
        cin >> father_name;
        for (int j = 0; j < i; j++) {
            if (s[j].father_name == father_name) {
                is_found = true;
                index = j;
            }   
        }
        if(is_found){
            display_student_details(s[index]);
        }
        else{
            cout << "\n\n ***No Record Found***";
        }
    }
}

void search_by_cgpa(){
    cout << "\n\n ***Search Students by CGPA***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        float cgpa;
        cout << "\n\n Enter CGPA: ";
        cin >> cgpa;
        bool is_found = false;
        int index = -1;
        for (int j = 0; j < i; j++) {
            if (s[j].cgpa == cgpa) {
                is_found = true;
                index = j;
            }
            
        }
        if(is_found){
            display_student_details(s[index]);
        }
        else{
            cout << "\n\n ***No Record Found***";
        }
    }
}   

void search_students_by_name() {
    cout << "\n\n ***Search Students by Name***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        bool is_found = false;
        string name;
        int found_index = -1;
        cout << "\n\n Enter Name: ";
        cin.ignore();
        getline(cin, name);
        for (int j = 0; j < i; j++) {
            if (s[j].name == name) {
                is_found = true;
                found_index = j;
            }

        }
        if(is_found){
            display_student_details(s[found_index]);
    }
    else{
        cout << "\n\n ***No Record Found***";
    }
    }
}

void marks_avg() {
    cout << "\n\n ***Calculate Average Marks***";
    if (i == 0) {
        cout << "\n\n ***No Record Found***";
    } else {
        float total_marks = 0;
        for (int j = 0; j < i; j++) {
            total_marks += s[j].marks;
        }
        cout << "\n\n Average Marks: " << total_marks / i;
    }
}

void menu() {
    cout << "\n\n ***Student Record System***";
    cout << "\n 1. Insert Record";
    cout << "\n 2. Search Record ";
    cout << "\n 3. Update Record";
    cout << "\n 4. Delete Record";
    cout << "\n 5. Show All Students";
    cout << "\n 6. Top Performers";
    cout << "\n 7. sort students by name";
    cout << "\n 8. sort students by cgpa";
    cout << "\n 9. Calculate Average Marks and CGPA";
    cout << "\n 10. Exit";
}

void search_manu(){
    cout << "\n\n ***Search Record***";
    cout << "\n 1. Search Students by ID";
    cout << "\n 2. Search Students by Name";
    cout << "\n 3. Search Students by first Name";
    cout << "\n 4. Search Students by last Name";
    cout << "\n 5. Search Students by GPA";
    cout << "\n 6. Search Students by Father Name";
    cout << "\n 7. Search Students by Grade";
    cout << "\n 8. Search Students by Semester";
    cout << "\n 9. Search Students by CGPA";
    cout << "\n 10. Exit";
}

void search_std(){
    while(true){
    int choice;
    search_manu();
    cout << "\n\n Enter your choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            search_record();
            break;
        case 2:
            search_students_by_name();
            break;
        case 3:
            search_student_by_first_name();
            break;
        case 4:
            search_students_by_last_name();
            break;
        case 5:
            search_by_gpa();
            break;
        case 6: 
            search_by_father_name();
            break;
        case 7:
            find_students_by_grade();
            break;
        case 8:
            display_students_by_semester();
            break;
        case 9:
            search_by_cgpa();
            break;
        case 10:
            return;
            break;
        default:
            cout << "\n\n ***Invalid Choice***";
    }
    }
}

void manu_choice(int a){
    switch(a){
        case 1:
            insert_student();
            break;
        case 2:
            search_std();
            break;
        case 3:
            update_record();
            break;
        case 4:
            delete_record();
            break;
        case 5:
            show_all_students();
            break;
        case 6:
            top_performers();
            break;
        case 7:
            sort_students_by_name();
            break;
        case 8:
            sort_students_by_cgpa();
            break;
        case 9:
            calculate_avg_marks_cgpa();
            break;
        case 10:
            exit(0);
            break;
        default:
            cout << "\n\n ***Invalid Choice***";
    }
}
