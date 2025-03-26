#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEAdvertising.h>

// Function Declaration
void setup_ble(void);

// Create Data
struct IMUData{
  float accelX;
  float accelY;
  float accelZ;
  float gyroX;
  float gyroY;
  float gyroZ;
};

void setup(void) {
  // Begin Serial
  Serial.begin(115200);

  // M5Unified configuration
  auto cfg = M5.config();
  cfg.internal_imu = true;  // Enable internal IMU
  M5.begin(cfg);

  // Setup BLE
  setup_ble();
}
 
void loop(void) {
  Serial.println("Hello World\n");
  delay(100);
}

// Function to Setup BLE
void setup_ble(void) {
  BLEDevice::init("M5Capsule");
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
}


