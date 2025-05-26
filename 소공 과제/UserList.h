#pragma once
#include <vector>
#include <string>
#include "User.h"

// 시스템의 모든 사용자 정보를 관리 한다
class UserList {
private:
    std::vector<User> users; // 사용자 객체들을 저장하는 벡터

public:
    // 새로운 사용자 목록 객체를 생성하고 관리자 계정을 추가한다
    UserList();
    // 새로운 사용자를 목록에 추가한다
    void addUser(const User& user);
    // 주어진 ID를 가진 사용자를 찾아 포인터를 반환한다 (없으면 nullptr)
    User* findUserById(const std::string& id);
    // 등록된 모든 사용자 목록을 반환한다
    const std::vector<User>& getAllUsers() const;
}; 