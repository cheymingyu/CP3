#pragma once
#include "AppController.h"
#include "Ban.h"
#include "AppView.h"
#include "GradeCounter.h"
#include "Student.h"

struct _AppController {
	Ban* _ban;
};

#define MAX_NUMBER_OF_STUDENTS	100
#define MAX_STUDENT_ID_LENGTH 9

AppController* AppController_new(void) {
	AppController* _this = NewObject(AppController);
	_this->_ban = Ban_newWithCapacity(MAX_NUMBER_OF_STUDENTS);
	return _this;
}

void AppController_delete(AppController* _this) {
	Ban_delete(_this->_ban);
	free(_this);
}

void AppController_run(AppController* _this) {
	AppView_out("<<< ���� ó���� �����մϴ� >>>\n");

	// (1) ������ �Է� �޴´�
	Boolean inputAndStoreWasSuccessful;
	inputAndStoreWasSuccessful = AppController_inputAndStoreStudents(_this);

	if (inputAndStoreWasSuccessful) {
		if (Ban_isEmpty(_this->_ban)) {
			AppView_out("[����] �л� ������ ���� �Էµ��� �ʾҽ��ϴ�.\n");
		}
		else {
			// (2) ��հ� ��� �̻��� �л� ��, �ְ���, �������� ����Ѵ�.
			AppController_showStatistics(_this);

			// (3) ���������� ����, �׸��� ���ĵ� �л� ������ ����Ѵ�.
			Ban_sortStudentByScore(_this->_ban);
			AppController_showStudentsSortedByScore(_this);
		}
	}
	else {
		AppView_out("[����] ������ ���������� ������� �ʾҽ��ϴ�.");
	}
	AppView_out("\n<<< ���� ó���� �����մϴ� >>>\n");
}

Boolean AppController_inputIsValid(AppController* _this, char* aStudentID, int aScore) {
	Boolean inputIsValid = TRUE;
	if (!Student_studentIDIsValid(aStudentID)) {
		AppView_out_msg_invalidStudentID(aStudentID, MAX_STUDENT_ID_LENGTH);
		inputIsValid = FALSE;
	}
	if (!Student_scoreIsValid(aScore)) {
		AppView_out("[����] 0���� �۰ų� 100���� Ŀ��, �������� ������ �ƴմϴ�.\n");
		inputIsValid = FALSE;
	}
	return inputIsValid;
}

Boolean	AppController_inputAndStoreStudents(AppController* _this) {
	int		 score;
	Boolean  storingAStudentWasSuccessful = TRUE;
	char	 studentID[100];
	Student* student;

	while (storingAStudentWasSuccessful && AppView_in_doesContinueToInputNextStudent()) {
		Appview_in_studentID(studentID);
		score = AppView_in_score();
		if (AppController_inputIsValid(_this, studentID, score)) {
			student = Student_new(studentID, score);
			storingAStudentWasSuccessful = Ban_add(_this->_ban, student);
		}
	}
	AppView_out("�Է��� �����մϴ�.\n\n");
	return storingAStudentWasSuccessful;
}

void AppController_showStatistics(AppController* _this) {
	// �� ������ ���� ó���� ����� Ban ��ü�� ������ �ִ�
	AppView_out_averageScore(Ban_averageScore(_this->_ban));
	AppView_out_numberOfStudentsAboveAverage(Ban_numberOfStudentsAboveAverage(_this->_ban));
	AppView_out_maxScore(Ban_maxScore(_this->_ban));
	AppView_out_minScore(Ban_minScore(_this->_ban));
	AppView_out("\n");

	// ���� �� �л����� Ban ��ü�κ��� GradeCounter ��ü ���·� ��´�.
	GradeCounter* gradeCounter = Ban_countGrades(_this->_ban);
	AppView_out_gradeCountFor('A', GradeCounter_numberOfA(gradeCounter));
	AppView_out_gradeCountFor('B', GradeCounter_numberOfB(gradeCounter));
	AppView_out_gradeCountFor('C', GradeCounter_numberOfC(gradeCounter));
	AppView_out_gradeCountFor('D', GradeCounter_numberOfD(gradeCounter));
	AppView_out_gradeCountFor('F', GradeCounter_numberOfF(gradeCounter));
	AppView_out("\n");
	GradeCounter_delete(gradeCounter);
}

void AppController_showStudentsSortedByScore(AppController* _this) {
	Student* student;
	AppView_out_titleForSortedStudentList();
	for (int i = 0; i < Ban_size(_this->_ban); i++) {
		student = Ban_elementAt(_this->_ban, i);
		int score = Student_score(student);
		AppView_out_studentInfo(
			Student_studentID(student),
			score,
			Ban_scoreToGrade(score)
		);
	}
}