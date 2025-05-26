#pragma once
#include <string>

// 자전거의 정보 및 상태를 관리하는 entity 클래스
class Bike {
private:
    std::string id;             // 자전거 고유 ID
    std::string model;          // 자전거 모델명
    bool rented;                // 대여 상태 (true: 대여됨, false: 대여 가능)
    std::string rentedByUserId; // 대여한 사용자의 ID (대여되지 않았으면 비어 있음)

public:
    // 새로운 자전거 객체를 생성한다
    Bike(const std::string& id, const std::string& model);

    // 자전거의 ID를 반환한다
    std::string getId() const;

    // 자전거의 모델명을 반환한다
    std::string getModel() const;

    // 자전거의 대여 상태를 반환한 다
    bool isRented() const;

    // 자전거를 대여한 사용자의 ID를 반환한다
    std::string getRentedByUserId() const;

    // 자전거의 대여 상태와 대여 사용자 ID를 설정한다
    void setRentedStatus(bool status, const std::string& userId);
}; 