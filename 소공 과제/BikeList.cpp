#include "BikeList.h"

// 새로운 자전거 목록 객체를 생성한다
BikeList::BikeList() {
    // 초기 자전거 데이터 추가가 필요하면 여기에 작성한다
}

// 새로운 자전거를 목록에 추가한다
void BikeList::addBike(const Bike& bike) {
    bikes.push_back(bike);
}

// 주어진 ID를 가진 자전거를 찾아 포인터를 반환한다 (없으면 nullptr)
Bike* BikeList::findBikeById(const std::string& id) {
    for (auto& bike : bikes) {
        if (bike.getId() == id) {
            return &bike;
        }
    }
    return nullptr;
}

// 등록된 모든 자전거 목록을 반환한다
const std::vector<Bike>& BikeList::getAllBikes() const {
    return bikes;
}

