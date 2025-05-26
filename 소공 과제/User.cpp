#include "User.h"
#include "Bike.h" 
#include <algorithm> 
#include <iostream> 

// 새로운 사용자 객체를 생성한다
User::User(const std::string& id, const std::string& pw, const std::string& phone, UserType type)
    : id(id), password(pw), phoneNumber(phone), type(type) {
    if (type == UserType::ADMIN) {
        this->password = "admin"; // 관리자 계정 비밀번호는 "admin"으로 고정한다
    }
}

// 사용자 객체소멸자
User::~User() {
}

// 사용자의 ID를 반환한다
std::string User::getId() const {
    return id;
}

// 사용자의 비밀번호를 반환한 다
std::string User::getPassword() const {
    return password;
}

// 사용자의 전화번호를 반환한다
std::string User::getPhoneNumber() const {
    return phoneNumber;
}

// 사용자의 유형을 반환한다
UserType User::getType() const {
    return type;
}

// 사용자의 유형을 설정한다
void User::setType(UserType type) {
    this->type = type;
}

// 사용자가 관리자인지 확인한다
bool User::isAdmin() const { return type == UserType::ADMIN; }

// 사용자가 특정 자전거를 대여한다
bool User::rentBike(Bike* bike) {
    if (bike != nullptr && !bike->isRented()) {
        if (isRenting(bike)) {
            return false; // 이미 이 사용자가 대여한 자전거이다
        }
        rentedBikes.push_back(bike);
        bike->setRentedStatus(true, id); // 자전거에 대여자 정보 및 상태를 설정한다
        return true;
    }
    return false;
}

// 사용자가 대여한 모든자전거의 목록을 반환한다
const std::vector<Bike*>& User::getRentedBikes() const {
    return rentedBikes;
}

// 사용자가 특정 자전거를 현재 대여 중인지 확인한다
bool User::isRenting(Bike* bike) const {
    if (!bike) return false;
    return std::find(rentedBikes.begin(), rentedBikes.end(), bike) != rentedBikes.end();
}

// 사용자가 한 대 이상의 자전거를 대여 중인지 확인한다
bool User::hasRentedBikes() const {
    return !rentedBikes.empty();
}
