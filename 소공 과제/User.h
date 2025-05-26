#pragma once
#include <string>
#include <vector>
#include "Bike.h" // Bike 클래스 사용을 위해 포함 (전방선언 대신)

 // class Bike; // Bike.h를 직접 포함하므로 전방선언 불필요

// 사용자 유형을 정의한다
enum class UserType {
    GENERAL,    // 일반 회원
    ADMIN       // 관리자
};

// 사용자 정보를 관리하는 entity 클래스
class User {
private:
    std::string id;                 // 사용자 ID
    std::string password;           // 사용자 비밀번호
    std::string phoneNumber;        // 사용자 전화번호
    UserType type;                  // 사용자 유형 (일반/관리자)
    std::vector<Bike*> rentedBikes; // 사용자가 대여한 자전거 목록

public:
    // 새로운 사용자 객체를 생성한다
    User(const std::string& id, const std::string& pw, const std::string& phone, UserType type = UserType::GENERAL);
    // 사용자 객체 소멸자
    ~User();
    // 사용자의 ID를 반환한다
    std::string getId() const;
    // 사용자의 비밀번호를 반환한 다
    std::string getPassword() const;
    // 사용자의 전화번호를 반환한다
    std::string getPhoneNumber() const;
    // 사용자의 유형을 반환한다
    UserType getType() const;
    // 사용자의 유형을 설정한다
    void setType(UserType type);
    // 사용자가 관리자인지 확인한다
    bool isAdmin() const;

    // 사용자가 특정 자전거를 대여한다
    bool rentBike(Bike* bike);
    // 사용자가 대여한 모든자전거의 목록을 반환한다
    const std::vector<Bike*>& getRentedBikes() const;
    // 사용자가 특정 자전거를 현재 대여 중인지 확인한다
    bool isRenting(Bike* bike) const;
    // 사용자가 한 대 이상의 자전거를 대여 중인지 확인한다
    bool hasRentedBikes() const;
}; 