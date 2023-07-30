#include <iostream>

struct Student {
    int number;
    char name[100];
    double score;
};

void StudentDate(const Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) 
    {
        std::cout << "��ȣ: " << students[i].number << std::endl;
        std::cout << "�̸�: " << students[i].name << std::endl;
        std::cout << "����: " << students[i].score << std::endl;
    }
}

double TotalScore(const Student students[], int numStudents) {
    double totalScore = 0;
    for (int i = 0; i < numStudents; ++i) {
        totalScore += students[i].score;
    }
    return totalScore;
}

void sortDescending(Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; ++i) {
        for (int j = 0; j < numStudents - i - 1; ++j) {
            if (students[j].score < students[j + 1].score) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numStudents;
    std::cout << "�л� ���� �Է��ϼ��� ";
    std::cin >> numStudents;

    const int maxStudents = 100;
    Student students[maxStudents];

    for (int i = 0; i < numStudents; ++i) {
        Student student;
        std::cout << "��ȣ: ";
        std::cin >> student.number;
        std::cin.ignore(); 

        std::cout << "�̸�: ";
        std::cin.getline(student.name, sizeof(student.name));

        std::cout << "����: ";
        std::cin >> student.score;

        std::cout << "---------------------------" << std::endl;

        students[i] = student;
    }

    int choice;
    std::cout << "�ϳ��� �����ϼ���" << std::endl;
    std::cout << "1. ����Ʈ ���" << std::endl;
    std::cout << "2. ���� ����" << std::endl;
    std::cout << "3. �������� ����" << std::endl;
    std::cin >> choice;

    switch (choice) {
    case 1:
        StudentDate(students, numStudents);
        break;

    case 2:
        std::cout << "���� ������:" << TotalScore(students, numStudents) << std::endl;
        break;

    case 3:
        sortDescending(students, numStudents);
        std::cout << "�������� ����:" << std::endl;
        StudentDate(students, numStudents);
        break;

    default:
        std::cout << "����" << std::endl;
        break;
    }
};