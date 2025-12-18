#include <iostream>
#include <string>
#include <vector>
#include "../include/LogManager.h"
#include "../include/NotificationListener.h"
#include "../external/IDevice.h"
#include "../external/DeviceType.h"

// --- MOCK DEVICE (Test Amaçlı Sahte Cihaz) ---
// Diğer modüller hazır olmadığı için IDevice kontratına uyan bir taklitçi yazdık.
class MockDevice : public IDevice {
private:
    std::string name;
    bool power;
public:
    MockDevice(std::string n) : name(n), power(false) {}
    virtual ~MockDevice() {}

    // IDevice zorunlulukları
    std::string getName() { return name; }
    void setName(const std::string& n) { name = n; }
    
    DeviceType getDeviceType() { return Light; }
    void setDeviceType(DeviceType dt) {}

    bool getPowerState() { return power; }
    void setPowerState(bool ps) { power = ps; }

    void poweron() { power = true; }
    void poweroff() { power = false; }
    
    // Geri kalan boş fonksiyonlar (Derleyici hata vermemesi için)
    std::vector<std::string> getConfig() { return std::vector<std::string>(); }
    void setConfig(const std::vector<std::string>& c) {}
    bool getOperationState() { return true; }
    void setOperationState(bool os) {}
    int getIndex() { return 0; }
    void setIndex(int i) {}
    void detect() {}
};

int main() {
    std::cout << "========= MSH MODULE 5: ENTEGRASYON TESTI =========" << std::endl;

    // TEST 1: LogManager Singleton Testi
    std::cout << "\n[ADIM 1] LogManager Singleton Test Ediliyor..." << std::endl;
    LogManager* logger = LogManager::getInstance();
    logger->writeLog("SYSTEM", "Test baslatildi.");
    std::cout << ">> Log dosyasi acildi ve ilk kayıt yazildi." << std::endl;

    // TEST 2: NotificationListener ve Observer Pattern Testi
    std::cout << "\n[ADIM 2] NotificationListener (Observer) Kuruluyor..." << std::endl;
    NotificationListener listener(logger);
    MockDevice testLamp("Salon Lambasi");

    // SENARYO A: LOG_ONLY (Sadece Log)
    std::cout << "\n--- Senaryo A: Sadece Loglama ---" << std::endl;
    listener.setPreference(LOG_ONLY);
    listener.update(&testLamp);
    std::cout << ">> Ekranda bir sey cikmadi (Beklenen), log dosyasina bakin." << std::endl;

    // SENARYO B: SMS_SIMULATION (SMS Simülasyonu)
    std::cout << "\n--- Senaryo B: SMS Bildirimi ---" << std::endl;
    listener.setPreference(SMS_SIMULATION);
    listener.update(&testLamp);

    // SENARYO C: ALARM_SOUND (Alarm Simülasyonu)
    std::cout << "\n--- Senaryo C: Sesli Alarm ---" << std::endl;
    listener.setPreference(ALARM_SOUND);
    MockDevice smokeDetector("Mutfak Duman Sensoru");
    listener.update(&smokeDetector);

    // TEST 3: Dosya Kapatma
    std::cout << "\n[ADIM 3] Sistem Kapatiliyor..." << std::endl;
    logger->close();

    std::cout << "\n========= TEST BASARIYLA TAMAMLANDI =========" << std::endl;
    std::cout << "Tum adimlar msh_log.txt dosyasina kaydedildi." << std::endl;

    return 0;
}