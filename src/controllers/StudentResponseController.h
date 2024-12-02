#ifndef STUDENTRESPONSECONTROLLER_H
#define STUDENTRESPONSECONTROLLER_H

#include<iostream>
#include"../repository/UserRepository.h"
#include"../models/Response.h"
#include"../models/User.h"
using namespace std;

class StudentResponseController {
    private:
        UserRepository userRepository;

    public:
        StudentResponseController () {}

    Response getAllTeacher() {
        Response res;
        vector<User> teachers = userRepository.getAllTeachers();

        if (teachers.empty()) {
            res.setStatus(8); 
            res.setMessage("Khong co giao vien nao trong he thong");
        } else {
            string message = "";
            for (const auto &teacher : teachers) {
                message += "ID: " + to_string(teacher.getId()) + ", ";
                message += "Ho ten: " + teacher.getFirstName() + " " + teacher.getLastName() + ", ";
                message += "Vai tro: " + teacher.getRole() + "|";
            }
            res.setStatus(0); 
            res.setMessage(message);
        }

        return res;
    }

        

};

#endif