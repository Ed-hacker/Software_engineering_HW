#include "Bike.h"

// 새로운 자전거 객체를 생성한다
Bike::Bike(const std::string& id, const std::string& model)
    : id(id), model(model), rented(false), rentedByUserId("") {}

// 자전거의 ID를 반환한다
std::string Bike::getId() const {
    return id;
}

// 자전거의 모델명을 반환한다
std::string Bike::getModel() const {
    return model;
}

// 자전거의 대여 상태를 반환한다
bool Bike::isRented() const {
    return rented;
}

// 자전거를 대여한 사용자의 ID를 반환한다
std::string Bike::getRentedByUserId() const {
    return rentedByUserId;
}

// 자전거의 대여 상태와 대여 사용자 ID를 설정한다
void Bike::setRentedStatus(bool status, const std::string& userId) {
    this->rented = status;
    this->rentedByUserId = userId;
} 