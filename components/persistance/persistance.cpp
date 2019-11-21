#include "persistance.h"
#include <string>
#include "nvs_flash.h"
#include "nvs.h"

void Persistance::SaveString(std::string key, std::string value)
{

}
std::string Persistance::GetString(std::string key)
{
    size_t required_size;
    esp_err_t err= nvs_get_str(handle, key.c_str(), NULL, &required_size);
    std::string s;
    if (err != ESP_OK) return s;

    char* value = (char*)malloc(required_size);
    nvs_get_str(handle, key.c_str(), value, &required_size);

    std::string svalue(value);
    free(value);

    return svalue;

}

Persistance::Persistance()
{
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }

    ESP_ERROR_CHECK( err );

    nvs_open("STORAGE", NVS_READWRITE, &handle);
}